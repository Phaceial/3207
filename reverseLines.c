#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

int main(int argc, char**argv){
    FILE *fRead = NULL;
    char string[BUFFER_SIZE];
    char *current = NULL;
    char **lines = NULL;
    char **newlines = NULL;
    size_t buffer;
    size_t counter = 0;
    int i;

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
        while(getline(&current, &buffer, fRead) >= 0){
            newlines = realloc(lines, (counter+1) * sizeof(*lines));
            if(newlines == NULL){
                fprintf(stderr,"Memory has failed to allocate");
                exit(1);
            } else lines = newlines;
            lines[counter] = current;
            current = NULL;
            counter++;
        }
        free(current);
        fclose(fRead);

        for(i = counter - 1; i >=0; i--){
            printf("%s", lines[i]);
        }

    }else if(argc == 3){
        if(strcmp(argv[1], argv[2]) == 0){
            fprintf(stderr, "Output file is the same as input\n");
            exit(1);
        }
        FILE *fWrite = fopen(argv[2], "w");
        fRead = fopen(argv[1], "r");
        while(getline(&current, &buffer, fRead) >= 0){
            fprintf(fWrite, "%s", current);
        }
        fclose(fRead);
        fclose(fWrite);
        free(current);

    } else{
        fprintf(stderr,"The minimum arguments is 1 and the maximum arguments are 3\n");
        exit(1);
    }
exit(0);
}