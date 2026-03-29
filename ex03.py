"""
ANÁLISE EXIGIDA:

Primeiro, o cálculo da folha é apresentado no estilo "código espaguete",
misturando lógica de negócio e impressão diretamente no fluxo principal.

Depois, o programa é refatorado com Alta Coesão:
- função pura: calcula salário líquido
- procedimento: imprime os resultados

Isso melhora legibilidade, manutenção e reutilização.
"""

print("=== VERSAO CAOTICA ===")

nome1 = "Ana"
horas1 = 160
valor1 = 25
sal1 = horas1 * valor1
imp1 = sal1 * 0.10
liq1 = sal1 - imp1
print(nome1, "Bruto:", sal1, "Imposto:", imp1, "Liquido:", liq1)

nome2 = "Bruno"
horas2 = 150
valor2 = 30
sal2 = horas2 * valor2
imp2 = sal2 * 0.10
liq2 = sal2 - imp2
print(nome2, "Bruto:", sal2, "Imposto:", imp2, "Liquido:", liq2)

nome3 = "Carla"
horas3 = 170
valor3 = 28
sal3 = horas3 * valor3
imp3 = sal3 * 0.10
liq3 = sal3 - imp3
print(nome3, "Bruto:", sal3, "Imposto:", imp3, "Liquido:", liq3)


print("\n=== VERSAO REFATORADA ===")

def calcular_salario_liquido(horas, valor_hora, taxa_imposto):
    """Função pura: só calcula e retorna valores."""
    bruto = horas * valor_hora
    imposto = bruto * taxa_imposto
    liquido = bruto - imposto
    return bruto, imposto, liquido

def imprimir_folha(nome, bruto, imposto, liquido):
    """Procedimento: responsável apenas por exibir os dados."""
    print(f"{nome} | Bruto: {bruto:.2f} | Imposto: {imposto:.2f} | Liquido: {liquido:.2f}")

funcionarios = [
    ("Ana", 160, 25),
    ("Bruno", 150, 30),
    ("Carla", 170, 28),
]

for nome, horas, valor_hora in funcionarios:
    bruto, imposto, liquido = calcular_salario_liquido(horas, valor_hora, 0.10)
    imprimir_folha(nome, bruto, imposto, liquido)
