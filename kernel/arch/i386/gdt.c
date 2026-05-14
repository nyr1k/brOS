#include <arch/i386/gdt.h> 
#include <stdint.h>

static uint64_t gdt_create_descriptor(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags) 
{
  uint64_t descriptor; 
  descriptor = (uint64_t) limit & 0xFFFF;
  descriptor |= (uint64_t)(base & 0xFFFF) << 16; 
  descriptor |= (uint64_t)((base >> 16) & 0xFF) << 32;
  descriptor |= (uint64_t)access << 40;
  descriptor |= (uint64_t)((limit >> 16) & 0x0F) << 48; 
  descriptor |= (uint64_t)(flags & 0xF0) << 48;
  descriptor |= (uint64_t)((base >> 24) & 0xFF) << 56;
  return descriptor; 
}

/* 
 *  8 bytes null descriptor 
 *  8 bytes for the kernel code descriptor
 *  8 bytes for the kernel data descriptor 
 *  TODO ring 1-3 
 * */
static uint64_t gdt[3];

void gdt_init(void) 
{
  gdt[0] = 0;   

  /* create kernel descriptor */;
  uint8_t code_access = 0x9B; // 1001 1011  
  uint8_t code_flags = 0xC0; // 1100 0000
  uint8_t data_access = 0x93; // 1001 0011
  uint8_t data_flags = 0xC0; // 1100 0000

  gdt[1] = gdt_create_descriptor(0x00000000, 0x000FFFFF, code_access, code_flags);
  gdt[2] = gdt_create_descriptor(0x00000000, 0x000FFFFF, data_access, data_flags);
}
