#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd1, fd2;
	fd1=open("temp1.txt",O_RDONLY);
	fd2=open("temp2.txt",O_RDONLY|O_CREAT);

	printf("%d %d\n",fd1, fd2);
	close(fd1);
	close(fd2);
}


