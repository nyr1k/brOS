# brOS

A hobby x86 operating system kernel written in C and x86 NASM assembly for educational purposes and low-level systems programming practice.

## Goals
The reason I started this project is to solidify the knowledge gained during the OS course I took this semester. 

The main goals of this project are:

  1. Better understand operating system internals and x86 architecture
  2. Gain hands-on experience with low-level systems programming
  3. Learn how the kernel interacts with hardware 
  4. Build a long-term project focused on OS development concepts

## Current Features

### Boot and Build System

* Boot using GRUB multiboot
* Cross-compiler toolchain (`i686-elf-gcc`)

### VGA Text Terminal

* VGA text mode terminal driver
* Basic terminal output
* Scrolling support
* Newline handling

### Minimal libc Components

* `printf` implementation (partial)
* `putchar`
* `puts`
* Basic string utilities

### Protected Mode 

* Global Descriptor Table (GDT)
* Interrupt Descriptor Table (IDT)
* Basic interrupt handling stubs
* CPU exception handling groundwork

## Technologies

* C
* x86 Assembly (NASM)
* GNU Make
* QEMU
* GRUB
* GCC Cross Compiler

## Planned Features

* Improved interrupt handling
* Paging and virtual memory
* Kernel heap allocator
* Keyboard input driver
* Timer interrupts
* Basic scheduler and multitasking
* User mode support
* ELF executable loading

## Running

### My system
I use Fedora Linux 42 (Workstation Edition) x86_64
* CPU: AMD Ryzen 5 4600H (12) @ 3.00 GHz
* GPU: NVIDIA GeForce GTX 1650 Mobile / Max-Q [Discrete]
* RAM: 24 GB

### Cross-compiler
First that you will need is the cross-compiler. I followed this guide on the OSdev Wiki: https://wiki.osdev.org/GCC_Cross-Compiler

In order to build the cross-compiler, I installed binutils (2.46.0) source code from https://ftp.gnu.org/gnu/binutils/, and the source for the gcc (16.1.0) from https://ftp.gnu.org/gnu/gcc/ 

### GRUB and Qemu 
I use GRUB2 for booting. You can install it using the following command:
```bash
sudo dnf install shim-* grub2-efi-* grub2-common 
```
You will also need QEMU to test the kernel. You can install it using the following command: 
```bash
sudo dnf install qemu-system-x86 
```
### Running the kernel
Now you can start the kernel in qemu by running the following commands in the root directory: 
```bash
make
make run
```
## Possible issue 
For some reason my cross-compiler couldn't find <stdint.h>. So, if you have encountered the same issue and followed the cross-compiler build right, then you should create your own stdint.h file and include it in "/home/USERNAME/opt/cross/i686-elf/include". 

stdint.h: 

```bash
#ifndef _STDINT_H
#define _STDINT_H

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;

typedef signed long long int64_t;
typedef unsigned long long uint64_t;

#endif
```

## References

* [OSdev Wiki](https://wiki.osdev.org/Expanded_Main_Page)
* Operating System Concepts, 10th Edition by Abraham Silberschatz, Peter Baer Galvin, Greg Gagne
* [Intel Software Developer Manuals](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html) - Volumes 2 & 3
* [ctOS](https://github.com/christianb93/ctOS/tree/master) & [hux-kernel](https://github.com/josehu07/hux-kernel/tree/main)

