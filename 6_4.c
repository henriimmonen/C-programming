#include <stdio.h>
#include <stdlib.h>

typedef struct yksittainen {
	int luku;
	struct yksittainen *pSeuraava;
} YKSITTAINEN;

void tulostaLista(YKSITTAINEN *pAlku){
	YKSITTAINEN *ptr;
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

YKSITTAINEN* taytaLista(int koko, int iViimeisin) {
    int i;
    YKSITTAINEN *pAlku = NULL, *pLoppu = NULL;
	YKSITTAINEN *pUusi;
    for (i=0;i<koko;i++) {
        if ((pUusi = (YKSITTAINEN*)malloc(sizeof(YKSITTAINEN))) == NULL ){
 			    perror("Muistin varaus epäonnistui");
 			    exit(1);
		}
		pUusi->luku=iViimeisin+i;
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
    int iViimeisin = 1;
    int iApu;
	int iValinta;
	int iKoko = 0;
	printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
	while (1){
		printf("1) Luo lista\n");
		printf("2) Lisää alkio listan loppuun\n");
        printf("3) Lisää alkio listan keskelle\n");
        printf("4) Tyhjennä lista\n");
        printf("5) Poista alkio listasta\n");
        printf("6) Tulosta lista\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		scanf("%d", &iValinta);

		if (iValinta == 1){
			printf("Anna listan pituus: ");
			scanf("%d", &iKoko);
			if (iKoko < 0){
                iKoko = 0;
				printf("Listan pituus ei voi olla negatiivinen.\n");
            } else if (iKoko == 0){
                continue;
			} else {
                if (iViimeisin == 1){
                    pAlku = taytaLista(iKoko, iViimeisin);
                    iViimeisin = iKoko + 1;
                } else {
                    pAlku = taytaLista(iKoko, iViimeisin);
                    iViimeisin = iKoko + iViimeisin;
                }
                tulostaLista(pAlku);
			}
        } else if (iValinta == 2){
            if (iKoko != 0){
                iApu = pAlku->luku;
                tyhjennaLista(pAlku);
                pAlku = NULL;
                iKoko++;
                pAlku = taytaLista(iKoko, iApu);
                iViimeisin++;
                tulostaLista(pAlku);
            } else {
                iKoko = 1;
                pAlku = taytaLista(iKoko, iViimeisin);
                tulostaLista(pAlku);
            }
            

        } else if (iValinta == 4){
            tyhjennaLista(pAlku);
            iKoko = 0;
            pAlku = NULL;
        } else if (iValinta == 6){
            if (iKoko == 0) {
                printf("\n");
            } else {
                tulostaLista(pAlku);
            }
		} else if (iValinta == 0) {
			printf("Kiitos ohjelman käytöstä.\n");
			break;
		} else {
			printf("Tuntematon valinta, yritä uudestaan.\n");
	    }
    }
    return 0;
}