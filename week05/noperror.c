#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
	int fd;
	if((fd=open("data.txt",O_RDONLY))<0){
		if(errno==ENOENT){
			fprintf(stderr, "data.txt: 파일이 없네요...\n");
			exit(-1);
		}
		else if(errno==EACCES){
			fprintf(stderr, "data.txt: 파일을 읽을수가 없네요...\n");
			exit(-1);
		}
	}
	return 0;
}
