#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char c;

	fp=fopen("data.txt","r");
	while((c=fgetc(fp))!=EOF)
		fputc(c,stdout);
	
	fclose(fp);
	return 0;
}
