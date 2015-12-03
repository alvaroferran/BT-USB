#include "mbed.h"
#include "USBSerial.h"
 
//Virtual serial port over USB
USBSerial pc;
Serial bt(USBTX, USBRX);


int main(void) {
    bt.baud(115200);
    bt.printf("AT+NAMEbqBtUSB\r\n");
    bt.printf("AT+ROLE0\r\n");//Slave=0 Master=1
    
    pc.printf("Starting\n");
    char r;
    while(1)
    {
       if (bt.readable()) {
            r = bt.getc();
            pc.putc(r);
        }
        if (pc.readable()) {
            r = pc.getc();
            bt.putc(r);
        }
    }
} 
