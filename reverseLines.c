#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256
void reverseLines(int argc, char **argv, FILE *stream);

int main(int argc, char **argv){
    FILE *stream = NULL;

    if(argc == 1){
        printf("Enter text you would like reversed. Press CTRL + D to end input.\n");
        reverseLines(argc, argv, stdin);
    } else if(argc >= 2){
        stream = fopen(argv[1], "r");
        if(stream == NULL){
            fprintf(stderr,"Cannot open file. Check filename/location.\n");
            exit(1);
            }
        reverseLines(argc, argv, stream);
    }else if (argc > 3){
        fprintf(stderr,"The minimum arguments is 1 and the maximum arguments are 3\n");
        exit(1);
        }
    exit(0);
}

void reverseLines(int argc, char **argv, FILE *stream){
    char *current = NULL;
    char **lines = NULL;
    char **newlines = NULL;
    size_t buffer;
    size_t counter = 0;
    int i;

    while(getline(&current, &buffer, stream) >= 0){
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
    fclose(stream);

    if(argc <= 2){
        for(i = counter - 1; i >=0; i--)
            fprintf(stdout, "%s", lines[i]);
            
    }else if (argc == 3){
        if(strcmp(argv[1], argv[2]) == 0){
            fprintf(stderr, "Output file cannot be same as input\n");
            exit(1);
        }
        FILE *fWrite = fopen(argv[2], "w");

        for(i = counter - 1; i >=0; i--)
            fprintf(fWrite, "%s", lines[i]);
            
        fclose(fWrite);
    }
}