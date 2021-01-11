#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define READONLY_MODE 0
#define WRITEONLY_MODE 1

#define MYBUFSIZE 512

#define EOF -1
typedef struct{
	int fd;
	char mode;
	char buf[MYBUFSIZE];
	int length;
	int offset;
}MYFILE;

MYFILE * myfopen(char* file,char* mode);
int myfclose(MYFILE* fp);
char myfgetc(MYFILE* fp);
void myfputc(char c, MYFILE* fp);
