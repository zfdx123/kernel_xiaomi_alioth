// SPDX-License-Identifier: GPL-2.0

#include <linux/compiler.h>
#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/types.h>

struct filename;

bool __weak ksu_input_hook __read_mostly;
bool __weak ksu_init_rc_hook __read_mostly;

int __weak ksu_handle_stat(int *dfd, const char __user **filename_user,
			   int *flags)
{
	return 0;
}

void __weak ksu_handle_newfstat_ret(unsigned int *fd,
				    struct stat __user **statbuf_ptr)
{
}

#if defined(__ARCH_WANT_STAT64) || defined(__ARCH_WANT_COMPAT_STAT64)
void __weak ksu_handle_fstat64_ret(unsigned long *fd,
				   struct stat64 __user **statbuf_ptr)
{
}
#endif

int __weak ksu_handle_execveat(int *fd, struct filename **filename_ptr,
			       void *argv, void *envp, int *flags)
{
	return 0;
}

int __weak ksu_handle_faccessat(int *dfd,
				const char __user **filename_user,
				int *mode, int *flags)
{
	return 0;
}

int __weak ksu_handle_sys_reboot(int magic1, int magic2, unsigned int cmd,
				 void __user **arg)
{
	return 0;
}

int __weak ksu_handle_input_handle_event(unsigned int *type,
					 unsigned int *code, int *value)
{
	return 0;
}

int __weak ksu_handle_setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
	return 0;
}

int __weak ksu_handle_sys_read(unsigned int fd, char __user **buf_ptr,
			       size_t *count_ptr)
{
	return 0;
}
