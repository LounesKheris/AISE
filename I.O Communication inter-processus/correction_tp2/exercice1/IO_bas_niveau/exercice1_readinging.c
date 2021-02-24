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
	
	
	/***************
	reading the file
	***************/
	
	int fd = open("./part.dat", O_RDONLY, 0600);
	
	if(fd < 0)
		perror("open"), 1;
	
	/*********
	READ2 DATA
	**********/
	
	size_t to_read = sizeof(struct particle) * NUM_PART;
	size_t reading = 0;
	
	while(to_read != reading){
	
		int ret = read(fd, part + reading, to_read - reading);
		
		if(ret < 0){
			if(errno = EINTR)
				continue;
		
			perror("read"), 1;
		}
		
		reading += ret; 		
	} 
	
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
	
	
	close(fd);
	free(part);
	
	return 0;
} 
