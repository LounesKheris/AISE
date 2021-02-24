#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NUM_PART 64 

struct particle {

    int x, y, z;

};

int main(int argc, char ** argv){

    struct particle *part = malloc(NUM_PART * sizeof(struct particle));

    for(int i = 0; i < NUM_PART; i++){
        part[i].x = i;
        part[i].y = i+1;
        part[i].z = i+2;

    }


    FILE *fd = fopen("./part.data","a");

    if(!fd)
        perror("fopen"), 1;

    int written = fwrite( part, sizeof(struct particle), NUM_PART, fd); 

    if(written < 0)
        perror("fwrite"), 1;


    printf("SUCCESS\n");

    fclose(fd);
    free(part);
    return 0;
}