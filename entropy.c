#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
FILE *file;
float entropy = 0.0;
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
/// get the next character in the file and covert it to hex
char getLine(  ){
    unsigned int c;
    unsigned char hex;
    c = getc(file);
    hex = c;
}
float findenp( int value ,float sum){
    float  x = value/sum;
    return   x  * log2(1/x);
}
int main( int argv,char *argc[]){
    //check for file
    check_for_error(argc[1]);
    fseek(file,0,SEEK_END); 
    int filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);
    // ClearLoop
    int array[255];
    int j;
    for(j =0;j < 256;j++) array[j] = 0.0;
    int i = 0;
    int totallevel = 0;

    while(   i < filesize){
        unsigned char hex = getLine();
        unsigned int c = hex; 
        array[c] = array[c] + 1;
        totallevel++;	
        i++; //i + 1 equal total;
    }
    i =0;
    while(i< 256){
        if(array[i] != 0){
            entropy += findenp(array[i],totallevel);
        }
        i++;
    }
    printf("Entropy:%2.5lf\n",entropy);

}// end of Main
