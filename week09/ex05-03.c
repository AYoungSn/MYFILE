#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	DIR* dirp;
	if((dirp=opendir("test_dir1"))==NULL){
		perror("test_dir1");
		exit(1);
	}
	closedir(dirp);
}
