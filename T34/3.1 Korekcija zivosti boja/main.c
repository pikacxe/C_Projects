#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define size 150

typedef struct pixel_st{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}PIXEL;

FILE *safe_fopen(char *name, char *mode) {
    FILE *pf = fopen(name, mode);
    if(pf == NULL) {
        printf("File %s could not be opened!\n", name);
        exit(EXIT_FAILURE);
    }
    return pf;
}



int main(int num_args, char **args) {
    if(num_args != 3) {
        printf("USAGE: %s in.bmp out.bmp", args[0]);
        exit(1);
    }
    FILE *in = safe_fopen(args[1],"rb");
    FILE *out = safe_fopen(args[2],"wb");


    return 0;
}


