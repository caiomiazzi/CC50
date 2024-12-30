def main():
    # Etapa 1: Solicitar altura do usuário
    height = get_height()

    # Etapa 2: Construir a pirâmide dupla
    for row in range(1, height + 1):
        # Calcular espaços antes da primeira pirâmide
        spaces = " " * (height - row)
        # Gerar os hashes para a primeira pirâmide
        left_hashes = "#" * row
        # Espaços fixos entre as pirâmides
        gap = "  "
        # Gerar os hashes para a segunda pirâmide
        right_hashes = "#" * row
        # Concatenar e imprimir a linha
        print(spaces + left_hashes + gap + right_hashes)


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
        # Exibir mensagem de erro e repetir solicitação
        print("Invalid input. Please enter a number between 1 and 8.")


# Executar o programa principal
main()
