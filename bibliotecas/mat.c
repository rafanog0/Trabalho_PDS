#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



int ehPalindromo(char *);
void inverterString(char *);
int fatorial(int);
int ehPrimo(int);

// Função para verificar se um número é primo
int ehPrimo(int num)
{
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Função para calcular o fatorial de um número
int fatorial(int num)
{
    if (num == 0)
        return 1;

    int resultado = 1;
    for (int i = 1; i <= num; i++)
        resultado *= i;

    return resultado;
}

double calcularMedia(int numeros[], int tamanho)
{
    if (tamanho <= 0)
        return 0.0;

    int soma = 0;
    for (int i = 0; i < tamanho; i++)
    {
        soma += numeros[i];
    }

    return (double)soma / tamanho;
}

// Função para encontrar o maior número em um array
int encontrarMaior(int numeros[], int tamanho)
{
    if (tamanho <= 0)
        return 0;

    int maior = numeros[0];
    for (int i = 1; i < tamanho; i++)
    {
        if (numeros[i] > maior)
            maior = numeros[i];
    }

    return maior;
}

// Função para verificar se um número é par
int ehPar(int num)
{
    return num % 2 == 0;
}

// Função para calcular a potência de um número
int potencia(int base, int expoente)
{
    int resultado = 1;
    for (int i = 0; i < expoente; i++)
    {
        resultado *= base;
    }

    return resultado;
}