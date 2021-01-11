#include <unistd.h>
#include <signal.h>

static void sig_alrm(int signo){
	return ;
}
int sleep(int nsecs){
	if(signal(SIGALRM, sig_alrm)==SIG_ERR) return nsecs;
	alarm(nsecs);
	pause();
	return (alarm(0));
}
