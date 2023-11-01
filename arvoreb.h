#ifndef arvoreb
#define arvoreb

typedef struct node {
    // lista de filhos
    struct plist {      
        struct node* pfilho;
        struct plist* prox;
    } *filhos;
    
    // lista de chaves
    struct klist {      
        int chave;
        struct klist* prox;
    } *chaves;
             
    int nchaves;                // número de chaves contidas nesse nó
    char folha;                 // folha ou não ('s' ou 'n')
} Nodo;

typedef struct btree {
    int t;                      // ordem da árvore
    Nodo* raiz;                 // raiz da árvore
} ArvoreB;

// alocar nodo na memória heap
Nodo* criarNodo(struct plist *filhos, struct klist *chaves, 
                    int nchaves, char folha);

// alocar filho na memória heap
struct plist* criarFilho(Nodo* pfilho, struct plist* prox);

// alocar chave na memória heap
struct klist* criarChave(int chave, struct klist* prox);

// alocar árvore na memória heap
ArvoreB* criarArvore(int t, int chaveInicial);

// inserir filho
Nodo* inserirFilho(Nodo* n, Nodo* f);

// buscar filho na posição i
struct plist* buscarFilho(Nodo* n, int i);

// inserir chave
Nodo* inserirChave(Nodo* n, int chave);

// buscar chave na posição i
struct klist* buscarChave(Nodo* n, int i);

// contar chaves no nodo
void contarChaves(Nodo* n);

// split

// inserir nodo

// buscar nodo


// imprimir chaves de um nodo x
// imprimir transversal

#endif