#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc<3){
		fprintf(stderr, "usage: link {-s} file1 file2\n");
		exit(-1);
	}
	if(strcmp(argv[1],"-s")==0&&argc==4){
		if(symlink(argv[2], argv[3])==-1){
			perror(argv[2]);
			exit(-1);
		}
	}
	else{
		if(link(argv[1],argv[2])==-1){
			perror(argv[1]);
			exit(-1);
		}
	}
	return 0;
}
