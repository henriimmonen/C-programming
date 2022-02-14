#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct henkilo {
    char cNimi[30];
    int aIka;
};
typedef struct henkilo HENKILO;
int main(void) {
    HENKILO hlo1;
    HENKILO hlo2;
    printf("Anna ensimmäisen henkilön etunimi: ");
    scanf("%s", hlo1.cNimi);
    printf("Anna ensimmäisen henkilön ikä: ");
    scanf("%d", &hlo1.aIka);
    printf("Anna toisen henkilön etunimi: ");
    scanf("%s", hlo2.cNimi);
    printf("Anna toisen henkilön ikä: ");
    scanf("%d", &hlo2.aIka); 
    if (hlo1.aIka != hlo2.aIka && hlo1.cNimi != hlo2.cNimi) {
        printf("Annetut tiedot eivät ole samoja.\n");
        HENKILO *hlo3;
        int muistin_maara = sizeof(HENKILO);
        if ((hlo3 = (HENKILO*)malloc(muistin_maara)) == NULL) {
            perror("Muistinvaraus epäonnistui.\n");
            exit(1);
        }
        strcpy(hlo3->cNimi, hlo1.cNimi);
        hlo3->aIka = hlo1.aIka;
        if (hlo3->aIka == hlo1.aIka && strcmp(hlo3->cNimi, hlo1.cNimi)== 0){
            printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");
            if (hlo3 != &hlo1){
                printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
                printf("Kiitos ohjelman käytöstä.\n");
            }
        }
        free(hlo3);
        return 0;
    } else {
        exit(1);
    }
    return 0;

}