#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
	int a=3;
	int b[]={0,1,2,3,10,20,30,100,200,300};

	for(int i=0;i<10;i++)
		b[i]*=a;
	printf("a = %d\n",a);

	for(int i=0;i<10;i++)
		printf("b[%d] = %d\n", i, b[i]);

	int fd = open("output2.txt", O_WRONLY|O_CREAT|O_TRUNC,0644);
	int fd2 = open("output2.txt", O_RDONLY);
	write(fd,(void*)&a,sizeof(a));
	write(fd,(void*)b,sizeof(b));
	int n=97; 
	write(fd, &n,sizeof(n));
	char c='a';
	char ch[]={'0','1','2','3'};
	write(fd, (void*)&c, sizeof(c));
	write(fd, ch, sizeof(ch));
	
	int nread;
	char buf[100];
//	close(fd);
	while((nread=read(fd2, buf, 100))<0){
		write(STDOUT_FILENO, buf,100);
	}

	close(fd2);
	close(fd);
}
