#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	printf("%o\n",umask(077));
	int fd=open("temp2.txt",O_WRONLY|O_CREAT,0644);
	close(fd);
	printf("%04o\n",umask(0022));
}
