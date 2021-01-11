#include <stdio.h>
#include <unistd.h>
int main(){
	int i, j, k;

	for(i=0;i<5;i++){
		sleep(1);
		printf("before fork: i = %d\n", i);
	}

	if(fork()>0){/* parent */
		for(j=0;;j++){
			sleep(2);
			printf("parent : j = %d\n", j);
		}
	}
	else{/* child */
		for(k=0;;k++){
			sleep(3);
			printf("child : k = %d\n",k);
		}
	}
	return 0;
}
