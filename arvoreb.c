#include <stdlib.h>
#include <math.h>

#include "arvoreb.h"

Nodo* criarNodo(struct plist *filhos, struct klist *chaves, 
                    int nchaves, char folha) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo*));
    n->filhos = filhos;
    n->chaves = chaves;
    n->nchaves = nchaves;
    n->folha = folha;

    return n;
}

struct plist* criarFilho(Nodo* pfilho, struct plist* prox) {
    struct plist* f = (struct plist*)malloc(sizeof(struct plist));
    f->pfilho = pfilho;
    f->prox = prox;

    return f;
}

struct klist* criarChave(int chave, struct klist* prox)  {
    struct klist* c = (struct klist*)malloc(sizeof(struct klist));
    c->chave = chave;
    c->prox = prox;

    return c;
}

ArvoreB* criarArvore(int t, int chaveInicial) {
    struct klist* c = criarChave(chaveInicial, NULL);
    Nodo* raiz = criarNodo(NULL, c, 1, 'n');

    ArvoreB* a = (ArvoreB*)malloc(sizeof(ArvoreB));
    a->t = t;
    a->raiz = raiz;

    return a;
}

Nodo* inserirFilho(Nodo* n, Nodo* f) {
    struct plist* aux = n->filhos;
    
    while(aux != NULL)
        aux = aux->prox;

    aux = criarFilho(f, NULL);

    return n;
}

struct plist* buscarFilho(Nodo* n, int i) {
    struct plist* aux = n->filhos;
    int cont = 0;

    while(aux != NULL) {
        if(cont == i)
            return aux;
        aux = aux->prox;
        cont++;
    }

    return NULL;
}

Nodo* inserirChave(Nodo* n, int chave) {
    struct klist* aux = n->chaves;
    struct klist* aux2 = NULL;
    int b = 0;

    while(aux != NULL && b == 0) {
        if(aux->prox != NULL)
            if(chave < aux->prox->chave) {
                b = 1;
                aux2 = aux;
            }
        aux = aux->prox;
    }
                
    if(b == 0)
        aux = criarChave(chave, NULL);
    else {
        aux2->prox = criarChave(chave, aux);
    }

    return n;
}

struct klist* buscarChave(Nodo* n, int i) {
    struct klist* aux = n->chaves;
    int cont = 0;

    while(aux != NULL) {
        if(cont == i)
            return aux;
        aux = aux->prox;
        cont++;
    }

    return NULL;
}

void contarChaves(Nodo* n) {
    struct klist* aux = n->chaves;
    int cont = 0;

    while(aux != NULL) {
        aux = aux->prox;
        cont++;
    }

    n->nchaves = cont;
}

Nodo* auxSplit(Nodo* n, int i) {
    struct klist* chavesFim = buscarChave(n, i);
    chavesFim->prox = NULL;

    return n;  
}

struct klist* split(Nodo* n) {
    double s = n->nchaves/2.0;
    s = ceil(s);
    struct klist* chaveMeio = buscarChave(n, s);
    n = auxSplit(n, s-1);

    return chaveMeio;
}

Nodo* inserir(Nodo* raiz, int chave) {
    if(raiz == NULL)
        return NULL;

    // descer
    raiz->filhos->pfilho = inserir(raiz->filhos->pfilho, chave);
    
    for(int i = 0; i < raiz->nchaves; i++) {
        
    }


    if(raiz->folha == 's')
        raiz = inserirChave(raiz, chave);


    return raiz;
}