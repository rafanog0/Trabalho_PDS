
//Declarando escopo das funções
int compararStrings(char *, char *);
void concatenarStrings(char *, char *);
void copiarString(char *, char *);
int calcularComprimento(char *);
int ehPalindromo(char *);
void inverterString(char *);



// Função para inverter uma string
void inverterString(char *str)
{
    if (str == NULL)
        return;

    int tamanho = 0;
    while (str[tamanho] != '\0')
        tamanho++;

    for (int i = 0; i < tamanho / 2; i++)
    {
        char temp = str[i];
        str[i] = str[tamanho - i - 1];
        str[tamanho - i - 1] = temp;
    }
}

// Função para verificar se uma string é um palíndromo
int ehPalindromo(char *str)
{
    if (str == NULL)
        return 0;

    int tamanho = 0;
    while (str[tamanho] != '\0')
        tamanho++;

    for (int i = 0; i < tamanho / 2; i++)
    {
        if (str[i] != str[tamanho - i - 1])
            return 0;
    }

    return 1;
}

// Função para calcular o comprimento de uma string
int calcularComprimento(char *str)
{
    int comprimento = 0;
    while (str[comprimento] != '\0')
    {
        comprimento++;
    }
    return comprimento;
}

// Função para copiar uma string para outra
void copiarString(char *destino, char *origem)
{
    int i = 0;
    while (origem[i] != '\0')
    {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

// Função para concatenar duas strings
void concatenarStrings(char *destino, char *origem)
{
    int tamanhoDestino = calcularComprimento(destino);
    int i = 0;
    while (origem[i] != '\0')
    {
        destino[tamanhoDestino + i] = origem[i];
        i++;
    }
    destino[tamanhoDestino + i] = '\0';
}

// Função para comparar duas strings
int compararStrings(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}
