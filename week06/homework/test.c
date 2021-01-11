#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp1, *fp2;
	char c;

	fp1=fopen("a","r");
	fp2=fopen("b","w");

	if(fp2==NULL){
		perror("b");
		exit(-1);
	}
	if(fp1==NULL){
		perror("a");
		exit(-1);
	}
	while((c=fgetc(fp1))!=EOF)
	       printf("%c",fputc(c,fp2));

	fclose(fp1);
	fclose(fp2);
}
