#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	int fd;
	off_t newpos;
	char pathname[100];
	scanf("%s", pathname);
	fd=open(pathname,O_RDONLY);
	if(fd==-1){
		perror(pathname);
		exit(-1);
	}
	/* 읽기 포인터를 EOF로 이동한다 */
	newpos=lseek(fd, 0, SEEK_END);
	/* 파일 사이즈 구하기 */
	printf("file size: %d\n",(int)newpos);
	close(fd);
	return 0;
}
