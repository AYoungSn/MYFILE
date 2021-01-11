#include <time.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	time_t curTime;
	char *stime1, *stime2;

	time(&curTime);
	stime1=ctime(&curTime);

	sleep(2);

	time(&curTime);
	stime2=ctime(&curTime);

	printf("current time = %ld\n", curTime);
	printf("%s, %s", stime1, stime2);
}
