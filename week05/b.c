#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int p;
	int q[10];

	int fd;
	fd = open("output.data", O_RDONLY);
	read(fd, (void*)&p, sizeof(p));
	read(fd, (void *)q, sizeof(q));
	close(fd);

	printf("p = %d\n",p);
	for(int i=0;i<10;i++)
		printf("q[%d] = %d\n",i,q[i]);

	return 0;
}
