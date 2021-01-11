#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char* argv[]){
	struct stat finfo;
	char *file=argv[1];

	if(stat(file, &finfo)==-1){
		perror(file);
		exit(-1);
	}
	printf("%s\n",file);
	printf("major number: %d\n", major(finfo.st_dev));
	printf("minor number: %d\n", minor(finfo.st_dev));
	printf("Inode number: %ld\n", finfo.st_ino);
	printf("File mode: %o\n", finfo.st_mode);
	printf("Num of links: %ld\n",finfo.st_nlink);
	printf("User ID: %d\n",finfo.st_uid);
	printf("Group ID: %d\n",finfo.st_gid);
	printf("Files size: %ld\n",finfo.st_size);
	printf("Last access time: %lu\n",finfo.st_atime);
	printf("Last modify time: %lu\n",finfo.st_mtime);
	printf("Last stat change: %lu\n", finfo.st_ctime);
}
