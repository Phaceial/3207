#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024

void reverse (char string[]);

int main(int argc, char **argv){
    char str[BUFFER_SIZE];
    FILE *fp = NULL;


    if (argc == 1){
        fp = stdin;
        printf("Enter text you would like reversed.\n");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        reverse(str);
    }
    else if (argc == 2){
        fp = fopen(argv[1], "r");
        if (fp == NULL){
                fprintf(stderr,"Cannot open file. Check filename/location.\n");
                exit(1);
            }
        while ((fgets(str, BUFFER_SIZE, fp)) != NULL){
            reverse(str);
        }
        fclose(fp);
        
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
    } else {
        fprintf(stderr, "Minimum number of arguments is 1 and maximum is 3");
        exit(1);
    }
    exit(0); 
}

void reverse(char string[]){
    int length = strlen(string);
    int i = 0;
    string[strcspn(string, "\n")] = '\0';

    for (i = length - 1; i >= 0; i--){
        if(string[i] == ' '){
            string[i] = '\0';
            printf("%s ", &string[i] + 1);
        }
    }
    printf("%s\n", string);
}