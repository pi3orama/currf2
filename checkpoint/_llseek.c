
#include "syscalls.h"

typedef long long	__kernel_loff_t;
typedef __kernel_loff_t		loff_t;

#ifndef SYSCALL_PRINTER

int SCOPE
post__llseek(const struct syscall_regs * regs)
{
	write_eax(regs);
	uint32_t presult = regs->esi;
	write_obj(presult);
	if (regs->eax >= 0) {
		if (presult != 0)
			write_mem(presult, sizeof(loff_t));
	}
	return 0;
}

int SCOPE
replay__llseek(const struct syscall_regs * regs)
{
	int32_t eax = read_int32();
	uint32_t presult;
	read_obj(presult);
	ASSERT(presult == regs->esi, regs, "");
	if (eax >= 0) {
		if (presult != 0)
			read_mem(presult, sizeof(loff_t));
	}
	return eax;
}

#else

void
output__llseek(int nr)
{
	int retval = read_eax();
	uint32_t presult;
	read_obj(presult);
	printf("_llseek:\t0x%x\n", retval);
	if (retval >= 0) {
		if (presult != 0)
			skip(sizeof(loff_t));
	}
}
#endif

