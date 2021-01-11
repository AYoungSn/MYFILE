#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char* filename="test.txt";
	if(access(filename, R_OK)==-1){
		printf("not read");
		perror(filename);
		exit(-1);
	}
	else if(access(filename, F_OK)==-1){
		printf("not exist");
		perror(filename);
		exit(-1);
	}
	else
		printf("%s is readable\n", filename);

}
