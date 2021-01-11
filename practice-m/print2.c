#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main(){
	FILE *fp = fopen("out","w");
	int fd=open("out",O_WRONLY|O_CREAT|O_TRUNC,0644);

	fprintf(fp, "Hello ");
	fprintf(stderr, "This is an error message...\n");
	fprintf(fp, "world!!!\n");

	fprintf(fp, "Hello\n");
	fprintf(fp, "This is an error message...");
	fprintf(fp, "world!!!\n");

	char buf[]="Hello world-system call\n";
	write(fd, buf, strlen(buf));
	sleep(5);

	fclose(fp);
	close(fd);
}
