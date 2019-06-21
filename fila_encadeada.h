#ifndef _fila_encadeada_h
#define _fila_encadeada_h

struct elemFila {
    int dado;
    struct elemFila *prox;
};
typedef struct elemFila ElemFila;

ElemFila *aloca();
ElemFila *retira(ElemFila *Fila);
void cria_fila();
int enfileira(ElemFila *Fila);
int desenfileira(ElemFila *Fila);
void libera(ElemFila *Fila);
int fila_vazia();
int fila_cheia();
void print_fila();

#endif