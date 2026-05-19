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
  descriptor |= (uint64_t)(flags & 0x0F) << 52;
  descriptor |= (uint64_t)((base >> 24) & 0xFF) << 56;
  return descriptor; 
}

struct __attribute__((packed)) gdt_desc {
  uint16_t size; 
  uint32_t start; 
};

extern void load_gdt(struct gdt_desc*); 

/* 
 *  8 bytes null descriptor 
 *  8 bytes for the kernel code descriptor
 *  8 bytes for the kernel data descriptor 
 *  TODO ring 1-3 
 * */
static uint64_t gdt[3];
static struct gdt_desc gdtr; 

void gdt_init(void) 
{
  gdt[0] = 0;   
  gdt[1] = gdt_create_descriptor(0x00000000, 0x000FFFFF, 0x9B, 0x0C); // kernel code segment
  gdt[2] = gdt_create_descriptor(0x00000000, 0x000FFFFF, 0x93, 0x0C); // kernel data segment
  gdtr.size = sizeof(gdt) - 1;
  gdtr.start = (uint32_t)gdt; 

  load_gdt(&gdtr); 
}
