#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	DIR *dirp;
	struct dirent* dentry;

	chdir("..");
	char buf[256];
	getcwd(buf, sizeof(buf));
	printf("%s\n",buf);
	if((dirp=opendir("."))==NULL)exit(1);

	while((dentry=readdir(dirp))!=NULL){
		printf("%s\n",dentry->d_name);
	}
	closedir(dirp);
}
