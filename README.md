# Cuckoo-Hashing
Aluno: Matheus Sebastian Alencar de Carvalho
GRR: 20220065

Para a implementação do Cuckoo-Hashing, foi utilizado um vetor com 22 "nodos". Cada nodo é uma estrutura que apresenta uma chave, um inteiro representando "NULL" e um inteiro representando "excluído". Foi utilizado um vetor fixo dado que teremos duas tabelas com 11 posições no máximo cada, portanto não seria necessário a utilização de alocação dinâmica. A inicialização desse vetor é colocando todos os nodos com valor "-1", já que não teremos números negativos, nulo = 1 e excluido = 0.

O algoritmo de Hashing1(h1) funciona com uma simples função de mod 11, no qual o resultado representa a posição de uma chave na tabela. Caso tenha colisão, é necessário utilizar a função de Hashing2(h2), a qual utiliza de piso e outra funções demonstradas na especificação do trabalho. Foi necessário produzir uma prórpia função de floor, uma vez que o compilador estava reclamando mesmo ao importar a biblioteca math.h. 

A função de busca é feita analisando o resultado da função h1 da chave em procura, caso o "nodo" na posição seja nulo, apenas retorna, pois o valor não existe. 
