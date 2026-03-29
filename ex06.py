"""
ANÁLISE EXIGIDA:

Caso Base:
- Quando o nome procurado está presente no dicionário atual.
- Ou quando chegamos a um ponto em que não há mais subpastas para explorar.

Passo Recursivo:
- Para cada subpasta encontrada (outro dicionário), a função chama a si mesma
  para continuar a busca em um nível mais profundo da árvore.
"""

def buscar_arquivo(arvore, nome_arquivo, caminho="raiz"):
    # Caso base 1: arquivo encontrado no nível atual
    if nome_arquivo in arvore:
        return f"Arquivo encontrado em: {caminho}/{nome_arquivo}"

    # Passo recursivo: explorar subdicionários
    for nome, conteudo in arvore.items():
        if isinstance(conteudo, dict):
            resultado = buscar_arquivo(conteudo, nome_arquivo, f"{caminho}/{nome}")
            if resultado is not None:
                return resultado

    # Caso base 2: não encontrou neste ramo
    return None


pastas = {
    "documentos": {
        "trabalho.txt": "conteudo",
        "projetos": {
            "relatorio.docx": "conteudo",
            "codigo.py": "print('oi')"
        }
    },
    "imagens": {
        "foto.jpg": "binario"
    },
    "backup": {
        "antigo": {
            "dados.csv": "1,2,3"
        }
    }
}

arquivo = "codigo.py"
resultado = buscar_arquivo(pastas, arquivo)

if resultado:
    print(resultado)
else:
    print("Arquivo nao encontrado.")
