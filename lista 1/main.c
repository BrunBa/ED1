// // Experimentos

// #include <stdio.h>

// typedef struct {
//     int matricula;
//     char nome[50];
//     float nota1;
//     float nota2;
// } Aluno;

// int maior(int num1, int num2);

// int main(){
//     int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i = 0; i < 10; i++){
//         printf("%d", nums[i]);
//     }

//     int matriz[3][4] = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12}
//     };
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 4; j++){
//             printf("%d ", matriz[i][j]);
//         }
//         printf("\n");
//     }

//     Aluno alunos[40];
// }

// // Problema 1

// #include <stdio.h>

// int maior_tres(int a, int b, int c) {
//     int max = a;
//     if (b > max) max = b;
//     if (c > max) max = c;
//     return max;
// }

// int menor_tres(int a, int b, int c) {
//     int min = a;
//     if (b < min) min = b;
//     if (c < min) min = c;
//     return min;
// }

// float media_tres(int a, int b, int c) {
//     return (a + b + c) / 3.0;
// }

// int main() {
//     int v1, v2, v3;

//     printf("Digite tres numeros inteiros: ");
//     scanf("%d %d %d", &v1, &v2, &v3);

//     printf("Maior valor: %d\n", maior_tres(v1, v2, v3));
//     printf("Menor valor: %d\n", menor_tres(v1, v2, v3));
//     printf("Media aritmetica: %.2f\n", media_tres(v1, v2, v3));

//     return 0;
// }

// // Problema 2

// #include <stdio.h>

// #define CAPACIDADE 100

// int buscar_elemento(int vet[], int qtd, int valor){
//     for (int i = 0; i < qtd; i++){
//         if (vet[i] == valor)
//             return i;
//     }

//     return -1;
// }

// int inserir_elemento(int vet[], int *qtd, int capacidade, int valor, int pos){
//     if (*qtd >= capacidade || pos < 0 || pos > *qtd)
//         return 0;

//     for (int i = *qtd; i > pos; i--)
//     {
//         vet[i] = vet[i - 1];
//     }
//     vet[pos] = valor;

//     (*qtd)++;
//     return 1;
// }

// int remover_elemento(int vet[], int *qtd, int pos){
//     if (pos < 0 || pos >= *qtd) return 0;

//     for (int i = pos; i < *qtd - 1; i++){
//         vet[i] = vet[i + 1];
//     }

//     (*qtd)--;
//     return 1;
// }

// void imprimir_vetor(int vet[], int qtd){
//     printf("Vetor (%d elementos): ", qtd);

//     for (int i = 0; i < qtd; i++){
//         printf("%d ", vet[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int vet[CAPACIDADE];
//     int qtd = 0, n;

//     printf("Digite a quantidade de elementos iniciais (max %d): ", CAPACIDADE);
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++){
//         printf("Elemento [%d]: ", i);
//         scanf("%d", &vet[i]);
//     }

//     qtd = n;

//     imprimir_vetor(vet, qtd);

//     int busca;

//     printf("\nDigite um valor para buscar: ");
//     scanf("%d", &busca);

//     int pos = buscar_elemento(vet, qtd, busca);

//     if (pos != -1) printf("Valor encontrado na posicao %d.\n", pos);
//     else printf("Valor nao encontrado.\n");

//     int elem, pos_ins;

//     printf("\nDigite um valor e a posicao para insercao: ");
//     scanf("%d %d", &elem, &pos_ins);

//     if (inserir_elemento(vet, &qtd, CAPACIDADE, elem, pos_ins)){
//         printf("Elemento inserido com sucesso!\n");
//         imprimir_vetor(vet, qtd);
//     } else {
//         printf("Falha ao inserir elemento.\n");
//     }

//     int pos_rem;

//     printf("\nDigite a posicao para remocao: ");
//     scanf("%d", &pos_rem);

//     if (remover_elemento(vet, &qtd, pos_rem)){
//         printf("Elemento removido com sucesso!\n");
//         imprimir_vetor(vet, qtd);
//     } else {
//         printf("Posicao invalida.\n");
//     }

//     return 0;
// }


// // Problema 3

// #include <stdio.h>

// #define MAX 50

// void encontrar_maior(int mat[MAX][MAX], int n, int m) {
//     int maior = mat[0][0];
//     int lin = 0, col = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (mat[i][j] > maior) {
//                 maior = mat[i][j];
//                 lin = i;
//                 col = j;
//             }
//         }
//     }
//     printf("Maior elemento: %d na posicao [%d][%d]\n", maior, lin, col);
// }

// void somar_linhas_colunas(int mat[MAX][MAX], int n, int m) {
//     for (int i = 0; i < n; i++) {
//         int soma_lin = 0;
//         for (int j = 0; j < m; j++) soma_lin += mat[i][j];
//         printf("Soma da linha %d: %d\n", i, soma_lin);
//     }

//     for (int j = 0; j < m; j++) {
//         int soma_col = 0;
//         for (int i = 0; i < n; i++) soma_col += mat[i][j];
//         printf("Soma da coluna %d: %d\n", j, soma_col);
//     }
// }

// float calcular_media_matriz(int mat[MAX][MAX], int n, int m) {
//     int soma = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             soma += mat[i][j];
//         }
//     }
//     return (float)soma / (n * m);
// }

// int contar_acima_media(int mat[MAX][MAX], int n, int m, float media) {
//     int cont = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (mat[i][j] > media) cont++;
//         }
//     }
//     return cont;
// }

// int main() {
//     int mat[MAX][MAX], n, m;

//     printf("Digite as dimensoes N e M da matriz: ");
//     scanf("%d %d", &n, &m);

//     printf("Digite os elementos da matriz:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             scanf("%d", &mat[i][j]);
//         }
//     }

//     printf("\nResultados\n");
//     encontrar_maior(mat, n, m);
//     somar_linhas_colunas(mat, n, m);
    
//     float media = calcular_media_matriz(mat, n, m);
//     printf("Media de todos os elementos: %.2f\n", media);
//     printf("Elementos acima da media: %d\n", contar_acima_media(mat, n, m, media));

//     return 0;
// }


// // Problema 4

// #include <stdio.h>

// #define MAX_ALUNOS 100

// typedef struct {
//     int matricula;
//     char nome[50];
//     float nota1;
//     float nota2;
// } Aluno;

// float calcular_media_aluno(Aluno a) {
//     return (a.nota1 + a.nota2) / 2.0;
// }

// int localizar_aluno(Aluno alunos[], int n, int mat) {
//     for (int i = 0; i < n; i++) {
//         if (alunos[i].matricula == mat) return i;
//     }
//     return -1;
// }

// int aluno_maior_media(Aluno alunos[], int n) {
//     int idx_maior = 0;
//     float maior_media = calcular_media_aluno(alunos[0]);

//     for (int i = 1; i < n; i++) {
//         float media = calcular_media_aluno(alunos[i]);
//         if (media > maior_media) {
//             maior_media = media;
//             idx_maior = i;
//         }
//     }
//     return idx_maior;
// }

// void imprimir_todos_alunos(Aluno alunos[], int n) {
//     printf("\n--- Relatorio de Alunos ---\n");
//     for (int i = 0; i < n; i++) {
//         printf("Matricula: %d | Nome: %-15s | Media: %.2f\n", 
//                alunos[i].matricula, alunos[i].nome, calcular_media_aluno(alunos[i]));
//     }
// }

// int main() {
//     Aluno alunos[MAX_ALUNOS];
//     int n;

//     printf("Digite o numero de alunos: ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         printf("\nAluno %d:\n", i + 1);
//         printf("Matricula: ");
//         scanf("%d", &alunos[i].matricula);
//         printf("Nome: ");
//         scanf(" %[^\n]", alunos[i].nome);
//         printf("Nota 1: ");
//         scanf("%f", &alunos[i].nota1);
//         printf("Nota 2: ");
//         scanf("%f", &alunos[i].nota2);
//     }

//     imprimir_todos_alunos(alunos, n);

//     int idx_top = aluno_maior_media(alunos, n);
//     printf("\nAluno com maior media: %s (Media: %.2f)\n", 
//            alunos[idx_top].nome, calcular_media_aluno(alunos[idx_top]));

//     int mat_busca;
//     printf("\nDigite uma matricula para buscar: ");
//     scanf("%d", &mat_busca);
//     int pos = localizar_aluno(alunos, n, mat_busca);
//     if (pos != -1) {
//         printf("Aluno encontrado: %s | Media: %.2f\n", 
//                alunos[pos].nome, calcular_media_aluno(alunos[pos]));
//     } else {
//         printf("Matricula nao encontrada.\n");
//     }

//     return 0;
// }


// // Desafio

// #include <stdio.h>

// #define MAX_ALUNOS 100
// #define MAX_AVALIACOES 10

// typedef struct {
//     int matricula;
//     char nome[50];
// } AlunoInfo;

// float media_final_aluno(float notas[][MAX_AVALIACOES], int idx_aluno, int m) {
//     float soma = 0;
//     for (int j = 0; j < m; j++) {
//         soma += notas[idx_aluno][j];
//     }
//     return soma / m;
// }

// float media_turma_avaliacao(float notas[][MAX_AVALIACOES], int n, int idx_aval) {
//     float soma = 0;
//     for (int i = 0; i < n; i++) {
//         soma += notas[i][idx_aval];
//     }
//     return soma / n;
// }

// int localizar_aluno_turma(AlunoInfo alunos[], int n, int matricula) {
//     for (int i = 0; i < n; i++) {
//         if (alunos[i].matricula == matricula) return i;
//     }
//     return -1;
// }

// int idx_maior_media_final(AlunoInfo alunos[], float notas[][MAX_AVALIACOES], int n, int m) {
//     int idx_maior = 0;
//     float maior = media_final_aluno(notas, 0, m);

//     for (int i = 1; i < n; i++) {
//         float med = media_final_aluno(notas, i, m);
//         if (med > maior) {
//             maior = med;
//             idx_maior = i;
//         }
//     }
//     return idx_maior;
// }

// int contar_aprovados(float notas[][MAX_AVALIACOES], int n, int m) {
//     int aprovados = 0;
//     for (int i = 0; i < n; i++) {
//         if (media_final_aluno(notas, i, m) >= 6.0f) {
//             aprovados++;
//         }
//     }
//     return aprovados;
// }

// int main() {
//     AlunoInfo alunos[MAX_ALUNOS];
//     float notas[MAX_ALUNOS][MAX_AVALIACOES];
//     int n, m;

//     printf("Quantidade de alunos (N): ");
//     scanf("%d", &n);
//     printf("Quantidade de avaliacoes (M): ");
//     scanf("%d", &m);

//     for (int i = 0; i < n; i++) {
//         printf("\n--- Dados do Aluno %d ---\n", i + 1);
//         printf("Matricula: ");
//         scanf("%d", &alunos[i].matricula);
//         printf("Nome: ");
//         scanf(" %[^\n]", alunos[i].nome);

//         for (int j = 0; j < m; j++) {
//             printf("Nota da avaliacao %d: ", j + 1);
//             scanf("%f", &notas[i][j]);
//         }
//     }

//     printf("\nRelatorio da Turma\n");

//     for (int j = 0; j < m; j++) {
//         printf("Media da turma na Avaliacao %d: %.2f\n", 
//                j + 1, media_turma_avaliacao(notas, n, j));
//     }

//     int top = idx_maior_media_final(alunos, notas, n, m);
//     printf("\nAluno com maior media final: %s (Matricula: %d) - Media: %.2f\n",
//            alunos[top].nome, alunos[top].matricula, media_final_aluno(notas, top, m));

//     printf("Alunos com media final >= 6.0: %d de %d\n", contar_aprovados(notas, n, m), n);

//     int mat_busca;
//     printf("\nDigite a matricula de um aluno para consultar: ");
//     scanf("%d", &mat_busca);
//     int pos = localizar_aluno_turma(alunos, n, mat_busca);
//     if (pos != -1) {
//         printf("Aluno: %s | Media Final: %.2f\n", 
//                alunos[pos].nome, media_final_aluno(notas, pos, m));
//     } else {
//         printf("Aluno nao encontrado.\n");
//     }

//     return 0;
// }