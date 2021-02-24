#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_PART 64

struct particle{

    int x, y, z;

};

int main(int argc, char ** argv){

    struct particle *part = malloc(NUM_PART* sizeof(struct particle));

    if(!part)
        perror("malloc"), 1;

    FILE * fd = fopen("./part.data", "r");

    if(!fd)
        perror("fopen"), 1;

    int reading = fread( part, sizeof(struct particle), NUM_PART, fd);

    if(reading < 0)
        perror("fread"), 1;

    for(int i= 0; i < NUM_PART; i++){
		if(part[i].x != i){
			fprintf(stderr, "ERROR on x %d != %d", part[i].x, i);
		}
		if(part[i].y != i+1){
			fprintf(stderr, "ERROR on y %d != %d", part[i].y, i+1);
		}
		if(part[i].z != i+2){
			fprintf(stderr, "ERROR on z %d != %d", part[i].z, i+2);
		}
	}

     printf("SUCCESS\n");

    fclose(fd);
    free(part);
    return 0;
}