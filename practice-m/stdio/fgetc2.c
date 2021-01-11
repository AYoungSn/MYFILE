#include <stdio.h>
#include <unistd.h>
int main(){
	char c;
	FILE* fp=fopen("data.txt","r");

	while((c=fgetc(fp))!=EOF){
		fputc(c,stdout);
		printf("%d %c\n",c,c);
	}
	sleep(10);
}
