#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	int fd;

	close(STDIN_FILENO);

	if((fd=open("data.txt",O_RDONLY))<0){
		perror("data.txt");
		exit(-1);
	}
	//close(STDIN_FILENO);
	//dup(fd);
	//close(fd);
	printf("%d\n",fd);
	if((fd=open("data2.txt",O_WRONLY|O_CREAT|O_EXCL, 0600))<0){
		perror("data2.txt");
		exit(-1);
	}
	close(STDOUT_FILENO);
	dup(fd);
	printf("%d",fd);
	close(fd);
	execl("/bin/cat","cat",NULL);
	fprintf(stderr, "execution failure...\n");
}
