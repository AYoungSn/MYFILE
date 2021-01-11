#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd = open("out",O_RDONLY);
	off_t newpos;

	newpos=lseek(fd, 0, SEEK_END);
	printf("file size: %ld\n", newpos);
	close(fd);
}
