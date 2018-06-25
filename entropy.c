#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
FILE *file;
struct test2
{
    unsigned char x:8;
    unsigned int: 0;
    unsigned int y: 8;
} ;
void check_for_error(char *fileIn){

    if( fileIn  == NULL){
        printf("INPUT ERROR:NO FILE\nExample:    entropy.exe <target file>\n");
        exit(-1);
    }
    file = fopen(fileIn,"rb");
    if(file == NULL){
        fprintf(stderr, "Error opening file: %s\n",fileIn);
        exit(-1);
    }
}
/// code from the notes not really needed right now 
typedef struct _MESSAGE
{
    union
    {   unsigned char bit1:1;
        unsigned char bit2:2;
        unsigned char bit3:3;
        unsigned char bit4:4;
        unsigned char bit5:5;
        unsigned char bit6:6;
        unsigned char bit7:7;
        unsigned char bit8:8;
    } BYTE;
} MESSAGE;

void readMsg()
{
    MESSAGE tMsg;
    tMsg.BYTE.bit8 = 0xC;

    printf("1=%x, 2=%x, 3=%x, 4=%x, 5=%x, 6=%x, 7=%x, 8=%x \n", 
            tMsg.BYTE.bit1, tMsg.BYTE.bit2, tMsg.BYTE.bit3, tMsg.BYTE.bit4, 
            tMsg.BYTE.bit5, tMsg.BYTE.bit6, tMsg.BYTE.bit7, tMsg.BYTE.bit8);
    return;
}
/// get the next character in the file and covert it to hex
char getLine(  ){
    unsigned int c;
    unsigned char hex;
    c = getc(file);
    hex = c;
    printf("%x\n",hex);
    //printf("%x\n",tMsg2.BYTE.bit8);
}
int main( int argv,char *argc[]){
    //check for file
    check_for_error(argc[1]);
    while(
    getLine();

}// end of Main
