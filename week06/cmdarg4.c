#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void dumpFile(char* file);

int main(int argc, char *argv[]){
	while(--argc>0) dumpFile(*++argv);
	return 0;
}
void dumpFile(char *file){
	char buffer[1024];
	int fd=open(file, O_RDONLY),nread;
	while((nread=read(fd, buffer, 1024))>0)
		write(STDOUT_FILENO, buffer, nread);

	close(fd);
}
