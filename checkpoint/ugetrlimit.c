
#include "syscalls.h"

struct rlimit {
	unsigned long	rlim_cur;
	unsigned long	rlim_max;
};

/* ugetrlimit is actually getrlimit in kernel,
 * libc's getrlimit is old_getrlimit in kernel  */

#ifndef SYSCALL_PRINTER
int SCOPE
post_ugetrlimit(struct syscall_regs * regs)
{
	
	write_eax(regs);
	if (regs->eax == 0) {
		write_mem(regs->ecx, sizeof(struct rlimit));
	}
	return 0;
}

#else

void
output_ugetrlimit(void)
{
	
}
#endif
