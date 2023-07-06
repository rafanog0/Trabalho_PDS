#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<math.h>

// Estrutura para representar um grafo direcionado
typedef struct Graph
{
    int numVertices;
    int **matrizAdj;
} Graph;

void liberarGrafo(Graph *);
void exibirMatrizAdj(Graph *);
void adicionarAresta(Graph *, int, int);
Graph *criarGrafo(int);



// Função para criar um novo grafo com n vértices
Graph *criarGrafo(int numVertices)
{
    Graph *grafo = (Graph *)malloc(sizeof(Graph));
    grafo->numVertices = numVertices;

    grafo->matrizAdj = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        grafo->matrizAdj[i] = (int *)calloc(numVertices, sizeof(int));
    }

    return grafo;
}

// Função para adicionar uma aresta direcionada entre dois vértices do grafo
void adicionarAresta(Graph *grafo, int origem, int destino)
{
    if (grafo == NULL || origem < 0 || origem >= grafo->numVertices || destino < 0 || destino >= grafo->numVertices)
    {
        return;
    }

    grafo->matrizAdj[origem][destino] = 1;
}

// Função para exibir a matriz de adjacência do grafo
void exibirMatrizAdj(Graph *grafo)
{
    if (grafo == NULL)
    {
        return;
    }

    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < grafo->numVertices; i++)
    {
        for (int j = 0; j < grafo->numVertices; j++)
        {
            printf("%d ", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória ocupada pelo grafo
void liberarGrafo(Graph *grafo)
{
    if (grafo == NULL)
    {
        return;
    }

    for (int i = 0; i < grafo->numVertices; i++)
    {
        free(grafo->matrizAdj[i]);
    }
    free(grafo->matrizAdj);
    free(grafo);
}