#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cuckoo_hashing.h"

int main(){
    int chave;
    char opcao;
    struct nodo hash[TAM];
    inicializa_hash(hash);

    while(!feof(stdin)){
        opcao = '\0';
        scanf(" %c %d", &opcao, &chave);

        if(opcao == 'i')
            insere_chave(chave, hash);
        
        else if(opcao == 'r')
            remove_chave(chave, hash);

        else if(opcao != '\0')
            return 1;
    } 
    
    imprime_hash(hash);

    return 0;
}
