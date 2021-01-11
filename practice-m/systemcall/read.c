#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int p;
	int q[10];

	printf("p = %d\n",p);
	for(int i=0;i<10;i++)
		printf("q[%d] = %d\n", i, q[i]);

	int fd = open("output.txt",O_RDONLY);
	read(fd, &p, sizeof(p));
	read(fd, q, sizeof(q));
	close(fd);

	printf("p = %d\n",p);
	for(int i=0;i<10;i++)
		printf("q[%d] = %d\n", i, q[i]);
	
	return 0;
}
