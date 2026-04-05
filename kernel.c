unsigned char *vga_buffer=(unsigned char*) 0xB8000;

unsigned char inb(unsigned short port)
{
    unsigned char ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "dN"(port));
    return ret;
}

void outb(unsigned short port, unsigned char val) {
    asm volatile ("outb %0, %1" : : "a"(val), "dN"(port));
}

void clear_screen() {
    for (int i = 0; i < 80 * 25 * 2; i+=2) {
        vga_buffer[i] = ' ';
        vga_buffer[i+1] = 0x07;
    }
}

extern void init_idt();

void keyboard_handler_main() {
    unsigned char status;
    unsigned char scancode;

    status = inb(0x64);

    if (status & 0x01) {
        scancode = inb(0x60);

        if (scancode == 0x1E) {
            vga_buffer[400] = 'I';
            vga_buffer[401] = 0x0E;
            vga_buffer[402] = 'T';
            vga_buffer[403] = 0x0E;
        }
    }

    outb(0x20, 0x20);
}
 void kernel_main() {
    init_idt();

    clear_screen();

    vga_buffer[0] = 'o'; vga_buffer[1] = 0x0F;
    vga_buffer[2] = 's'; vga_buffer[3] = 0x0F;
    vga_buffer[4] = ' '; vga_buffer[5] = 0x0F;
    vga_buffer[6] = 'R'; vga_buffer[7] = 0x0F;
    vga_buffer[8] = 'E'; vga_buffer[9] = 0x0F;
    vga_buffer[10] = 'A'; vga_buffer[11] = 0x0F;
    vga_buffer[12] = 'D'; vga_buffer[13] = 0x0F;
    vga_buffer[14] = 'Y'; vga_buffer[15] = 0x0F;

    while(1) {
        if(inb(0x64) & 0x01) {
            unsigned char scancode = inb(0x60);

            if(scancode == 0x1E) {
                vga_buffer[160] = 'A';
                vga_buffer[161] = 0x0A;
            }
        }
    }
}
