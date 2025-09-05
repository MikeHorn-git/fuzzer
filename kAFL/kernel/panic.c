#include <asm/nyx_api.h>

void oops_exit(void)
{
	kAFL_hypercall(HYPERCALL_KAFL_PANIC, 0);
}
