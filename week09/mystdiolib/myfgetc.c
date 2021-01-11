#include "mystdio.h"
char myfgetc(MYFILE* fp){
	if(fp==NULL) return EOF;
	if(fp->mode==WRITEONLY_MODE) return EOF;
	if(fp->offset==fp->length){
		if((fp->length=read(fp->fd, fp->buf, MYBUFSIZE))<1)
			return EOF;
		fp->offset=0;
	}
	return fp->buf[fp->offset++];
}
