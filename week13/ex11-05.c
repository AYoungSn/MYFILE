#include <unistd.h>
#include <stdio.h>

#define SIZE 512

int main(){
	char* msg1="apple is red";
	char* msg2="banana is yellow";
	int fd[2], len1,len2;
	pid_t pid;

	pipe(fd);

	if((pid=fork())>0){
		close(fd[0]);
		len1=strlen(msg1)+1;
		len2=strlen(msg2)+1;
		write(fd[1],&len1, sizeof(int));
		write(fd[1],msg1,len1);
		write(fd[1],&len2, sizeof(int));
		write(fd[1],msg2, len2);
	}
	else{
		char buffer[SIZE];
		int nread,len;
		close(fd[1]);

		read(fd[0],&len,sizeof(int));
		nread=read(fd[0],buffer, len);
		printf("%d, %s\n", nread, buffer);
		read(fd[0], &len, sizeof(int));
		nread=read(fd[0],buffer,len);
		printf("%d, %s\n",nread, buffer);
	}
}
