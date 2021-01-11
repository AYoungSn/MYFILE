#include <stdio.h>
int main(){
	char c;
	while((c=fgetc(stdin))!=EOF)
		fputc(c,stdout);

	printf("%5d\n",123);
	printf("%d\n",123);
	printf("%-5d\n",123);
	printf("%05d\n",123);
}
