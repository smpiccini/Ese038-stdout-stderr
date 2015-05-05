#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100

int main(int argc, char** argv) {
    char s[MAX_STRLEN+1];
    int a;
    
    printf("Inserire una stringa: ");
    scanf("%[^\n]", s);
    while (strcmp(s,"[fine]")!=0) {
        printf("1. Standard Output\n 2. Standard Error\n");
        printf("\nCome deve essere stampata la stringa?: ");
        scanf("%d", &a);
        switch(a) {
            case 1:
            printf("%s\n", s);
            break;
            case 2:
            fprintf(stderr, "%s\n", s);
            break;
            default:
                printf("Non riconosciuto.\n");
        }
        printf("Inserire un'altra stringa(inserire [fine] per uscire): ");
        scanf("\n%[^\n]s", s);
    }
    return (EXIT_SUCCESS);
}

