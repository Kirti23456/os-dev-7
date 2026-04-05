# MyCustomOS - A Simple x86 Kernel

Welcome to my Operating System project! This is a 32-bit x86 kernel built from scratch as part of my B.Tech project. It currently supports basic booting, GDT/IDT initialization, and hardware interrupts (specifically Keyboard).

## 🚀 Current Status: "The Keyboard Milestone"
As of today, the OS successfully:
- Boots using GRUB/Multiboot.
- Loads a custom *Global Descriptor Table (GDT)*.
- Initializes the *Interrupt Descriptor Table (IDT)*.
- Handles *Hardware Interrupts (IRQ 1)* from the Keyboard.
- Prints "IT" to the VGA buffer when the 'A' key is pressed.

## 🛠 Project Structure
- boot.asm: The entry point that handles the transition to C.
- kernel.c: The main kernel logic and keyboard handler.
- idt.c: Logic for setting up interrupt gates.
- interrupt.asm: Assembly stubs for handling interrupts without crashing.
- linker.ld: Defines the memory layout of the kernel.

## 💻 How to Run
To compile and run this OS, you will need nasm, gcc (multilib for 32-bit), and qemu.

### 1. Assemble & Compile
```bash
nasm -f elf32 boot.asm -o boot.o
nasm -f elf32 interrupt.asm -o interrupt.o
gcc -m32 -c kernel.c -o kernel.o -ffreestanding -fno-stack-protector -fno-pie
gcc -m32 -c idt.c -o idt.o -ffreestanding -fno-stack-protector -fno-pie


--
By AUTHOR KIRTI SRIVASTAVA
