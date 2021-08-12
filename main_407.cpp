#include "mbed.h"
#include "SDFileSystem.h"

// initial SPI SD card setting
SDFileSystem sd(PC_3, PC_2, PB_10, PE_2, "sd"); // mo mi sck cs

// initial UART GPS setting
Serial GPS(PA_9, PA_10); // Tx Rx

// initial UART to LPC1768 setting
Serial uart(PC_6, PC_7); //tx rx
 
int main() {
    
    // initial FILE
    FILE *fp;
     
    //Mount the filesystem
    sd.mount();
    
    printf("Hello World!\n");   
 
    mkdir("/sd/mydir", 0777);
    
    fp = fopen("/sd/mydir/sdtest.txt", "w");
    if(fp == NULL) {
        error("Could not open file for write\n");
    }
    fprintf(fp, "Hello fun SD Card World!");
    
    fclose(fp); 
    // Unmount the filesystem
    sd.unmount();
 
    printf("Goodbye World!\n");
}


