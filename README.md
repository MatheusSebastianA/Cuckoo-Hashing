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
  
A inclusão é feita com a utilização de duas funções, h1 e h2, na qual o parâmetro é apenas a chave e o retorno é o resultado da posição no vetor/tabela hash. É verificado se o valor já não existe para que não haja duplicatas nas tabelas. Para a inserção, existem dois casos:

    . Se a posição que a função h1 retornou está vazia ou excluída, apenas insere a chave nessa posição.
    . Se a posição que a função h1 retornou tem algum valor, é chamada a função h2 para a chave que está ocupando aquela posição e será inserida na posição de retorno da h2 + 11, já que com vetores de 22 posições um valor na segunda tabela é h2 + 11.
    
A remoção é feita simplemesnte utilizando o retorno da função busca, se o retorno for -1, apenas sai, pois esse valor não existe na tabela. Se não, vai para a posição que a função de busca retornou e atribui valro "-1" para a chave, excluido = 1 e nulo = 0. 

Para a impressão, de acordo com as especificações do trabalho, foi necessário fazer dois vetores auxiliares, um para guardar em ordem crescente os valores e outro para guardar as posições dos valores em ordem. Para isso, não foi feita uma cópia da tabela hash, visto que não há necessidade de salvá-la. Na inserção em ordem temos que buscar o menor da tabela hash, remover da tabela e inserir no vetor ordenado. Assim, perdemos a construção exata da tabela hash para essa impressão, mas se fosse necessário salvar a tabela teria que ser feito uma cópia completa em outro vetor com a mesma estrutura da tabela. Como não é necessário acessar a tabela após uma rodagem do programa, perdê-la não acarreta em nenhum problema para as especificações desse trabalho.  
