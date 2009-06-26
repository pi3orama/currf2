/* 
 * recorder.h
 * by WN @ Jun. 22, 2009
 */

#ifndef __CHECKPOINT_H
#define __CHECKPOINT_H

#include <sys/cdefs.h>
#include <stdint.h>
#include <unistd.h>
#include "defs.h"
#include "syscall_table.h"

#ifndef INJECTOR
# include "ptraceutils.h"
# include <stdio.h>
# include <stdlib.h>
# include <alloca.h>
# include "debug.h"
# include "exception.h"
#endif

__BEGIN_DECLS

#ifndef INJECTOR
# define SCOPE
# define __open open
# define __close close
# define __read read
# define __write write
# define __printf printf
# define __exit(x) THROW(EXCEPTION_FATAL, "checkpoint exit")
# define __dup_mem(d, s, sz) ptrace_dupmem(d, s, sz)

#define write_syscall_nr(nr)	do {	\
	uint32_t x_nr;	\
	x_nr = nr;	\
	__write(logger_fd, &x_nr, sizeof(x_nr));	\
} while(0)

#define write_regs(regs)	do {	\
	__write(logger_fd, regs, sizeof(*regs));	\
} while(0)

#define write_eax(regs)	do {	\
	__write(logger_fd, &regs->eax, sizeof(regs->eax));	\
} while(0)

#define write_mem(addr, sz) do {	\
	void * p;			\
	if (sz <= (1 << 20))		\
		p = alloca(sz);		\
	else				\
		p = malloc(sz);		\
	__dup_mem(p, addr, sz);		\
	__write(logger_fd, p, sz);	\
	if (sz > (1 << 20))		\
		free(p);		\
} while(0)

#endif

#define GDT_ENTRY_TLS_MIN	6
#define GDT_ENTRY_TLS_ENTRIES 3
#define GDT_ENTRY_TLS_MAX 	(GDT_ENTRY_TLS_MIN + GDT_ENTRY_TLS_ENTRIES - 1)

struct user_desc {
	unsigned int  entry_number;
	unsigned int  base_addr;
	unsigned int  limit;
	unsigned int  seg_32bit:1;
	unsigned int  contents:2;
	unsigned int  read_exec_only:1;
	unsigned int  limit_in_pages:1;
	unsigned int  seg_not_present:1;
	unsigned int  useable:1;
};


extern SCOPE struct state_vector {
	int dummy;
	uint32_t brk;
	struct user_desc thread_area[GDT_ENTRY_TLS_ENTRIES];
} state_vector;

extern SCOPE int
checkpoint_init(void);

extern SCOPE int
logger_init(pid_t pid);

extern SCOPE int
logger_close(void);

extern SCOPE int
before_syscall(struct syscall_regs regs);

extern SCOPE int
after_syscall(struct syscall_regs regs);

__END_DECLS

#endif
