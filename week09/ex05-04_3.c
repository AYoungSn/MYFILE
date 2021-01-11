#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	DIR *dirp;
	struct dirent* dentry;

	if((dirp=opendir("."))==NULL) exit(1);

	while((dentry=readdir(dirp))!=NULL)
		printf("%s\n",dentry->d_name);

	closedir(dirp);
}
