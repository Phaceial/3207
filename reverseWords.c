#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256
void reverseInput (char string[]);

int main(int argc, char **argv){
    char string[BUFFER_SIZE];
    FILE *fp = NULL;

    if (argc == 1){
        printf("Enter text you would like reversed.\n");
        fgets(string, sizeof(string), stdin);
        reverseInput(string);
    }
    else if (argc == 2){
        fp = fopen(argv[1], "r");

        if (fp == NULL){
                fprintf(stderr,"Cannot open file. Check filename/location.\n");
                exit(1);
            }
        while((fgets(string, sizeof(string), fp)) != NULL){
            reverseInput(string);
        }
        fclose(fp);
    }
    // }else if (argc == 3){
    //     strncpy(search, argv[1], sizeof(argv[1]));
    //     for (i = 2; i < argc; i++){
    //         fp = fopen(argv[i], "r");
    //         if (fp == NULL){
    //             fprintf(stderr,"Cannot open file. Check filename/location.\n");
    //             exit(1);
    //         }
    //         while ((fgets(str, BUFFER_SIZE, fp)) != NULL){
            
    //         }
    //         fclose(fp);
    //     }
    else {
        fprintf(stderr, "Minimum number of arguments is 1 and maximum is 3");
        exit(1);
    }
    exit(0); 
}

void reverseInput(char string[]){
    int length = strlen(string);
    int i;
    string[strlen(string)-1] = '\0';

      for (i = strlen(string)-1; i >= 0; i--){
        if(string[i] == ' ') {
            string[i] = '\0';
            printf("%s ", &(string[i]) + 1);
        }
    }
      printf("%s\n", string);
}