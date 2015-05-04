#include <stdio.h>
#include <stdlib.h>

#define STR_MAXLEN 50

int main(int argc, char** argv) {
    char stringa[STR_MAXLEN+1];
    int scelta;
    
    printf("Inserisci una stringa (max %d, [fine] per terminare): ", STR_MAXLEN);
    scanf("%[^\n]", stringa);
    
    while(strcmp(stringa, "[fine]")) {
        printf("Dove vuoi scrivere? (1: stdout - 2: stderr) ");
        scanf("%d", &scelta);
        
        switch(scelta) {
            case 1:
                fprintf(stdout, "stdout: %s\n", stringa);
                break;
            case 2:
            default:
                fprintf(stderr, "stderr: %s\n", stringa);
                // Scrivo su stderr per qualsiasi valore diverso da 1
        }
        
        printf("Inserisci una stringa (max %d, [fine] per terminare): ", STR_MAXLEN);
        scanf("\n%[^\n]", stringa);
        /* E' necessario che inizi la stringa che specifica la modalità di lettura
         * di scanf con la sequenza \n che identifica il ritorno a capo.
         * Se così non facessi, il ritorno a capo specificato per il precedente
         * inserimento della scelta sarebbe utilizzato e non sarebbe letta alcuna stringa */
    }

    return (EXIT_SUCCESS);
}

