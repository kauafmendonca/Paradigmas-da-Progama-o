#include <stdio.h>

/*
ANÁLISE EXIGIDA:

Sem Caso Base, a função recursiva continua chamando a si mesma indefinidamente.
Cada chamada empilha um novo Stack Frame na Pilha de Execução.

Como a pilha é finita, o programa eventualmente esgota a memória reservada
para chamadas de função, causando Stack Overflow ou Segmentation Fault,
dependendo do sistema operacional e compilador.

A versão corrigida abaixo possui Caso Base: quando n < 0, a recursão para.
*/

/*
VERSAO COM ERRO INTENCIONAL (NAO EXECUTAR JUNTO COM A CORRIGIDA):

void contagem_sem_base(int n) {
    printf("%d\n", n);
    contagem_sem_base(n - 1);
}
*/

void contagem_corrigida(int n) {
    if (n < 0) {
        return; // Caso Base
    }

    printf("%d\n", n);
    contagem_corrigida(n - 1);
}

int main() {
    printf("Contagem regressiva corrigida:\n");
    contagem_corrigida(5);

    return 0;
}
