#include <stdio.h>
#include <unistd.h>

int main(){
	for(int i=0;i<10;i++){
		sleep(1);
		if(i==5){
			fprintf(stderr,"Now I am...");
			execl("./batman", "batman",NULL);
		}else printf("I am Superman! i=%d\n",i);
	}
}
