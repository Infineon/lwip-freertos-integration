#pragma once

#include <time.h>
#define LWIP_PLATFORM_ASSERT(x)  do {printf("Assertion \"%s\" failed at line %d in %s\n", \
                                     x, __LINE__, __FILE__); abort();} while(0)

#if (CY_CPU_CORTEX_M55)
extern uint8_t __attribute__((section(".cy_gpu_buf"))) memp_memory_PBUF_POOL_base[];
extern uint8_t __attribute__((section(".cy_gpu_buf"))) ram_heap[];
#elif !defined (CY_DISABLE_XMC7000_DATA_CACHE) && defined (__DCACHE_PRESENT) && (__DCACHE_PRESENT == 1U)
CY_SECTION_SHAREDMEM extern uint8_t memp_memory_PBUF_POOL_base[];
CY_SECTION_SHAREDMEM extern uint8_t ram_heap[];
#endif
                                     
#ifdef __ICCARM__
#define PACK_STRUCT_BEGIN __packed
#endif

