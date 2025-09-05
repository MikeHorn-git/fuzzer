#include <asm/nyx_api.h>

bool kasan_report(const void *addr, size_t size, bool is_write,
		  unsigned long ip)
{
	kAFL_hypercall(HYPERCALL_KAFL_KASAN, 0);
}
