#include <stdio.h>
#include <unistd.h>

int main(){
	for(int i=0;i<100;i++){
		sleep(1);
		printf("j = %d\n",i);
	}
	return 0;
}
