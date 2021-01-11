#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(){
	int a=3;
	int b[10]={0,1,2,3,10,20,30,100,200,300};
	int fd;

	for(int i=0;i<10;i++) b[i]*=a;

	printf("a = %d\n",a);
	for(int i=0;i<10;i++)
		printf("b[%d] = %d\n",i,b[i]);

	fd=open("output.data",O_WRONLY | O_CREAT, 0644);
	
	if(fd==-1){
		perror("output.data");
		exit(-1);
	}

	write(fd, (void*)&a, sizeof(a));
	write(fd, (void*)b, sizeof(b));
	close(fd);
	return 0;
}
