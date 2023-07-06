#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

// Definição da estrutura de um nó da árvore
typedef struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;


No *buscarChave(No *, int);
void percorrerEmOrdem(No* );
No *inserirNo(No *, int);
No *criarNo(int);


// Função para criar um novo nó
No *criarNo(int chave)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um nó na árvore
No *inserirNo(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return criarNo(chave);
    }

    if (chave < raiz->chave)
    {
        raiz->esquerda = inserirNo(raiz->esquerda, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->direita = inserirNo(raiz->direita, chave);
    }

    return raiz;
}

// Função para percorrer a árvore em ordem (esquerda, raiz, direita)
void percorrerEmOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

// Função para buscar uma chave na árvore
No *buscarChave(No *raiz, int chave)
{
    if (raiz == NULL || raiz->chave == chave)
    {
        return raiz;
    }

    if (chave < raiz->chave)
    {
        return buscarChave(raiz->esquerda, chave);
    }
    else
    {
        return buscarChave(raiz->direita, chave);
    }
}