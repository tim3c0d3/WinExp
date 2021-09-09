#include <stdlib.h>
#include "memalloc.h"


void *save_buffer(int buffer_size){
	char *buf;
	if (buffer_size < MIN_BUFFER_SIZE){
		buf = (char *)malloc(MIN_BUFFER_SIZE);
	}
	else{
		buf = (char *)malloc(buffer_size);
	}
	return buf;
}
