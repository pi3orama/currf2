
#include "syscalls.h"

#ifndef SYSCALL_PRINTER

int SCOPE
post_dup2(const struct syscall_regs * regs)
{
	write_eax(regs);
	return 0;
}

int SCOPE
replay_dup2(const struct syscall_regs * regs)
{
	int32_t eax = read_int32();
	return eax;
}
#else

void
output_dup2(int nr)
{
	printf("dup2:\t%d\n", read_eax());
}
#endif

