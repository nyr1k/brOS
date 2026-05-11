PREFIX = $(HOME)/opt/cross/bin
CC = $(PREFIX)/i686-elf-gcc
AS = nasm 
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc
BUILD_DIR = build
TARGET_ISO = $(BUILD_DIR)/brOS.iso
TARGET_BIN = $(BUILD_DIR)/brOS 

OBJ = $(BUILD_DIR)/boot/boot.o $(BUILD_DIR)/kernel/kernel.o

all: $(TARGET_ISO)
  
$(TARGET_ISO): $(TARGET_BIN)
	@mkdir -p $(BUILD_DIR)/isodir/boot/grub
	@cp $(TARGET_BIN) $(BUILD_DIR)/isodir/boot/brOS 
	@cp GRUB/grub.cfg $(BUILD_DIR)/isodir/boot/grub/grub.cfg
	grub2-mkrescue -o $(TARGET_ISO) $(BUILD_DIR)/isodir  

$(TARGET_BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $(TARGET_BIN) $(OBJ)

$(BUILD_DIR)/boot/boot.o: src/boot/boot.asm
	@mkdir -p $(dir $@)
	$(AS) -felf32 src/boot/boot.asm -o $@

$(BUILD_DIR)/kernel/kernel.o: src/kernel/kernel.c 
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c src/kernel/kernel.c -o $@ 

run: $(TARGET_ISO)
	qemu-system-i386 -cdrom $(TARGET_ISO)

clean:
	rm -rf $(BUILD_DIR)
