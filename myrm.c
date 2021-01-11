#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	if(argc==1){
		fprintf(stderr, "usage: myrm files...\n");
		exit(-1);
	}
	while(--argc>0)
		unlink(*++argv);

	return 0;
}	
