#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd=open("data.txt",O_RDONLY);
	execl("./mycat", "mycat", NULL);
}
