#include "mystdio.h"
void myfputc(char c, MYFILE* fp){
	fp->buf[fp->offset++]=c;
	fp->length++;

	if(fp->length==MYBUFSIZE){
		write(fp->fd, fp->buf, fp->length);
		fp->offset=fp->length=0;
	}
}
