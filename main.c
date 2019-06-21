#include <stdio.h>
#include <stdlib.h>
#include "fila_int.h"

void acessaMenu();
void menu();
void opcao1();
void opcao2();
void opcao3();

int main(){
    cria_fila();
    fila_vazia();
    acessaMenu();
return 0;
}

void menu(){
    printf("=======================================================\n");
    printf(">>>>>>>>>>>>>>>>>>>> TRABALHO 01 <<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=======================================================\n");
    printf("\t Por favor selecione a opção desejada:\n");
    printf(" (1) Inserir elementos na fila\n");
    printf(" (2) Remover elementos da fila\n");
    printf(" (3) Imprimir a Fila\n");
    printf(" (4) Sair\n");
    printf("=======================================================\n");
    printf("Digite a opção:");
}

void acessaMenu(){
    char opcao = '0';
    menu();
    while(opcao != '4'){
        scanf(" %c", &opcao);
        switch(opcao){
            case '1':
                opcao1();
                menu();
                break;
            case '2':
                opcao2();
                menu();
                break;
            case '3':
                opcao3();
                menu();
                break;
            case '4':
                system("clear");
                break;
            default:
                printf("\nEntrada Inválida, digite novamente: ");
        }
    }
}

void opcao1(){
    int quant, elemento;

    printf("Digite quantos elementos você deseja inserir:\n");
    scanf("%d", &quant);
    printf("Digite a seguir, os elementos a serem inseridos:\n");

    for(int i = 1; i <= quant; i++){
        printf("Elemento (%d): ", i);
        scanf("%d", &elemento);
        while(elemento > 999 || elemento < 0){
            printf("Elemento inválido, digite novamente:\n");
            printf("Elemento (%d): ", i);
            scanf("%d", &elemento);
        }
        if(fila_cheia()){
            system("clear");
            printf("Impossível inserir mais elementos, a fila está cheia!!\n\n\n");
            break;
        }
        else{
            if(enfileira(elemento)){
                printf("Elemento %d inserido!\n", elemento);
            }
        }
    }
    system("clear");
}

void opcao2(){
    int quant, elemento;

    printf("Digite quantos elementos você deseja remover:\n");
    scanf("%d", &quant);
    system("clear");
    if(fila_vazia()){
        printf("A fila está vazia!!\n");
    }
    else{
        for(int i = 0; i < quant; i++){
            if(fila_vazia()){
                printf("Impossível remover mais elementos, a fila está vazia!!\n");
                break;
            }
            else{
                elemento = desenfileira();
                printf("Elemento removido: %d\n", elemento);
            }
        }
    }
}

void opcao3(){
    system("clear");
    print_fila();
}