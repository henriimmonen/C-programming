#include <stdio.h>
#include <stdlib.h>
void tulostaTaulukko(int *osoite, int iKoko){
	int i;
	if (iKoko > 0){
		printf("Taulukon alkiot ovat: ");
		for (i=0;i<iKoko;i++){
			printf("%d ",osoite[i]);
		}
		printf("\n");
	} else {
		printf("Taulukko on tyhjä.\n");
	}
}

int* varaaMuisti(int koko) {
	int *pMuistilohko;
	if ((pMuistilohko = (int*)malloc(koko)) == NULL ){
 		perror("Muistin varaus epäonnistui.\n");
 		exit(1);
 	}
    return pMuistilohko;
	
}

int main (void){
	int iValinta;
	int iKoko = 0;
	int *osoite;
	int muistin_maara;
	muistin_maara = iKoko * sizeof(int);
	osoite = varaaMuisti(muistin_maara);
	while (1){
		printf("1) Tulosta taulukon alkiot\n");
		printf("2) Muuta taulukon kokoa\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		scanf("%d", &iValinta);
		if (iValinta == 1){
			tulostaTaulukko(osoite, iKoko);
		}
		
		else if (iValinta == 2){
            int i;
			int iUusiKoko;
			printf("Anna taulukon uusi koko: ");
			scanf("%d", &iUusiKoko);
			if (iUusiKoko < 0){
				printf("Taulukon koko ei voi olla negatiivinen.\n");
                continue;	
			} else {
				iKoko = iUusiKoko;
				muistin_maara = iKoko * sizeof(int);
				osoite = varaaMuisti(muistin_maara);
				for (i=0;i<iKoko;i++){
					osoite[i] = i;
				}
			}
		}
		
		else if (iValinta == 0) {
			free(osoite);
			printf("Kiitos ohjelman käytöstä.\n");
			break;
		} else {
			printf("Tuntematon valinta, yritä uudestaan.\n");
	    }
    }
    return 0;
}