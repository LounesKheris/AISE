/*******************************************************************************
la fractale de Mandelbrot est souvent utilisée pour évaluer 
l'éfficacité du partage des tahes.
La construction de la fractale est basée sur un calcul recursif. 
Ce calcul est plus long pour les points qui sont siués dans la partie
centrale de l'image. Le découpage des taches est donc promordial si l'on veut
profiter de toute la puissance de calcul d'un systéme multiprocesseur.

-------------------------------------	le programme   ------------------------------

utiliser la bib 'gd' pour stocker l'image resultat.
installation 'libgs2-xpm-dev' pour la compilation.
cette bib permet de créer des image et de manipuler des pixels.

-------------------------------------	Compilation	-----------------------------
gcc -Wall -lgd -lpng -fopenmp -oMandelbrot Mandelbrot.c


********************************************************************************/

#include"gd.h"
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<sys/time.h>

typedef struct{
	double r,i;
} complex;

//variables global pour simplifier le pg
	gdImagePtr image;
	int largeur, hauteur;
	int noir;
	int *couleurs;
	
	double get_time(){
		struct timeval tv;
		gettimeofday(&tv, (void *)0);
		return (double) tv.tv_sec + tv.tv_usec*1e-6;
	}
	
	double fractale(double centre_x, double centre_y, double zoom, int nb_threads){
		
		double start, stop;
		double cpu_time_used;
		complex origin, z, c, nouveau;
		double distance;
		int x, y;
		int couleur, exit;
		
		start = get_time();
		origin.r = centre_x;
		origin.i = centre_y;
		#pragma omp parallel for num_threads(nb_threads) private(c,z,couleur,exit,nouveau, distance,x,y)
		for(y = 1; y < hauteur; y++){
			for(x = 1; x < largeur; x++){
				//calcul le nombre complexe situé en (x,y)
				c.r = (	origin.r +( (double) (x-(largeur/2)) / (double) largeur)) / zoom;
				c.i = (	origin.i +( (double) (y-(largeur/2)) / (double) hauteur)) / zoom;
				z.r = z.i = 0.0; // point de départ
				couleur =0;
				exit = 0;
				while((couleur < 256) && (exit == 0)){
					nouveau.r = z.r *z.r - z.i*z.i +c.r;
					nouveau.i = 2*z.r*z.i+c.i;
					z.r = nouveau.r;
					z.i = nouveau.i;
					distance = nouveau.r*nouveau.r + nouveau.i*nouveau.i;
					couleur++;
					if(distance > 4){
						exit = 1;
					}
				}
			//MAJ de la couleur
			if(couleur <=256){
				gdImageSetPixel(image, x,y,couleurs[couleur]);
				
			}else{
				gdImageSetPixel(image, x,y, noir);
			}
		}
	}	
	stop = get_time();
	cpu_time_used = stop-start;
	return cpu_time_used;	
}

int main(int argc, char **argv){
	char nom_fichier[50];
	FILE *fichier;
	int n,nb;
	double t=0.0;
	double T0=0.0;
	double eff=0.0;

	printf("Nb.threads\tEff.\tSpeed.\tTps.\n");
	
	//taille de l'image
	image = gdImageCreate(largeur, hauteur);
	noir = gdImageColorAllocate(image,0,0,0);
	//creation et allocation du tableau de couleure
	couleurs = (int*) malloc(256*sizeof(int));
	for(n=0;n<42;n++){
	couleurs[n] = gdImageColorAllocate(image, 255, n * 6, 0);
	couleurs[n + 42] = gdImageColorAllocate(image, (255 - n * 6), 255, 0);
	couleurs[n + 84] = gdImageColorAllocate(image, 0, 255, n * 6);
	couleurs[n + 126] = gdImageColorAllocate(image, 0, (255 - n * 6), 255);
	couleurs[n + 168] = gdImageColorAllocate(image, n * 6, 0, 255);
	couleurs[n + 210] = gdImageColorAllocate(image, 255, 0, (255 - n * 6));
	}	
	
	for(nb=1;nb<=12;nb++){
		t = fractale(-0.1,0,0.4,nb);
		if(nb==1){
			T0 = t;
		}
		
		eff = T0/(nb*t);
		printf("%d\t%f\t%f\t%f\n", nb,eff,(T0/t),t);
	}
  // Ouverture du fichier
	sprintf(nom_fichier,"Mandelbrot_%d.png",largeur);
	fichier = fopen(nom_fichier, "w");

  // Ecriture de l'image
	gdImagePng(image, fichier);

  // Fermeture du fichier
  	fclose(fichier);

  // Destruction de l'image
	gdImageDestroy(image);

  // Destruction du tableau de couleurs
	free(couleurs);

  return(EXIT_SUCCESS);
}
