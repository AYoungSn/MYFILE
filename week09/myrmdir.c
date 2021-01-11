#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
void removeDirectory(char* dirname){
	DIR *dp;
	struct dirent* entp;
	struct stat buf;

	if((dp=opendir(dirname))==NULL){
		perror(dirname);
		exit(-1);
	}
	chdir(dirname);
	while((entp=readdir(dp))!=NULL){
		if(strcmp(entp->d_name, ".")==0)continue;
		else if(strcmp(entp->d_name,"..")==0) continue;
		stat(entp->d_name, &buf);
		if(S_ISDIR(buf.st_mode))
			removeDirectory(entp->d_name);
		else unlink(entp->d_name);
	}
	closedir(dp);
	chdir("..");
	rmdir(dirname);
}

int main(int argc, char* argv[]){
	struct stat buf;
	if(argc<2){
		fprintf(stderr, "usage: %s dir\n",argv[0]);
		exit(-1);
	}
	if(stat(argv[1], &buf)<0){
		perror(argv[1]);
		exit(-1);
	}

	if(S_ISDIR(buf.st_mode))
		removeDirectory(argv[1]);
	else{
		fprintf(stderr, "%s is not a directory\n",argv[1]);
	}
}
