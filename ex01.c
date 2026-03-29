#include <stdio.h>

/*
ANÁLISE EXIGIDA:

Este exercício compara duas abordagens para calcular Fibonacci:

1) Iterativa:
   - Complexidade de tempo: O(n)
   - Complexidade de espaço: O(1)
   - Usa repetição procedural e reaproveita variáveis locais.

2) Recursiva ingênua:
   - Complexidade de tempo: exponencial, aproximadamente O(2^n)
   - Complexidade de espaço: O(n) na profundidade da pilha
   - O problema ocorre porque a função recalcula os mesmos subproblemas
     muitas vezes. Exemplo: fib_rec(40) chama fib_rec(39) e fib_rec(38),
     e fib_rec(39) volta a chamar fib_rec(38), repetindo trabalho.
   - Cada chamada recursiva cria um novo Stack Frame, consumindo memória
     da pilha e aumentando o custo do programa.
*/

long long fib_iter(int n) {
    if (n <= 1) return n;

    long long a = 0;
    long long b = 1;
    long long c = 0;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

long long fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main() {
    int n = 40;

    long long resultado_iter = fib_iter(n);
    long long resultado_rec = fib_rec(n);

    printf("Fibonacci iterativo de %d = %lld\n", n, resultado_iter);
    printf("Fibonacci recursivo de %d = %lld\n", n, resultado_rec);

    return 0;
}
