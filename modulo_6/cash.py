def main():
    # Etapa 1: Solicitar entrada válida do usuário
    change_owed = get_positive_float("Change owed: ")

    # Etapa 2: Converter para centavos
    cents = round(change_owed * 100)

    # Etapa 3: Calcular o número mínimo de moedas
    coin_count = 0
    for coin in [25, 10, 5, 1]:  # Lista com os valores das moedas
        coin_count += cents // coin  # Quantidade de moedas desse tipo
        cents %= coin  # Atualizar o valor restante

    # Etapa 4: Exibir o resultado
    print(coin_count)


def get_positive_float(prompt):
    """Solicita ao usuário um número positivo e repete até que seja válido"""
    while True:
        try:
            value = float(input(prompt))
            if value >= 0:  # Validar se é não negativo
                return value
        except ValueError:
            pass  # Ignorar valores não numéricos
        print("Invalid input. Please enter a positive number.")


# Executar o programa principal
main()
