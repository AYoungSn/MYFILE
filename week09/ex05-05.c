#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
	DIR *dirp;
	struct dirent* dentry;
	if((dirp=opendir("."))==NULL) exit(1);

	while(dentry=readdir(dirp))
		printf("%s\n",dentry->d_name);

	rewinddir(dirp);

	while(dentry=readdir(dirp))
		printf("%s\n",dentry->d_name);
	closedir(dirp);
}
