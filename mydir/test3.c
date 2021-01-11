#include <stdio.h>
int main(){
	char c;
	FILE *fp=fopen("data.txt","r");

	while((c=fgetc(fp))!=EOF)
		fputc(c,stdout);
}
