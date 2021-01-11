#include "mystdio.h"
#include <stdio.h>
int main(int argc, char* argv[]){
	char c;
	MYFILE *fpin, *fpout;

	if(argc<3){
		fprintf(stderr, "usage: mycp file1 file2\n");
		exit(-1);
	}
	if((fpin=myfopen(argv[1],"r"))==NULL){
		perror(argv[1]);
		exit(-1);
	}
	if((fpout=myfopen(argv[2],"w"))==NULL){
		perror(argv[2]);
		exit(-1);
	}
	while((c=myfgetc(fpin))!=EOF)
		myfputc(c,fpout);

	myfclose(fpin);
	myfclose(fpout);
}
