#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// Definição da estrutura de um nó da lista
typedef struct No
{
    int dado;
    struct No *prox;
} No;

void liberarLista(No **);
void removerNo(No **, int);
int buscarValor(No *, int);
int contarNos(No *);
void exibirLista(No *);
void inserirNoFinal(No **, int);
void inserirNoInicio(No **, int);
No *criarNo(int);


// Função para criar um novo nó
No *criarNo(int dado)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um nó no início da lista
void inserirNoInicio(No **cabeca, int dado)
{
    No *novoNo = criarNo(dado);
    novoNo->prox = *cabeca;
    *cabeca = novoNo;
}

// Função para inserir um nó no final da lista
void inserirNoFinal(No **cabeca, int dado)
{
    No *novoNo = criarNo(dado);

    if (*cabeca == NULL)
    {
        *cabeca = novoNo;
        return;
    }

    No *temp = *cabeca;
    while (temp->prox != NULL)
    {
        temp = temp->prox;
    }

    temp->prox = novoNo;
}

// Função para exibir a lista
void exibirLista(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    No *temp = cabeca;
    printf("Lista: ");
    while (temp != NULL)
    {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

// Função para contar o número de nós na lista
int contarNos(No *cabeca)
{
    int contador = 0;
    No *temp = cabeca;
    while (temp != NULL)
    {
        contador++;
        temp = temp->prox;
    }
    return contador;
}

// Função para buscar um valor na lista
int buscarValor(No *cabeca, int valor)
{
    int indice = 0;
    No *temp = cabeca;
    while (temp != NULL)
    {
        if (temp->dado == valor)
        {
            return indice;
        }
        indice++;
        temp = temp->prox;
    }
    return -1; // Valor não encontrado
}

// Função para remover um nó da lista
void removerNo(No **cabeca, int valor)
{
    if (*cabeca == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    No *temp = *cabeca;
    No *anterior = NULL;

    // Caso especial: nó a ser removido é o primeiro
    if (temp != NULL && temp->dado == valor)
    {
        *cabeca = temp->prox;
        free(temp);
        printf("Nó com valor %d removido da lista.\n", valor);
        return;
    }

    // Procura o nó a ser removido
    while (temp != NULL && temp->dado != valor)
    {
        anterior = temp;
        temp = temp->prox;
    }

    // Caso especial: nó não encontrado
    if (temp == NULL)
    {
        printf("Nó com valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Remove o nó
    anterior->prox = temp->prox;
    
}
// Função para liberar a memória ocupada pela lista
void liberarLista(No **cabeca)
{
    No *atual = *cabeca;
    No *proximo;

    while (atual != NULL)
    {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *cabeca = NULL;
}