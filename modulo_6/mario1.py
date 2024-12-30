
def main():
    # Etapa 1: Solicitar entrada do usuário
    height = get_height()

    # Etapa 2: Construir a pirâmide
    for row in range(1, height + 1):
        # Calcular espaços e hashes
        spaces = height - row
        hashes = row
        # Montar a linha da pirâmide
        line = " " * spaces + "#" * hashes
        # Imprimir a linha
        print(line)

def get_height():
    """Solicita ao usuário uma altura válida entre 1 e 8"""
    while True:
        try:
            # Solicitar entrada
            height = int(input("Height: "))
            # Verificar se está no intervalo permitido
            if 1 <= height <= 8:
                return height
        except ValueError:
            pass  # Ignorar entradas não inteiras
        # Se inválido, exibir mensagem e repetir
        print("Invalid input. Please enter a number between 1 and 8.")


main()
