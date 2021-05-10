#include <stdio.h>
#include <stdint.h>
#include <string.h>

void read_binary(void *ptr, char *dtype);

int main() {
    float pif = 3.141; //0 10000000 10010010000011000100101
    printf("float representation of %f = ", pif);
    read_binary(&pif,"float");

    float pifn = -3.141; //1 10000000 10010010000011000100101
    printf("float representation of %f = ", pifn);
    read_binary(&pifn,"float");

    double pid = 3.141; //0 10000000 10010010000011000100101
    printf("double representation of %f = ", pid);
    read_binary(&pid,"double");

    double pidn = -3.141; //1 10000000 10010010000011000100101
    printf("double representation of %f = ", pidn);
    read_binary(&pidn,"double");

    short a = 10;
    printf("short representation of %d = ", a);
    read_binary(&a,"short");

    short an = -10;
    printf("short representation of %d = ", an);
    read_binary(&an,"short");

    return 0;
}

void read_binary(void *ptr, char *dtype) {
    if (strcmp(dtype,"char") == 0) {    // read character from memory
        uint8_t *p2f = (uint8_t*)ptr;   
        // 10000000
        uint16_t mask = 0x80;
        for (size_t i = 1; i <= sizeof(char)*8; i++) {
            putchar(*p2f & mask ? '1' : '0');
            mask >>= 1;
        }
        putchar('\n');
    }
    if (strcmp(dtype,"short") == 0) {    // read short from memory
        uint16_t *p2f = (uint16_t*)ptr;
        // 10000000 00000000
        uint16_t mask = 0x8000;
        for (size_t i = 1; i <= sizeof(short)*8; i++) {
            putchar(*p2f & mask ? '1' : '0');
            mask >>= 1;
            if (i % 8 == 0) { // output space after 8 bits
                putchar(' ');
            }
        }
        putchar('\n');
    }
    if (strcmp(dtype,"int") == 0) {    // read integer from memory
        uint32_t *p2f = (uint32_t*)ptr;
        // // 10000000 00000000 00000000 00000000
        uint32_t mask = 0x80000000;
        for (size_t i = 1; i <= sizeof(int)*8; i++) {
            putchar(*p2f & mask ? '1' : '0');
            mask >>= 1;
            if (i % 8 == 0) { // output space after 8 bits
                putchar(' ');
            }
        }
        putchar('\n');
    }
    if (strcmp(dtype,"float") == 0) {    // read float from memory
    // https://www.h-schmidt.net/FloatConverter/IEEE754.html
        uint32_t *p2f = (uint32_t*)ptr;
        // 10000000 00000000 00000000 00000000
        uint32_t mask = 0x80000000;
        for (size_t i = 1; i <= sizeof(float)*8; i++) {
            putchar(*p2f & mask ? '1' : '0');
            mask >>= 1;
            if (i == 1) {
                putchar(' ');
            }
            else if (i == 9) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    if (strcmp(dtype,"double") == 0) {    // read double from memory
        uint64_t *p2f = (uint64_t*)ptr;
        // 10000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
        uint64_t mask = 0x8000000000000000;
        for (size_t i = 1; i <= sizeof(double)*8; i++) {
            putchar(*p2f & mask ? '1' : '0');
            mask >>= 1;
            if (i == 1) {
                putchar(' ');
            }
            else if (i == 12) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}