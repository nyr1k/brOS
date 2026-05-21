#ifndef ARCH_I386_ISR_H
#define ARCH_I386_ISR_H

#include <stdint.h> 

typedef struct __attribute__((packed)) isr_state {
    uint32_t ds;
    uint32_t edi, esi, ebp, esp_old, ebx, edx, ecx, eax;
    uint32_t interrupt_index, error_code;
    uint32_t eip, cs, eflags, esp_og, ss; 
} isr_state_t; 

#ifdef __cplusplus
extern "C" {
#endif 

void isr_handle(isr_state_t* isr_frame); 

#ifdef __cplusplus
}
#endif

#endif 