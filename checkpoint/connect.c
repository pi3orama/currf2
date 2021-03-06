
#include "socketcall.h"
#ifndef SYSCALL_PRINTER

int SCOPE
post_connect(int fd, uint32_t uservaddr, int addrlen, int retval, const struct syscall_regs * regs)
{
	return 0;
}

int SCOPE
replay_connect(int fd, uint32_t uservaddr, int addrlen, int retval, const struct syscall_regs * regs)
{
	return retval;
}


#else

void SCOPE
output_connect(int fd, uint32_t uservaddr, int addrlen, int retval)
{
	printf("connect(fd=%d, uservaddr=0x%x, addrlen=%d):\t%d\n",
			fd, uservaddr, addrlen, retval);
}

#endif

