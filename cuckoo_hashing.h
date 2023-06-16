#ifndef cuckoo_hashing
#define cuckoo_hashing

#define TAM 22

struct nodo{
    int chave;
    int excluido;
    int null;
};

double floor(double x);

void inicializa_hash(struct nodo hash[TAM]);

int busca(int chave, struct nodo hash[TAM]);

int h1(int chave);

int h2(int chave);

void insere_chave(int chave, struct nodo hash[TAM]);

void remove_chave(int chave, struct nodo hash[TAM]);

void imprime_hash(struct nodo hash[TAM]);

#endif /* cuckoo_hashing.h*/
