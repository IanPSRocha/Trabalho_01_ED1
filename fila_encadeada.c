#include <stdlib.h>
#include <stdio.h>
#include "fila_encadeada.h"

static int tam;
static int lim = 10;

void criar_fila(ElemFila * Fila){
    Fila->prox = NULL;
    tam = 0;
}

int fila_cheia(){
    if(tam == lim){
        return 1;
    }
    return 0;
}

int fila_vazia(){
    if(tam == 0){
        return 1;
    }
    return 0;
}

ElemFila *aloca(){
    ElemFila *novo = (ElemFila *) malloc (sizeof (ElemFila));
    if(!novo){
        printf("Erro ao alocar!!\n");
        exit(1);
    }
    else{
        printf("Novo Elemento: ");
        scanf("%d", &novo->dado);
    }
}

int enfileira(ElemFila *Fila){
    ElemFila *novo = aloca();
    novo->prox = NULL;

    if(fila_vazia()){
        Fila->prox = novo;
    }
    else{
        ElemFila *aux = Fila->prox;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    tam++;
    return 1;
}

ElemFila *retira(ElemFila *Fila){
    if(Fila->prox == NULL){
        printf("A fila já está vazia!!\n");
        return NULL;
    }
    else{
        ElemFila *aux = Fila->prox;
        Fila->prox = aux->prox;
        tam--;
        return aux;
    }
}

int desenfileira(ElemFila *Fila){
    ElemFila *aux = retira(Fila);
    if(aux != NULL){
        libera(aux);
        return 1;
    }
    return 0;
}

void libera(ElemFila *Fila){
    if(!fila_vazia()){
        ElemFila *aux, *atual;
        atual = Fila->prox;
        while(atual != NULL){
            aux = atual->prox;
            free(atual);
            atual = aux;
        }
    }
}

void print_fila(ElemFila *Fila){
    ElemFila *aux = Fila;
    printf("-------------------------------------------------------------\n|");
    for(aux; aux->prox != NULL; aux->prox){
        if(aux->dado == 0){
            printf(" xxx |");
        }
        else{
            printf("  %d  |", aux->dado);
        }
    }
    printf("\n-------------------------------------------------------------\n");
    if(tam == 0){
        printf("p  u\n");
    }
    else{
        for(aux; aux->prox != NULL; aux->prox){
            if(aux->dado != 0){
                printf(" p ");
                break;
            }
            else{
                printf("    ");
            }
        }
        for(aux; aux->prox != NULL; aux->prox){
            if(aux->dado != 0 && aux->prox->dado == 0){
                printf("  u  \n");
                break;
            }
                else{
                printf("     ");
            }
        }
    }
}