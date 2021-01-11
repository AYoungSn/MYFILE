#include <stdio.h>

int main(){
	FILE* fp=fopen("a","r");
	char c=fgetc(fp);
	int i=c;
	printf("%d, %c\n",i, c);
	fputc(c,stdout);
	c=fgetc(fp);
	i=c;
	printf("\n%d, %c\n",i, c);
}
