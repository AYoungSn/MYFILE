#include "mystdio.h"
int myfclose(MYFILE* fp){
	if(fp==NULL) return EOF;
	if(fp->mode==WRITEONLY_MODE){
		write(fp->fd, fp->buf, fp->length);
	}
	if(close(fp->fd)<0){
		free(fp);
		return EOF;
	}
	free(fp);
	return 0;
}

