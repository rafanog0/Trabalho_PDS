# Trabalho_PDS
Repositório voltado ao trabalho final da matéria de Processo de Desenvolvimento de Software



## Como Usar
Para usar o gerenciador de bibliotecas, basta ter a pasta "bibliotecas" no seu ambiente local e executar o arquivo "gerenciador.c".
Ao executar, o programa irá solicitar o nome do arquivo onde serão inseridas as funções desejadas (Caso tenha problemas ao abrir o arquivo, insira o path incluindo o nome).


É possível importar mais de uma biblioteca por execução do programa, mas devido a algumas particularidades da linguagem C, o ideal é não importar. Ou seja, caso queira adicionar mais de uma biblioteca, encerre o gerenciador e inicie-o novamente, de preferência.

## Documentação
No proprio programa há uma opção no menu de visualizar a documentação

## Bibliotecas Existentes
O gerenciador possui as seguintes bibliotecas de funções:

  -> Biblioteca Matemática

  -> Biblioteca de Listas

  -> Biblioteca de Árvores

  -> Biblioteca de Grafos

  -> Biblioteca de Manipulação de strings

  -> Biblioteca de Algoritmos de Busca e Ordenação

  ## "Warning"
  Caso esteja aparecendo algum "warning" no código cujo as funções foram importadas, basta mover o "#include" que foi adicionado ao código e move-lo para o cabeçalho do arquivo. Isso ocorre devido a limitações da linguagem C, pois para o gerenciador inserir diretamente no cabeçalho do programa há chances de sobrescrever algum código já existente.

  
