#include <stdio.h>
#include <unistd.h>

int main(){
	FILE *fp;
	char line[512];
	fp=fopen("data.txt", "r");

	fgets(line, 512, fp);
	fprintf(stderr, "before fork: %s", line);

	if(fork()>0){
		sleep(3);
		fgets(line, 512, fp);
		fprintf(stderr, "parent process: %s",line);
		//fprintf(stderr, "parent: %d", fp->file_desc);
	}
	else{
		fgets(line, 512, fp);
		fprintf(stderr, "child process: %s", line);
		//fprintf(stderr, "child: %d", fp.fd);
	}
	fgets(line, 512, fp);
	fprintf(stderr, "after fork:%s", line);
}
