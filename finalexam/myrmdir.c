#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void removeDirectory(char *dir){
	DIR* dp;
	struct dirent* entp;
	struct stat buf;
	if((dp=opendir(dir))==NULL){
		perror(dir);
		exit(-1);
	}
	chdir(dir);
	while((entp=readdir(dp))!=NULL){
		if(strcmp(entp->d_name,".")==0) continue;
		else if(strcmp(entp->d_name,"..")==0) continue;
		stat(entp->d_name, &buf);
		if(S_ISDIR(buf.st_mode))
			removeDirectory(entp->d_name);
		else unlink(entp->d_name);
	}
	chdir("..");
	closedir(dp);
	rmdir(dir);
}
int main(int argc, char* argv[]){
	struct stat buf;

	if(argc<2){
		fprintf(stderr, "usage: %s dir\n",argv[0]);
		exit(-1);
	}

	if(stat(argv[1],&buf)<0){
		perror(argv[1]);
		exit(-1);
	}

	if(S_ISDIR(buf.st_mode))
		removeDirectory(argv[1]);
	else fprintf(stderr, "%s is not a directory\n",argv[1]);

}
