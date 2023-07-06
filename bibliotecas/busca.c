
void ordenacaoInsercao(int *, int);
void ordenacaoSelecao(int *, int);
int buscaBinaria(int *, int, int);
int buscaLinear(int *, int, int);

// Função de busca linear em um array
int buscaLinear(int array[], int tamanho, int elemento)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] == elemento)
        {
            return i;
        }
    }
    return -1; // Elemento não encontrado
}

// Função de busca binária em um array ordenado
int buscaBinaria(int array[], int tamanho, int elemento)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (array[meio] == elemento)
        {
            return meio;
        }

        if (array[meio] < elemento)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    return -1; // Elemento não encontrado
}

// Função de ordenação por seleção em um array
void ordenacaoSelecao(int array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int indiceMinimo = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[j] < array[indiceMinimo])
            {
                indiceMinimo = j;
            }
        }

        if (indiceMinimo != i)
        {
            int temp = array[i];
            array[i] = array[indiceMinimo];
            array[indiceMinimo] = temp;
        }
    }
}

// Função de ordenação por inserção em um array
void ordenacaoInsercao(int array[], int tamanho)
{
    for (int i = 1; i < tamanho; i++)
    {
        int chave = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > chave)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = chave;
    }
}
