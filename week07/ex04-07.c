#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
	if(link(argv[1], argv[2])<0){
		perror(argv[1]);
		exit(-1);
	}
}
