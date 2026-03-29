#include <stdio.h>

/*
ANÁLISE EXIGIDA:

A variável saldo_bancario nasce no escopo do main, protegida do acesso global.

A função tentar_alterar_por_valor recebe apenas uma CÓPIA do valor original.
Ou seja, o parâmetro formal 'saldo' é outra variável local, armazenada em outro
endereço de memória. Alterar essa cópia não afeta a variável original do main.

Já a função alterar_por_referencia recebe o ENDEREÇO da variável original.
Com ponteiros, a função acessa diretamente a posição de memória do saldo_bancario,
realizando a mutação do estado com sucesso (Inout Mode).
*/

void tentar_alterar_por_valor(int saldo) {
    saldo = saldo + 500;
    printf("Dentro de tentar_alterar_por_valor: %d\n", saldo);
}

void alterar_por_referencia(int *saldo) {
    *saldo = *saldo + 500;
    printf("Dentro de alterar_por_referencia: %d\n", *saldo);
}

int main() {
    int saldo_bancario = 1000;

    printf("Saldo inicial: %d\n", saldo_bancario);

    tentar_alterar_por_valor(saldo_bancario);
    printf("Saldo apos passagem por valor: %d\n", saldo_bancario);

    alterar_por_referencia(&saldo_bancario);
    printf("Saldo apos passagem por referencia: %d\n", saldo_bancario);

    return 0;
}
