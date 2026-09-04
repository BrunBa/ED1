#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int quantidade;
} Lista;

// Exercício 1
void inicializar(Lista *lista);
int estaVazia(Lista lista);
int obterQuantidade(Lista lista);
void imprimir(Lista lista);

// Exercício 2
int inserirInicio(Lista *lista, int valor);
int inserirFinal(Lista *lista, int valor);

// Exercício 3
int buscar(Lista lista, int valor);

// Exercício 4
int remover(Lista *lista, int valor);

// Exercício 5
void liberar(Lista *lista);

int main() {
    printf("1.\n");
    Lista lista1;
    printf("2.\n");
    inicializar(&lista1);
    printf("3.\n");

    inserirInicio(&lista1, 10);
    printf("4.\n");
    inserirFinal(&lista1, 20);
    inserirFinal(&lista1, 30);
    inserirFinal(&lista1, 40);
    printf("4.\n");

    printf("Lista criada: ");
    imprimir(lista1);

    printf("Buscando valor na lista (30): ");
    if(buscar(lista1, 30)) printf("Encontrado\n");
    else printf("Nao encontrado\n");

    printf("Buscando valor na lista (99): ");
    if(buscar(lista1, 99)) printf("Encontrado\n");
    else printf("Nao encontrado\n");

    printf("Removendo valores:\n");

    printf("[INICIO]\n");
    printf("Removendo valor (10): ");
    remover(&lista1, 10);
    imprimir(lista1);

    printf("[INTERMEDIARIO]\n");
    printf("Removendo valor (30): ");
    remover(&lista1, 30);
    imprimir(lista1);

    printf("[FINAL]\n");
    printf("Removendo valor (40): ");
    remover(&lista1, 40);
    imprimir(lista1);

    printf("[AUSENTE]\n");
    printf("Removendo valor (39): ");
    remover(&lista1, 39);
    imprimir(lista1);

    printf("Liberando estrutura...\n");
    liberar(&lista1);
    if(estaVazia(lista1)) printf("Lista vazia");
    else printf("Lista nao esvaziou");
    
    return 0;
}

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->quantidade = 0;
}

int estaVazia(Lista lista) {
    return lista.inicio == NULL;
}

int obterQuantidade(Lista lista) {
    return lista.quantidade;
}

void imprimir(Lista lista) {
    No *atual = lista.inicio;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int inserirInicio(Lista *lista, int valor) {
    No *novo = malloc(sizeof *novo);
    if(novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = lista->inicio;

    lista->inicio = novo;
    lista->quantidade++;

    return 1;
}

int inserirFinal(Lista *lista, int valor) {
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) return 0;

    novo->valor = valor;
    novo->proximo = NULL;
    if(lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while(atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    lista->quantidade++;
    return 1;
}

int buscar(Lista lista, int valor) {
    No *atual = lista.inicio;

    while(atual != NULL) {
        if(atual->valor == valor) return 1;
        atual = atual->proximo;
    }

    return 0;
}

int remover(Lista *lista, int valor) {
    if (lista->inicio == NULL) {
        return 0;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;
    
    while(atual != NULL && atual->valor != valor ) {
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->quantidade--;
    return 1;
}

void liberar(Lista *lista) {
    if(lista->inicio == NULL) return;

    No *anterior = NULL;
    No *atual = lista->inicio;

    while(atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }

    lista->inicio = NULL;
    lista->quantidade = 0;
}
