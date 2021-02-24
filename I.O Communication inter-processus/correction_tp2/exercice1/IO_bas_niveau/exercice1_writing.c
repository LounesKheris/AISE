#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define NUM_PART 64

struct particle{
	int x, y, z;
};

int main(int argc, char ** argv){
	
	/*struct particle part[NUM_PART]
		allouée sur la pile, si NUM_PART = 128000 par exemple 
		on péte notre pile :3 
	*/
	struct particle *part = malloc(NUM_PART * sizeof(struct particle));
	/*alouée dans le tas, on peut utiliser toute la mémoire de la machine */
	if(!part)
		perror("malloc"), 1;
	
	for(int i = 0; i < NUM_PART; i++){
		part[i].x = i;
		part[i].y = i+1;
		part[i].z = i+2;			
	}
	/***************
	writing the file
	***************/
	
	int fd = open("./part.dat", O_CREAT | O_WRONLY, 0600);
	
	if(fd < 0)
		perror("open"), 1;
	
	/*********
	WRITE DATA
	**********/
	
	size_t to_write = sizeof(struct particle) * NUM_PART;
	size_t written = 0;
	
	while(to_write != written){
	
		int ret = write(fd, part + written, to_write - written);
		
		if(ret < 0){
			if(errno = EINTR)
				continue;
		
			perror("write"), 1;
		}
		
		written += ret; 		
	
		
		
	
	} 
	
	
	
	close(fd);
	free(part);
	
	return 0;
} 
