#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	//struct stat *finfo; -> stat(file, &finfo)-> **finfo 포인터의 포인터가 됨
	struct stat finfo;
	char* file=argv[1];
	if(stat(file, &finfo)==-1){
		perror(file);
		exit(1);
	}
	fprintf(stderr, "Hello!!\n");

//	if(S_ISREG(finfo.st_mode))
//		printf("%s is a regular file.\n",file);
	if(S_ISDIR(finfo.st_mode))
		printf("%s is a directory.\n",file);
	if(S_ISCHR(finfo.st_mode))
		printf("%s is a char special file.\n",file);
	if(S_ISBLK(finfo.st_mode))
		printf("%s is a block special file.\n",file);
	if(S_ISLNK(finfo.st_mode))
		printf("%s is a symbolic link.\n",file);
	if(S_ISFIFO(finfo.st_mode))
		printf("%s is a fifo.\n",file);
	return 0;
}
