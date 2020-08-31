#include <stdlib.h>
#include <stdio.h>

main(int argc, char **argv){
    int i;
    char c;
    for (i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL){
            printf("Cannot open file. Check filename/location.\n");
            exit(1);
        }
        while ((c = fgetc(fp)) != EOF){
            putchar(c);
        }
        fclose(fp);
    }
    return 0;
}