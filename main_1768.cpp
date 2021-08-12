#include "mbed.h"


Serial pc(USBTX,USBRX);

Serial uart(p13,p14); //tx rx (PC_7,PC_6) rx tx

int main()
{
    pc.printf("Start\r\n");
    while(1) {
        pc.putc(uart.getc());
    }

}
