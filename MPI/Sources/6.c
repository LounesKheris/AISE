#define BUFFSIZE 100000

int sz;
char *buf;


MPI_Buffer_attach(malloc(BUFFSIZE), BUFFSIZE);
....

MPI_Bsend(msg1,...);
MPI_Bsend(msg2,...);

....
MPI_Buffer_detach(&buf, &sz);
free(buf);
