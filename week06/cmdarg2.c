#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc!=3){
		fprintf(stderr, "usage: %s n1 n2\n",argv[0]);
		exit(-1);
	}
	printf("%d + %d = %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[1])+atoi(argv[2]));
	return 0;
}
