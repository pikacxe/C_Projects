#include <stdio.h>
#include <stdlib.h>

FILE *safe_fopen(char *name, char *mode);

int main(int num_args, char **args) {
    if(num_args != 3) {
        printf("USAGE: %s in.bmp out.bmp", args[0]);
        exit(1);
    }
    return 0;
}

FILE *safe_fopen(char *name, char *mode) {
    FILE *pf = fopen(name, mode);
    if(pf == NULL) {
        printf("File '%s' could not be opened!\n", name);
        exit(EXIT_FAILURE);
    }
    return pf;
}
