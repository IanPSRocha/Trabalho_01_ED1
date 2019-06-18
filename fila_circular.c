#include <stdio.h>
#include "fila_int.h"

#define N 10

static int *fila;
static int N, p, u;

void cria_fila_circular(){
    fila = malloc( N * sizeof(int) );p = 0; u = 0;
}

int enfileira_circular(int y){
    int ret = 1;
    if ( fila_cheia() ) { ret = redimensiona();}
    if ( ret ) {
    fila[u++] = y;
    if ( u == N ) u = 0;
    }
    return ret;
}

int desenfileira_int(){
    fila_int[p] = 0;
return fila_int[p++];
}

//falta a fila vazia, cheia e desinfileira

void print_fila(){
    printf("-------------------------------------------------------------\n|");
    for(int i = 0; i < N; i++){
        if(fila_int[i] == 0){
            printf(" xxx |");
        }
        else{
            printf("  %d  |", fila_int[i]);
        }
    }
    printf("\n-------------------------------------------------------------\n");
    if(p == 0 && u == 0){
        printf("p  u\n");
    }
    else{
        for(int i = 0; i < N; i++){
            if(fila_int[i] != 0){
                printf(" p ");
                break;
            }
            else{
                printf("    ");
            }
        }
        for(int i = 0; i < N; i++){
            if(fila_int[i] != 0 && fila_int[i+1] == 0){
                printf("  u  \n");
                break;
            }
                else{
                printf("     ");
            }
        }
    }
}
int redimensiona() {
int i, j;
fila = realloc( fila, 2 * N * sizeof(int) );
if ( fila == NULL ) return 0;
if ( u != N-1 ) {
if ( u-1 < N-p ) {
for ( i = N, j = 0; j < u; i++, j++ ) {
fila[i] = fila[j];
}
u = N+u;

else {
for ( i = p, j = N+p; i < N; i++, j++ ) {
fila[j] = fila[i];
}
p = N+p;
}
}
N *= 2;
return 1;
}
