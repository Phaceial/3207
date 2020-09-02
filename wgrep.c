#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

main(int argc, char **argv){
    int i;
    char str[BUFFER_SIZE];
    char search[BUFFER_SIZE];

    if (argc < 2){
        printf("Search term not provided\n");
        exit(1);
    }
    else if (argc == 2){
        strncpy(search, argv[1], sizeof(argv[1]));
        printf("Enter a String to search\n");
        fgets(str, sizeof(str), stdin);
        if (strstr(str, search)){
            puts(str);
        }
    }else{
        strncpy(search, argv[1], sizeof(argv[1]));
        for (i = 2; i < argc; i++){
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL){
                printf("Cannot open file. Check filename/location.\n");
                exit(1);
            }
            while ((fgets(str, BUFFER_SIZE, fp)) != NULL){
                if (strstr(str, search))
                    puts(str);
            }
            fclose(fp);
        }
        return 0;
    }
}