#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	if(chown("test.txt",2045,200)==-1){
		perror("chown");exit(-1);
	}
	return 0;
}
