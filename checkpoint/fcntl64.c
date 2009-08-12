
#include "syscalls.h"
#ifndef SYSCALL_PRINTER
int SCOPE
post_fcntl64(const struct syscall_regs * regs)
{
	write_eax(regs);
	return 0;
}

int SCOPE
replay_fcntl64(const struct syscall_regs * regs)
{
	return read_int32();
}

#else

void
output_fcntl64(int nr)
{
	printf("fcntl64:\t%d\n", read_eax());
}
#endif

