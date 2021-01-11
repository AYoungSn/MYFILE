#include <stdio.h>
#include <unistd.h>

int main(){
	char* msg[3]={"apple is red\n","banana is yellow\n","cherry is red\n"};
	int p[2],j;
	pid_t pid;

	pipe(p);

	if((pid=fork())>0){
		printf("[parent]\n");
		close(p[0]);
		for(j=0;j<3;j++)
			write(p[1],msg[j],strlen(msg[j])+1);
	}else{
		printf("[child]\n");
		close(p[1]); dup2(p[0],0);
		execlp("wc","wc",NULL);
		printf("[child] fail to call execlp()\n");
	}
}
