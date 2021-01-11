#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int sum=0;
	if(argc ==1){
		fprintf(stderr, "usage: mycalc numbers...\n");
		exit(-1);
	}
	while(--argc>0) sum+=atoi(*++argv);
	printf("%d\n",sum);
	return 0;
}
