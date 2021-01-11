#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <unistd.h>


int main(){
	int fd, n;
	char line[512];

	fd = open("data.txt", O_RDONLY);

	n=read(fd, line, 17);
	line[n]='\0';
	fprintf(stderr, "before fork: %s", line);

	if(fork()>0){/* parent process */
		sleep(3);
		n=read(fd, line, 17);
		line[n]='\0';
		fprintf(stderr,"parent proces: %s", line);
	}
	else{/* child process */
		n=read(fd, line, 17);
		line[n]='\0';
		fprintf(stderr, "child process: %s",line);
	}
	n=read(fd, line, 17);
	line[n]='\0';
	fprintf(stderr, "after fork: %s",line);
	close(fd);
}
