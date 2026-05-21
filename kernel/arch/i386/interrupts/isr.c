#include <arch/i386/isr.h>
#include <stdio.h> 

void isr_handle(isr_state_t* isr_frame)
{
    printf("Problem!\nInterrupt index: %d\nIndex node: %d\n", isr_frame->interrupt_index, isr_frame->error_code);
}