INCLUDES LIBRARIES IN C

lib.h : includes
lib.c : source
main.c: exec


Makefile :

-shared : pour créer la bib
-fpic : c'est pour faire du code position indépendant(position independante code), c'est à dire c'est un code qui peut étre relocationné puisqu'une librairie partagée est projetée en mémoire en différents endroits.
$^: tout ce qui est à droite de :
$@ : cible, càd à gauche de :
-lfoo : c'est équivalent à -libfoo


**-** Compialtion **-**
$> make

$./test
	./test : error while loading shared ....

$> ldd ./test
libfoo.so => not found

\___________________________________________________________/
/Warning : dépend d'un libfoo mais ne sait pas où le trouver\
\-----------------------------------------------------------/

==> On doit lui spécifier le chemin, pas dans le PATH mais dans LIBRARY_PATH

$> export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$> echo $LD_LIBRARY_PATH

//affiche le chemin de la librairie

--Rajouter le binaire dans le chemin de recherche
$> export PATH=$PWD:$PATH

$> mv test mytest

//execution//
$> mytest

<-------------------------------------------------------------------------->
//VIRER LA VAR LIBRARY_PATH
$>unset LD_LIBRARY_PATH

$> ldd ./mytest
libfoo.so => not found

***--*** Y a un autre moyen de lui le chemin ***--***
C'est lors de la compilation avec un flag de linkeur



-wl.-rpath=$(PATH)   dans le Makefile
---
|-> veut dire qu'on passe un argument au linkeur, et lui dit sauvegarde dans le binaire le chemin vers la librairie et c'est le repertoire courant

<---------------------------------------------------------------->

LD_DEBUG :

on enleve .Wl,-rpath=$(PWD)

$> make
$> ldd ./test
libfoo.so : not found
$> LD_DEBUG=all ./test
.
.
.
.
.
.
//**//voir pourquoi il a planté, il montre ce qu'il est enrain de faire le loadeur, et le loadeur montre que :
file=libfoo.so [0]: needed by ./test [0]
{
test a besoin de libfoo.so
puis il va parcourir tous les chemin standards et il ajoute bétement libfoo derriere
puis soit il le trouve sinon il dit qu'il n'a rien trouvé

DANS NOTRE CAS IL NE L'A PAS TROUVÉ

PUIS :
------
si on ajoute le LD_LIBRARY_PATH

$> export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$> LD_DEBUG=libs ./test

là, il donne tous les chemin