#include <stdio.h>
#include <unistd.h>

int main(){
	FILE *fp;
	fp=fopen("out","w");
	fprintf(fp, "Hello ");
	fprintf(stderr, "This is an error message...");
	fprintf(fp, "world!!\n");

	fprintf(fp, "Hello\n");
	fprintf(fp, "This is an error message...");
	fprintf(fp, "world!!");

	sleep(10);

	//fclose(fp);
	return 0;
}
