"""
ANÁLISE EXIGIDA:

A abordagem com gerador implementa avaliação preguiçosa (lazy evaluation):
cada registro é produzido apenas quando solicitado pelo chamador.

Isso evita armazenar todos os registros em memória RAM ao mesmo tempo.
Se tentássemos carregar um log infinito ou enorme em uma lista, a memória
cresceria sem limite, podendo causar esgotamento de RAM.

Com yield, geramos sob demanda, com baixo consumo de memória.
"""

def gerar_logs():
    contador = 1
    while True:
        yield f"LOG #{contador}: evento processado"
        contador += 1

stream_logs = gerar_logs()

for _ in range(10):
    print(next(stream_logs))
