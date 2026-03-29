"""
ANÁLISE EXIGIDA:

Em Python, argumentos são passados por compartilhamento de objeto
(call-by-sharing). Isso significa que a função recebe uma referência
ao MESMO objeto lista usado no programa principal.

Como listas são mutáveis, qualquer alteração feita nos elementos da lista
dentro da função afeta o objeto original de forma irreversível, a menos que
uma cópia seja criada antes.

Ou seja: não houve cópia profunda da lista; o estoque original foi alterado.
"""

def aplicar_desconto(estoque, desconto):
    for i in range(len(estoque)):
        estoque[i] = estoque[i] - desconto

estoque = [100.0, 250.0, 80.0, 300.0]

print("Estoque antes:", estoque)
aplicar_desconto(estoque, 10.0)
print("Estoque depois:", estoque)
