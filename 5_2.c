#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tarkistaSyote(char *luku){
	int aLuku = atoi(luku);
	if (aLuku <= 0){
		return 0;
	}
	return 1;
}
int* varaaMuisti(int koko) {
	int *pMuistilohko;
	if ((pMuistilohko = (int*)malloc(koko)) == NULL ){
 		perror("Muistin varaus epäonnistui.\n");
 		exit(1);
 	}
    return pMuistilohko;
	
}

void taytaTaulukko(int *osoite, int koko) {
    int i;
    printf("Taulukossa on tilaa %d alkiolle.\n", koko);
    for (i=0;i<koko;i++){
        printf("Anna %d. luku: ", i+1);
        scanf("%d", &osoite[i]);
    }
}
void tulostaTaulukko(int *osoite, int koko) {
    int i;
    printf("Taulukossa on luvut: ");
    for (i=0;i<koko;i++){
        printf("%d ", osoite[i]);
    }
    printf("\n");
}
void vapautaMuisti(int *osoite){
    free(osoite);
}
int main(int argc, char* argv[]){
    int muistin_maara;
    int tulos;
    int *osoite;
	if (argc == 1){
		printf("Et antanut taulukon kokoa.\n");
        exit(0);
	}
    int koko = atoi(argv[1]);
	tulos = tarkistaSyote(argv[1]);
    if (tulos == 0){
        printf("Parametri ei ollut positiivinen kokonaisluku.\n");
        exit(0);
    }
	muistin_maara = koko * sizeof(int);
	osoite = varaaMuisti(muistin_maara);
    taytaTaulukko(osoite,koko);
    tulostaTaulukko(osoite,koko);
    vapautaMuisti(osoite);
    return 0;
}