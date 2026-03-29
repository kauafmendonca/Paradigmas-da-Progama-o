#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 5
#define MAX_MEDICOS 3
#define MAX_LEITOS 5

/*
ANÁLISE EXIGIDA:

Neste ponto do paradigma procedural, começa a ficar evidente uma crise de escala.
O estado do sistema está concentrado em uma struct gigante, contendo muitos dados
heterogêneos e interdependentes. Procedimentos como realizar_internacao precisam
receber essa estrutura inteira e manipulá-la com muito cuidado para não corromper
o estado geral.

À medida que o sistema cresce, aumenta a quantidade de campos, ponteiros, regras
de integridade e dependências entre partes distintas. Separar funções matemáticas
dos dados passa a ser insuficiente, porque o problema principal deixa de ser só
"calcular" e passa a ser "proteger e organizar o estado". Esse cenário prepara
o terreno para o encapsulamento da Orientação a Objetos, onde dados e comportamentos
relacionados passam a viver juntos com maior controle de acesso.
*/

typedef struct {
    char pacientes[MAX_PACIENTES][50];
    char medicos[MAX_MEDICOS][50];
    int leitos_disponiveis[MAX_LEITOS];
    float caixa_financeiro;
    int total_pacientes;
} SistemaHospitalar;

void inicializar_sistema(SistemaHospitalar *sistema) {
    strcpy(sistema->medicos[0], "Dr. Silva");
    strcpy(sistema->medicos[1], "Dra. Costa");
    strcpy(sistema->medicos[2], "Dr. Lima");

    for (int i = 0; i < MAX_LEITOS; i++) {
        sistema->leitos_disponiveis[i] = 1;
    }

    sistema->caixa_financeiro = 10000.0f;
    sistema->total_pacientes = 0;
}

void realizar_internacao(SistemaHospitalar *sistema, const char *nome_paciente, float custo) {
    int leito_encontrado = -1;

    for (int i = 0; i < MAX_LEITOS; i++) {
        if (sistema->leitos_disponiveis[i] == 1) {
            leito_encontrado = i;
            break;
        }
    }

    if (leito_encontrado == -1) {
        printf("Nao ha leitos disponiveis para %s\n", nome_paciente);
        return;
    }

    if (sistema->total_pacientes >= MAX_PACIENTES) {
        printf("Capacidade maxima de pacientes atingida.\n");
        return;
    }

    strcpy(sistema->pacientes[sistema->total_pacientes], nome_paciente);
    sistema->total_pacientes++;
    sistema->leitos_disponiveis[leito_encontrado] = 0;
    sistema->caixa_financeiro += custo;

    printf("Paciente %s internado no leito %d\n", nome_paciente, leito_encontrado);
}

void exibir_sistema(const SistemaHospitalar *sistema) {
    printf("=== ESTADO DO SISTEMA HOSPITALAR ===\n");
    printf("Caixa financeiro: %.2f\n", sistema->caixa_financeiro);
    printf("Total de pacientes: %d\n", sistema->total_pacientes);

    printf("Pacientes internados:\n");
    for (int i = 0; i < sistema->total_pacientes; i++) {
        printf("- %s\n", sistema->pacientes[i]);
    }

    printf("Leitos:\n");
    for (int i = 0; i < MAX_LEITOS; i++) {
        printf("Leito %d: %s\n", i, sistema->leitos_disponiveis[i] ? "Livre" : "Ocupado");
    }
}

int main() {
    SistemaHospitalar sistema;
    inicializar_sistema(&sistema);

    realizar_internacao(&sistema, "Gabriel Souza", 1500.0f);
    realizar_internacao(&sistema, "Mariana Alves", 2200.0f);

    exibir_sistema(&sistema);

    return 0;
}
