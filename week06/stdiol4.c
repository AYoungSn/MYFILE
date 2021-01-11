#include <stdio.h>

int main(){
	char c;
	FILE *fpin, *fpout;

	if((fpin=fopen("a","r"))==NULL){
		perror("a");
		exit(-1);
	}
	if((fpout=fopen("b","w"))==NULL){
		perror("b");
		exit(-1);
	}
	while((c=fgetc(fpin))!=EOF){
		fputc(c, fpout);
	}
	fclose(fpin);
	fclose(fpout);
}
