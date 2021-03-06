#include "syscalls.h"

struct iovec
{
	void *iov_base;	/* BSD uses caddr_t (1003.1g requires void *) */
	__kernel_size_t iov_len; /* Must be size_t (1003.1g) */
};

#ifndef SYSCALL_PRINTER

int SCOPE
post_writev(const struct syscall_regs * regs)
{
	/* i am writev, i don't need to write the content. */
	write_eax(regs);
	return 0;
}

int SCOPE
replay_writev(const struct syscall_regs * regs)
{
	int32_t eax = read_int32();
	return eax;
}

#else

void
output_writev(int nr)
{
	int32_t ret = read_eax();
	printf("writev:\t%d\n", ret);
}
#endif

