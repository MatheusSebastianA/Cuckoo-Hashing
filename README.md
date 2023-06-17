# Cuckoo-Hashing
Aluno: Matheus Sebastian Alencar de Carvalho
GRR: 20220065

Objetivo:  Implementar a inclusão e exclusão de valores em tabela hash de endreçamento aberto.

Para a implementação do Cuckoo-Hashing, foi utilizado um vetor com 22 "nodos" para representar as duas tabelas Hash de 11 elementos cada. Cada nodo é uma estrutura que apresenta uma chave, um inteiro representando "NULL" e um inteiro representando "excluído". Foi utilizado um vetor fixo dado que teremos duas tabelas com 11 posições, no máximo cada, portanto não é necessário a utilização de alocação dinâmica. A inicialização desse vetor é colocando todos os nodos com valor "-1", já que não teremos números negativos, nulo = 1 e excluido = 0.

O algoritmo de Hashing1(h1) funciona com uma simples função de mod 11, no qual o resultado representa a posição de uma chave na tabela. Caso tenha colisão, é necessário utilizar a função de Hashing2(h2), a qual utiliza de piso e outra funções demonstradas na especificação do trabalho. Foi necessário produzir uma prórpia função de floor, uma vez que o compilador estava reclamando mesmo ao importar a biblioteca math.h. 

A função de busca é feita analisando 3 casos diferentes:

    .Posição recebe o resultado da função h1 da chave em procura, caso o "nodo" na posição seja nulo, apenas retorna -1 (valor de verificação), pois o valor não existe. 
    .Posição recebe o resultado da função h1 da chave em procura, caso o "nodo" na posição tenha chave igual à procurada retorna em qual posição o valor foi encontrado no vetor/tabela hash.  
    .Posição recebe o resultado da função h1 da chave em procura, caso o "nodo" não seja nulo e não tenha a chave procurada, ela pode estar na segunda tabela. Posição recebe o resultado da função h2 da chave em procura + 11, já que temos apenas um vetor com 22 posições, onde a posição na tabela 2 é 11 + h2. Assim, verifica se a chave na posição da segunda tabela é igual à procurada, se for retorna a posição, se não retorna "-1".
  
  
