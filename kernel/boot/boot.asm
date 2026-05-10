; constants for multiboot header
MBALIGN equ 1 << 0 ; align loaded modules 
MEMINFO equ 1 << 1 ; provide memory map 
MBFLAGS equ MBALIGN | MEMINFO ; multiboot flag 
MAGIC equ 0x1BADB002 ; magic number 
CHECKSUM equ -(MAGIC+MBFLAGS) ; check sum to prove we are multiboot

; multiboot header 
section .multiboot
align 4
  dd MAGIC
  dd MBFLAGS
  dd CHECKSUM

; allocating stack
section .bss 
align 16
stack_bottom:
resb 16384 ; 16KiB for stack
stack_top:

section .text
global _start:function (_start.end - _start)
_start:
  ; setting up stack
  mov esp, stack_top
  
  ; high-level kernel
  extern kernel_main
  call kernel_main

  cli 
.hang: hlt
  jmp .hang
.end:
