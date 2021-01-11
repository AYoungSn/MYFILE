#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	struct stat a;
	char *s;

	if(argc<2){
		fprintf(stderr, "usage: %s file\n",argv[0]);
		exit(-1);
	}
	stat(argv[1],&a);
	s=ctime(&a.st_mtime);
	printf("%s, %s\n",argv[1], s);

	time_t curTime=time(0);
	s=ctime(&curTime);
	printf("%s", s);
}
