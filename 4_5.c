#include <stdio.h>
#define koko 2
int main(void){
    int i,j;
    int matriisi1 [koko][koko];
    int matriisi2 [koko][koko];
    printf("Anna arvot yhteenlaskettaville matriiseille:\n");
    printf("Matriisin 1 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &matriisi1[0][0]);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &matriisi1[0][1]);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &matriisi1[1][0]);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &matriisi1[1][1]);
    printf("\n");
    printf("Matriisi 1:\n");
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf("%4d", matriisi1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matriisin 2 alkiot:\n");
    printf("Rivi 1 alkio 1: ");
    scanf("%d", &matriisi2[0][0]);
    printf("Rivi 1 alkio 2: ");
    scanf("%d", &matriisi2[0][1]);
    printf("Rivi 2 alkio 1: ");
    scanf("%d", &matriisi2[1][0]);
    printf("Rivi 2 alkio 2: ");
    scanf("%d", &matriisi2[1][1]);
    printf("\n");
    printf("Matriisi 2:\n");
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf("%4d", matriisi2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nSummamatriisi:\n");
    for (i=0;i<2;i++){
        for (j=0;j<2;j++){
            printf("%4d", matriisi1[i][j] + matriisi2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}