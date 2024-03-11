/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * 
 * PILHA com alocacao estatica
 */

#include<stdio.h>
#include<stdlib.h>

#define N 10    // Definicao de constante que determina a capacidade da fila

//Definicao do tipo abstrato de dado que representa a estrutura plILA
struct est_pilha {
    int pilha[N];    //Vetor que representa a fila (estatico)
    int contador;   //Contador para controle da estrutura
};
typedef struct est_pilha tipo_pilha;

//Prototipo das funcoes
void empilha(tipo_pilha*, int);
int topo(tipo_pilha);
int desempilha(tipo_pilha*);
void imprimePilha(tipo_pilha);

int main() {
    tipo_pilha minha_pilha;
    int valor;

    //Inicializa o contador da fila
    minha_pilha.contador = 0;

    empilha(&minha_pilha, 2);
    empilha(&minha_pilha, 5);
    empilha(&minha_pilha, 3);
    empilha(&minha_pilha, 1);
    

    imprimePilha(minha_pilha);

    valor = desempilha(&minha_pilha);
    printf("Valor desempilhado = %d\n", valor);
    valor = desempilha(&minha_pilha);
    printf("Valor desempilhado = %d\n", valor);

    imprimePilha(minha_pilha);
    
    return EXIT_SUCCESS;
}

/***
 * Funcao que insere um novo valor na PILHA.
 * Parametros: *tipo_pilha pl
 *		int valor
 * Retorno: void
 */
void empilha(tipo_pilha *pl, int valor) {
    if ( pl->contador < N ) {
        pl->pilha[ pl->contador++ ] = valor;
    } else {
        printf("[ERRO] Pilha cheia. Valor nao empilhado.\n");
    }
}

/***
 * Funcao que desempilha valor. Se a pilha estah vazia, retorna -1.
 * Parametros:  tipo_pilha *pl
 * Retorno: (int) valor desempilhado
*/
int desempilha(tipo_pilha *pl) {
    int valor;
    //Verifica se a pilha estah vazia
    if ( pl->contador == 0) {
        printf("[ERRO] Pilha vazia, nao eh possivel Desempilhar valor.\n");
        return -1; //Retorna -1 como código de erro, nao foi possivel remover valor
    } else { //Contexto em que desempilha o valor do topo
        valor = pl->pilha[ --pl->contador ];
        return valor; //retorna o valor desempilhado 
    }
}

/***
 * FUncao que imprime a PILHA.
 * Parametro: tipo_pilha pl
 * Retorno: void
 */
void imprimePilha(tipo_pilha pl) {
    int i;
    printf("PILHA: (base)[ ");
    
    for (i=0; i<pl.contador; i++) {
        printf("%d ", pl.pilha[i]);
    }
    printf("] <-topo\n");
}
