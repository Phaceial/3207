#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 4096

int main(int argc, char**argv){
    FILE *fRead = NULL;
    char string[BUFFER_SIZE];

    if(argc == 1){
        printf("Enter text you would like reversed.\n");
        fgets(string, sizeof(string), stdin);
        printf("%s", string);

    } else if(argc == 2){
        fRead = fopen(argv[1], "r");

        if (fRead == NULL){
                fprintf(stderr,"Cannot open file. Check filename/location.\n");
                exit(1);
            }
        while((fgets(string, sizeof(string), fRead)) != NULL){
            puts(string);
        }
        fclose(fRead);

    }else if(argc == 3){
        if(strcmp(argv[1], argv[2]) == 0){
            fprintf(stderr, "Output file is the same as input");
        }
        FILE *fWrite = fopen(argv[2], "w");
        fRead = fopen(argv[1], "r");
        while((fgets(string, sizeof(string), fRead)) != NULL){
            fprintf(fWrite, "%s", string);
        }
        fclose(fRead);
        fclose(fWrite);

    } else{
        printf("The minimum arguments is 1 and the maximum arguments are 3");
    }
return 0;
}