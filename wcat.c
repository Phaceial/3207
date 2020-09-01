#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 256

main(int argc, char **argv){
    int i;
    char str[BUFFER_SIZE];
    for (i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL){
            printf("Cannot open file. Check filename/location.\n");
            exit(1);
        }
        while ((fgets(str, BUFFER_SIZE, fp)) != NULL){
            puts(str);
        }
        fclose(fp);
    }
    return 0;
}