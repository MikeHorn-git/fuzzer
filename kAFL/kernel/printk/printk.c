#include <asm/nyx_api.h>

asmlinkage __visible int _printk(const char *fmt, ...)
{
	static char hprintf_buffer[HPRINTF_MAX_SIZE]
		__attribute__((aligned(4096)));

	va_list args;
	int r = vsnprintf((char *)hprintf_buffer, HPRINTF_MAX_SIZE, fmt, args);
	//printf("%s", hprintf_buffer);
	kAFL_hypercall(HYPERCALL_KAFL_PRINTF, (uintptr_t)hprintf_buffer);
}
