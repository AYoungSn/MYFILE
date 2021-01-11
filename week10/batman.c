#include <stdio.h>
#include <unistd.h>

int main(){
	for(int i=0;i<10;i++){
		sleep(1);
		printf("I am Batman! i=%d\n",i);
	}
}
