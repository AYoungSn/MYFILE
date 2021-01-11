#include <unistd.h>
int main(){
	if(fork()>0){
		/* parent */
	}
	else {
		/* child */
		for(;;);
	}
}
