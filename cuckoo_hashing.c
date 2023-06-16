#include "cuckoo_hashing.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 22
#define MAX 11

double floor(double x){
    if (x >= 0) {
        return (double)((long)x);
    } else {
        double t = (double)((long)x - 1);
        return (t == x) ? x : t;
    }
}

void inicializa_hash(struct nodo hash[TAM]){
    for(int i = 0; i < TAM; i++){
        hash[i].chave = -1;
        hash[i].excluido = 0;
        hash[i].null = 1;
    }

    return;
}

int busca(int chave, struct nodo hash[TAM]){
    int pos = h1(chave);

    if(hash[pos].null == 1)
        return -1;

    if(hash[pos].chave == chave)
        return pos;
    
    if(hash[pos].excluido == 1 || hash[pos].null != 1){
        pos = h2(chave) + MAX;
        if(hash[pos].chave == chave)
            return pos;
    }

    return -1;
}

int h1(int chave){
    return (chave % MAX);
}

int h2(int chave){
    return floor(MAX * (chave * 0.9 - floor(chave * 0.9)));
}

void insere_chave(int chave, struct nodo hash[TAM]){
    int pos1 = h1(chave), pos2 = 0;

    if(hash[pos1].null == 1 || hash[pos1].excluido == 1){
        hash[pos1].chave = chave;
        hash[pos1].null = 0;
        hash[pos1].excluido = 0; 

        return;
    }

    if(hash[pos1].null == 0){
        if(chave == hash[pos1].chave)
            return;

        pos2 = h2(hash[pos1].chave) + MAX;
        hash[pos2].chave = hash[pos1].chave;
        hash[pos2].null = 0;
        hash[pos2].excluido = 0;

            
        hash[pos1].chave = chave;
        hash[pos1].null = 0;
        hash[pos1].excluido = 0;

        return;
    }
}

void remove_chave(int chave, struct nodo hash[TAM]){
    int pos = busca(chave, hash);

    if(pos == -1)
        return;

    hash[pos].chave = -1;
    hash[pos].excluido = 1;
    hash[pos].null = 0;


    return;
}

int menor_chave(struct nodo hash[TAM], int pos){
    return 1;
}

void imprime_hash(struct nodo hash[TAM]){
    int menor, pos_menor, i, pos, cont = 0;
    int vet_pos[TAM];
    struct nodo aux[TAM];
    inicializa_hash(aux);

    for(i = 0; i < TAM; i++){
        menor = -1;
        cont = 0;
        for(pos = 0; pos < TAM; pos++){
            if(hash[pos].null != 1 && hash[pos].excluido != 1){
                if(cont == 0 || menor > hash[pos].chave){
                    menor = hash[pos].chave;
                    pos_menor = pos;
                    cont++;
                }
            }
        }
        if(menor != -1){
            remove_chave(menor, hash);
            aux[i].chave = menor;
            aux[i].excluido = 0;
            aux[i].null = 0;
            vet_pos[i] = pos_menor;
        }
    }



    for(i = 0; i < TAM; i++){
        if(aux[i].null != 1 && aux[i].excluido != 1){
            printf("%d,", aux[i].chave);
            if(vet_pos[i] <= 10)
                printf("T1,%d\n", vet_pos[i]);
            else
                printf("T2,%d\n", vet_pos[i] - MAX);
        }
    } 

    return;
}
