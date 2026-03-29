#include <stdio.h>

/*
ANÁLISE EXIGIDA:

A função calcular_nova_altitude é segura porque recebe a altitude atual por valor
e apenas retorna um novo valor calculado, sem alterar o estado original.

Já o procedimento forcar_mutacao_altitude recebe o endereço da variável local
de altitude e modifica diretamente seu conteúdo. Isso ilustra o efeito colateral
via referência: a função altera o estado do chamador.
*/

int calcular_nova_altitude(int altitude_atual, int variacao_planejada) {
    return altitude_atual + variacao_planejada;
}

void forcar_mutacao_altitude(int *altitude, int variacao_forcada) {
    *altitude = *altitude + variacao_forcada;
}

int main() {
    int altitude = 10000;

    printf("Altitude inicial: %d\n", altitude);

    int altitude_desejada = calcular_nova_altitude(altitude, 500);
    printf("Nova altitude calculada com seguranca: %d\n", altitude_desejada);
    printf("Altitude original apos funcao pura: %d\n", altitude);

    forcar_mutacao_altitude(&altitude, -700);
    printf("Altitude original apos efeito colateral: %d\n", altitude);

    return 0;
