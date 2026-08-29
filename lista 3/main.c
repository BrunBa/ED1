#include <stdio.h>
#include <stdlib.h>

int initVetor(int* vetor, int tamanho);
int printVetor(int* vetor, int tamanho);

int maior(int* vetor, int tamanho);
int menor(int* vetor, int tamanho);
float mediaVetor(int* vetor, int tamanho);
int maiorQueMedia(int* vetor, int tamanho);

typedef struct No{
    int valor;
    struct No *proximo;
} No;

int main(){
    // int tamanho;

    // printf("Digite o tamanho do vetor: ");
    // scanf("%d", &tamanho);

    // if (tamanho <= 0){
    //     printf("Tamanho do vetor deve ser maior que 0");
    //     return 1;
    // }

    // int *nums = (int*)malloc(tamanho * sizeof(int));

    // if(nums == NULL){
    //     printf("Memoria nao foi alocada\n");
    //     return 1;
    // }

    // initVetor(nums, tamanho);
    // printVetor(nums, tamanho);

    // printf("\nMaior valor do vetor: %d\n", maior(nums, tamanho));
    // printf("Menor valor do vetor: %d\n", menor(nums, tamanho));
    // printf("Media dos valores do vetor: %.2f\n", mediaVetor(nums, tamanho));
    // printf("Valores no vetor maiores que a media: %d\n", maiorQueMedia(nums, tamanho));

    // int novoTamanho;

    // printf("Digite um novo tamanho para o vetor:");
    // scanf("%d", &novoTamanho);

    // int *temp = nums;

    // nums = realloc(nums, novoTamanho * sizeof(int));

    // if(!nums){
    //     printf("Realocacao falhou\n");
    //     nums = temp;
    // }

    // if (novoTamanho > tamanho){
    //     for (int i = tamanho; i < novoTamanho; i++){
    //         printf("Valor para a posicao %d: ", i + 1);
    //         scanf("%d", &nums[i]);
    //     }
    // }

    // tamanho = novoTamanho;

    // printf("Novo vetor:\n");
    // printVetor(nums, tamanho);
    // printf("\n\n\n");

    // free(nums);

    printf("Alocando No com malloc...\n");

    No *no1 = (No *)malloc(sizeof(No));

    if (no1 == NULL){
        printf("Falha de alocação\n");
        return 1;
    }

    printf("Digite um inteiro (no1):");
    scanf("%d", &no1->valor);
    no1->proximo = NULL;

    printf("\nValor armazenado: %d\n", no1->valor);
    printf("Endereco do no: %p\n", (void *)no1);

    free(no1);

    No *no2 = (No *)malloc(sizeof(No));
    No *no3 = (No *)malloc(sizeof(No));
    No *no4 = (No *)malloc(sizeof(No));

    if(no2 == NULL || no3 == NULL || no4 == NULL){
        printf("Falha de alocacao\n");
        return 1;
    }

    no2->valor = 10;
    no3->valor = 20;
    no4->valor = 30;

    no2->proximo = no3;
    no3->proximo = no4;
    no4->proximo = NULL;

    printf("\nNos conectados:\n");
    printf("No 1: %d\n", no2->valor);
    printf("No 2: %d\n", no2->proximo->valor);
    printf("No 3: %d\n", no2->proximo->proximo->valor);

    free(no2);
    free(no3);
    free(no4);
}

int initVetor(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = i + 1;
    }
}

int printVetor(int* vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}

int maior(int* vetor, int tamanho){
    int maiorValor = 0;

    for (int i = 0; i < tamanho; i++){
        if (vetor[i] > maiorValor) maiorValor = vetor[i];
    }

    return maiorValor;
}

int menor(int* vetor, int tamanho){
    int menorValor = vetor[0];

    for (int i = 0; i < tamanho; i++){
        if (vetor[i] < menorValor) menorValor = vetor[i];
    }

    return menorValor;
}

float mediaVetor(int* vetor, int tamanho){
    float calculo;

    for (int i = 0; i < tamanho; i++){
        calculo += vetor[i];
    }

    return calculo/tamanho;
}

int maiorQueMedia(int* vetor, int tamanho){
    float media = mediaVetor(vetor, tamanho);
    int total = 0;

    for (int i = 0; i < tamanho; i++){
        if (vetor[i] > media) total++;
    }

    return total;
}

