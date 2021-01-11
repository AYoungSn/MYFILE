#include <stdio.h>
int main(){
	char c;
	FILE *fp1, *fp2;
	fp1=fopen("a","r");
	fp2=fopen("b","w");
	while((c=fgetc(fp1))!=EOF) fputc(c,fp2);
}
