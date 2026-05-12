PREFIX = $(HOME)/opt/cross/bin
CC = $(PREFIX)/i686-elf-gcc
AS = nasm 
CFLAGS = -std=gnu99 -D__is_libk -ffreestanding -Ikernel/include -Ilibc/include -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
BUILD_DIR = build
TARGET_ISO = $(BUILD_DIR)/brOS.iso
TARGET_BIN = $(BUILD_DIR)/brOS 
ARCH_I386 = kernel/arch/i386
OBJ = $(BUILD_DIR)/boot.o \
	$(BUILD_DIR)/kernel.o \
	$(BUILD_DIR)/tty.o \
	$(BUILD_DIR)/libc/string.o \
	$(BUILD_DIR)/libc/putchar.o \
	$(BUILD_DIR)/libc/puts.o \
	$(BUILD_DIR)/libc/printf.o

all: $(TARGET_ISO)
  
$(TARGET_ISO): $(TARGET_BIN)
	@mkdir -p $(BUILD_DIR)/isodir/boot/grub
	@cp $(TARGET_BIN) $(BUILD_DIR)/isodir/boot/brOS 
	@cp GRUB/grub.cfg $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	grub2-mkrescue -o $(TARGET_ISO) $(BUILD_DIR)/isodir  

$(TARGET_BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET_BIN) $(OBJ)

$(BUILD_DIR)/boot.o: $(ARCH_I386)/boot.asm
	@mkdir -p $(dir $@)
	$(AS) -felf32 $(ARCH_I386)/boot.asm -o $@

$(BUILD_DIR)/kernel.o: kernel/kernel/kernel.c 
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c kernel/kernel/kernel.c -o $@ 

$(BUILD_DIR)/tty.o: $(ARCH_I386)/tty.c
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c $(ARCH_I386)/tty.c -o $@

$(BUILD_DIR)/libc/string.o: libc/string/string.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c libc/string/string.c -o $@

$(BUILD_DIR)/libc/putchar.o: libc/stdio/putchar.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c libc/stdio/putchar.c -o $@ 

$(BUILD_DIR)/libc/puts.o: libc/stdio/puts.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c libc/stdio/puts.c -o $@

$(BUILD_DIR)/libc/printf.o: libc/stdio/printf.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c libc/stdio/printf.c -o $@

run: $(TARGET_ISO)
	qemu-system-i386 -cdrom $(TARGET_ISO)

clean:
	rm -rf $(BUILD_DIR)
