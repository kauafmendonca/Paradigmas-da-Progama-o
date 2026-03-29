"""
ANÁLISE EXIGIDA:

Uma sub-rotina tradicional executa do início ao fim no modelo run-to-completion:
ela começa, processa tudo e só depois devolve o controle.

Já a corrotina geradora abaixo usa yield para suspender a execução no meio,
preservando seu estado interno (variáveis locais e posição atual).
Quando next() é chamado novamente, a execução continua de onde parou.

Isso caracteriza controle de fluxo cooperativo: o chamador decide quando retomar
a execução da rotina.
"""

def linha_de_montagem():
    peca = 1
    while peca <= 5:
        yield f"Processando peca {peca}"
        peca += 1

maquina = linha_de_montagem()

for _ in range(5):
    print(next(maquina))
