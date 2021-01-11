#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;

	if((fp=fopen("data.txt","r"))==NULL){
		perror("data.txt");
		exit(-1);
	}
	fclose(fp);
	return 0;
}
