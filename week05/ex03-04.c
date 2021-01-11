#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int fdin, fdout;
	ssize_t nread;
	char buffer[1024];
	char file1[100],file2[100];

	printf("Enter source file: ");
	scanf("%s", file1);

	printf("Enter target file: ");
	scanf("%s", file2);

	if(file1==NULL||file2==NULL){
		exit(0);
	}
	fdin = open(file1, O_RDONLY);
	fdout = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while((nread=read(fdin, buffer, 1024))>0){
		if(write(fdout, buffer, nread)<nread){
			/* write가 비정상적으로  수정되었음을 의미 */
			break;
		}
	}
	
	close(fdin);
	close(fdout);
	return 0;
}
