#include <stdio.h>

#define CAPACIDADE 100

typedef struct {
int dados[CAPACIDADE];
int quantidade;
} Lista;

int initLista(Lista *lista);
int listaCheia(Lista *lista);
int listaVazia(Lista *lista);
void printLista(Lista *lista);

int addElem(Lista *lista, int elemento);
int buscarElem(Lista *lista, int valor);
int insertElem(Lista *lista, int elemento, int posicao);
int removeElem(Lista *lista, int posicao);


int main(){
    Lista lista;
    int retorno;
    int valor1;
    int valor2;

    printf("Inicializando lista...\n");
    initLista(&lista);
    printf("Lista inicializada!\n\n");



    printf("Verificando se a lista esta cheia ou vazia:\n");
    printf("Lista cheia: %d\n", listaCheia(&lista));
    printf("Lista vazia: %d\n\n", listaVazia(&lista));



    printf("Imprimindo lista...\n");
    printLista(&lista);
    printf("A lista tem %d/%d elementos\n\n", lista.quantidade, CAPACIDADE);



    printf("Adicionando de 1 a 5 na lista...\n");
    for (int i = 1; i < 6; i++){
        addElem(&lista, i);
        printf("Adicionado %d\n", i);
    }

    printf("\nImprimindo lista...\n");
    printLista(&lista);
    printf("\n");



    printf("Escolha um valor para ser buscado na lista:");
    scanf("%d", &valor1);
    printf("Buscando o valor %d na lista...\n", valor1);
    retorno = buscarElem(&lista, valor1);
    if (retorno == -1) printf("Valor nao encontrado\n\n");
    else printf("Elemento de valor %d esta na posicao %d\n\n", valor1, retorno);



    printf("Escolha um valor para ser inserido na lista:");
    scanf("%d", &valor1);
    printf("Escolha a posicao para inserir o valor (0-%d):", lista.quantidade);
    scanf("%d", &valor2);
    if (insertElem(&lista, valor1, valor2)) printf("Inserido valor %d na posicao %d\n", valor1, valor2);
    printf("\nImprimindo nova lista:\n");
    printLista(&lista);
    printf("A lista tem %d/%d elementos\n\n", lista.quantidade, CAPACIDADE);


    printf("Escolha a posicao para remover seu valor:");
    scanf("%d", &valor1);
    removeElem(&lista, valor1);
    printf("Removido o elemento na posicao %d\n\n", valor1);

    printf("Imprimindo nova lista:\n");
    printLista(&lista);
    printf("A lista tem %d/%d elementos\n\n", lista.quantidade, CAPACIDADE);

    return 0;
}

int initLista(Lista *lista){
    lista->quantidade = 0;
}

int listaCheia(Lista *lista){
    return lista->quantidade == CAPACIDADE;
}

int listaVazia(Lista *lista){
    return lista->quantidade == 0;
}

void printLista(Lista *lista){
    for (int i = 0; i < lista->quantidade; i++){
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int addElem(Lista *lista, int elemento){
    if (listaCheia(lista)){
        printf("Lista cheia");
        return 0;
    }

    lista->dados[lista->quantidade] = elemento;
    lista->quantidade++;
    return 1;
}

int buscarElem(Lista *lista, int valor){
    for (int i = 0; i < CAPACIDADE; i++){
        if (lista->dados[i] == valor) return i;
    }

    return -1;
}

int insertElem(Lista *lista, int elemento, int posicao){
    if (posicao > lista->quantidade){
        printf("Posicao deve ser entre 0 e %d\n", lista->quantidade);
        return 0;
    }

    for (int i = lista->quantidade; i > posicao; i--){
        lista->dados[i] = lista->dados[i-1];
    }
    lista->quantidade++;

    lista->dados[posicao] = elemento;
    return 1;
}

int removeElem(Lista *lista, int posicao){
    if (posicao > CAPACIDADE){
        printf("Posicao deve ser entre 0 e %d", CAPACIDADE);
        return 1;
    }

    for (int i = posicao; i < lista->quantidade; i++){
        lista->dados[i] = lista->dados[i+1];
    }

    lista->quantidade--;
}