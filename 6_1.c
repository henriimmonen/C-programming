#include <stdio.h>
#include <stdlib.h>
typedef struct yksittainen {
	int luku;
	struct yksittainen *pSeuraava;
} YKSITTAINEN;

int main(void){
	YKSITTAINEN *pAlku = NULL, *pLoppu = NULL;
	YKSITTAINEN *pUusi, *ptr, *apu;
	int iLuku;
	printf("Anna listan luvut.\n");
	while(1){
		printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
		scanf("%d", &iLuku);
		if(iLuku > 0){
            if ((pUusi = (YKSITTAINEN*)malloc(sizeof(YKSITTAINEN))) == NULL ){
 			    perror("Muistin varaus epäonnistui");
 			    exit(1);
		    }
			pUusi->luku=iLuku;
			pUusi->pSeuraava=NULL;
			iLuku = 0;
			if (pAlku == NULL){
				pAlku = pUusi;
				pLoppu = pUusi;
			} else {
				pLoppu->pSeuraava = pUusi;
 				pLoppu = pUusi;
			}
		} else {
			printf("Listassa on seuraavat luvut: ");
			ptr = pAlku;
			apu = ptr;
			while (ptr != NULL) {
 				printf("%d ", ptr->luku);
				apu = ptr;
 				ptr = ptr->pSeuraava;
				free(apu);
			}
			printf("\n");
			printf("Kiitos ohjelman käytöstä.\n");
            break;
		}
	}
	return 0;
}