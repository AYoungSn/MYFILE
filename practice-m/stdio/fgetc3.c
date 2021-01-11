#include <stdio.h>
#include <unistd.h>
int main(){
	char c;
	FILE *fpin, *fpout;

	fpin = fopen("data.txt", "r");
	fpout = fopen("result.txt", "w");

	while((c=fgetc(fpin))!=EOF)
		fputc(c,fpout);
	sleep(5);
	fclose(fpin);
	fclose(fpout);
}
