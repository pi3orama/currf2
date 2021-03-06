#ifndef SOCKETCALL_H
#define SOCKETCALL_H

#include "syscalls.h"

#define SYS_SOCKET	1		/* sys_socket(2)		*/
#define SYS_BIND	2		/* sys_bind(2)			*/
#define SYS_CONNECT	3		/* sys_connect(2)		*/
#define SYS_LISTEN	4		/* sys_listen(2)		*/
#define SYS_ACCEPT	5		/* sys_accept(2)		*/
#define SYS_GETSOCKNAME	6		/* sys_getsockname(2)		*/
#define SYS_GETPEERNAME	7		/* sys_getpeername(2)		*/
#define SYS_SOCKETPAIR	8		/* sys_socketpair(2)		*/
#define SYS_SEND	9		/* sys_send(2)			*/
#define SYS_RECV	10		/* sys_recv(2)			*/
#define SYS_SENDTO	11		/* sys_sendto(2)		*/
#define SYS_RECVFROM	12		/* sys_recvfrom(2)		*/
#define SYS_SHUTDOWN	13		/* sys_shutdown(2)		*/
#define SYS_SETSOCKOPT	14		/* sys_setsockopt(2)		*/
#define SYS_GETSOCKOPT	15		/* sys_getsockopt(2)		*/
#define SYS_SENDMSG	16		/* sys_sendmsg(2)		*/
#define SYS_RECVMSG	17		/* sys_recvmsg(2)		*/

extern SCOPE int
post_socket(int family, int type, int protocol, int retval, const struct syscall_regs * regs);
extern SCOPE int
replay_socket(int family, int type, int protocol, int retval, const struct syscall_regs * regs);
extern void
output_socket(int family, int type, int protocol, int retval);

extern int SCOPE
post_bind(int fd, uint32_t umyaddr, int addrlen, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_bind(int fd, uint32_t umyaddr, int addrlen, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_bind(int fd, uint32_t umyaddr, int addrlen, int retval);

extern int SCOPE
post_getsockname(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_getsockname(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_getsockname(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval);

extern int SCOPE
post_sendto(int fd, uint32_t buff, uint32_t len, uint32_t flags,
		uint32_t addr, uint32_t addr_len, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_sendto(int fd, uint32_t buff, uint32_t len, uint32_t flags,
		uint32_t addr, uint32_t addr_len, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_sendto(int fd, uint32_t buff, uint32_t len, uint32_t flags,
		uint32_t addr, uint32_t addr_len, int retval);

extern int SCOPE
post_recvfrom(int fd, uint32_t ubuf, uint32_t size,
		uint32_t flags, uint32_t addr,
		uint32_t addr_len, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_recvfrom(int fd, uint32_t ubuf, uint32_t size,
		uint32_t flags, uint32_t addr,
		uint32_t addr_len, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_recvfrom(int fd, uint32_t ubuf, uint32_t size,
		uint32_t flags, uint32_t addr,
		uint32_t addr_len, int retval);

extern int SCOPE
post_recvmsg(int fd, uint32_t msg, uint32_t flags, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_recvmsg(int fd, uint32_t msg, uint32_t flags, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_recvmsg(int fd, uint32_t msg, uint32_t flags, int retval);

extern int SCOPE
post_connect(int fd, uint32_t uservaddr, int addrlen, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_connect(int fd, uint32_t uservaddr, int addrlen, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_connect(int fd, uint32_t uservaddr, int addrlen, int retval);

extern int SCOPE
post_recv(int fd, uint32_t ubuf, uint32_t size, uint32_t flags, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_recv(int fd, uint32_t ubuf, uint32_t size, uint32_t flags, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_recv(int fd, uint32_t ubuf, uint32_t size, uint32_t flags, int retval);

extern int SCOPE
post_getpeername(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_getpeername(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_getpeername(int fd, uint32_t usockaddr, uint32_t usockaddr_len, int retval);

extern int SCOPE
post_setsockopt(int fd, int level, int optname,
		uint32_t optval, int optlen, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_setsockopt(int fd, int level, int optname,
		uint32_t optval, int optlen, int retval, const struct syscall_regs * regs);
extern void SCOPE
output_setsockopt(int fd, int level, int optname,
		uint32_t optval, int optlen, int retval);

extern SCOPE int
post_listen(int fd, int backlog, int retval, const struct syscall_regs * regs);
extern SCOPE int
replay_listen(int fd, int backlog, int retval, const struct syscall_regs * regs);
extern void
output_listen(int fd, int backlog, int retval);


extern int SCOPE
post_accept(int fd, uintptr_t pupeer_sockaddr,
		uintptr_t pupeer_addrlen, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_accept(int fd, uintptr_t pupeer_sockaddr,
		uintptr_t pupeer_addrlen, int retval, const struct syscall_regs * regs);
void SCOPE
output_accept(int fd, uintptr_t pupeer_sockaddr,
		uintptr_t pupeer_addrlen, int retval);


extern int SCOPE
post_shutdown(int fd, int how, int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_shutdown(int fd, int how, int retval, const struct syscall_regs * regs);
void SCOPE
output_shutdown(int fd, int how, int retval);

extern int SCOPE
post_send(int fd, uint32_t buff, uint32_t len, uint32_t flags,
		int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_send(int fd, uint32_t buff, uint32_t len, uint32_t flags,
		int retval, const struct syscall_regs * regs);
extern void SCOPE
output_send(int fd, uint32_t buff, uint32_t len, uint32_t flags, int retval);

extern SCOPE int
post_socketpair(int family, int type, int protocol, uintptr_t usockvec, int retval,
		const struct syscall_regs * regs);
extern SCOPE int
replay_socketpair(int family, int type, int protocol, uintptr_t usockvec, int retval,
		const struct syscall_regs * regs);
extern void
output_socketpair(int family, int type, int protocol,
		uintptr_t usockvec, int retval);

extern int SCOPE
post_sendmsg(int fd, uintptr_t msg, uint32_t flags,
		int retval, const struct syscall_regs * regs);
extern int SCOPE
replay_sendmsg(int fd, uintptr_t msg, uint32_t flags,
		int retval, const struct syscall_regs * regs);
extern void SCOPE
output_sendmsg(int fd, uintptr_t msg, uint32_t flags, int retval);


#endif 

