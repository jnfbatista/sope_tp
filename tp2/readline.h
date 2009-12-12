#ifndef _READLINE_H_
#define _READLINE_H_

#include <unistd.h>

ssize_t readline(int fd, void * vptr, size_t maxlen);

#endif
