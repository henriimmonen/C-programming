#include <stdio.h>
#include <stdlib.h>

typedef struct yksittainen {
	int luku;
	struct yksittainen *pSeuraava;
} YKSITTAINEN;

void tulostaLista(YKSITTAINEN *pAlku){
	YKSITTAINEN *ptr;
	printf("Listassa on seuraavat luvut: \n");
	ptr = pAlku;
	while (ptr != NULL) {
 		printf("%d ", ptr->luku);
		ptr = ptr->pSeuraava;
    }
    printf("\n");
}

void tyhjennaLista(YKSITTAINEN *pAlku) {
	YKSITTAINEN *ptr, *pApu;
	ptr = pAlku;
	while(ptr != NULL) {
		pApu = ptr;
		ptr = ptr->pSeuraava;
		free(pApu);
	}
}

YKSITTAINEN* taytaLista(int koko) {
    int i;
    YKSITTAINEN *pAlku = NULL, *pLoppu = NULL;
	YKSITTAINEN *pUusi;
    for (i=0;i<koko;i++) {
        if ((pUusi = (YKSITTAINEN*)malloc(sizeof(YKSITTAINEN))) == NULL ){
 			    perror("Muistin varaus epäonnistui");
 			    exit(1);
		}
		pUusi->luku=i;
		pUusi->pSeuraava=NULL;
		if (pAlku == NULL){
			pAlku = pUusi;
			pLoppu = pUusi;
		} else {
			pLoppu->pSeuraava = pUusi;
 			pLoppu = pUusi;
		}
    }
    return pAlku;
}

int main (void){
    YKSITTAINEN *pAlku = NULL;
	int iValinta;
	int iKoko = 0;
	while (1){
		printf("1) Tulosta listan alkiot\n");
		printf("2) Muuta listan pituutta\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		scanf("%d", &iValinta);
		if (iValinta == 1){
            if (iKoko == 0) {
                printf("Lista on tyhjä.\n");
            } else {
                tulostaLista(pAlku);
            }
		}

		else if (iValinta == 2){
			int iUusiKoko;
			printf("Anna listan uusi pituus: ");
			scanf("%d", &iUusiKoko);
			if (iUusiKoko < 0){
				printf("Listan pituus ei voi olla negatiivinen.\n");
            } else if (iUusiKoko == 0){
                iKoko = iUusiKoko;
			} else {
				iKoko = iUusiKoko;
                pAlku = taytaLista(iKoko);
			}

		} else if (iValinta == 0) {
			printf("Kiitos ohjelman käytöstä.\n");
			tyhjennaLista(pAlku);
			break;
		} else {
			printf("Tuntematon valinta, yritä uudestaan.\n");
	    }
    }
    return 0;
}