#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char *filename="test.txt";
	if(access(filename,R_OK)==-1){
		perror(filename);
		exit(-1);
	}else printf("%s is readable\n",filename);
	return 0;
}
