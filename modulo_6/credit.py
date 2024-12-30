def main():
    # Solicitar o número do cartão ao usuário
    card_number = get_card_number()

    # Validar o número com o algoritmo de Luhn
    if not luhn_check(card_number):
        print("INVALID")
        return

    # Determinar o tipo do cartão
    card_type = get_card_type(card_number)
    print(card_type)


def get_card_number():
    """Solicita um número de cartão válido ao usuário"""
    while True:
        card_number = input("Number: ").strip()
        if card_number.isdigit():
            return card_number
        print("Invalid input. Please enter a numeric value.")


def luhn_check(card_number):
    """Valida o número do cartão usando o algoritmo de Luhn"""
    total = 0
    # Inverter os dígitos para percorrer da direita para a esquerda
    reversed_digits = card_number[::-1]

    for i, digit in enumerate(reversed_digits):
        digit = int(digit)
        # Multiplicar cada segundo dígito por 2
        if i % 2 == 1:
            digit *= 2
            # Se o resultado tiver dois dígitos, somar os dígitos
            if digit > 9:
                digit -= 9
        total += digit

    # Retornar True se o total for divisível por 10
    return total % 10 == 0


def get_card_type(card_number):
    """Determina o tipo de cartão com base nos padrões"""
    length = len(card_number)
    start_digits = int(card_number[:2])  # Pegar os dois primeiros dígitos

    if length == 15 and start_digits in {34, 37}:
        return "AMEX"
    elif length == 16 and 51 <= start_digits <= 55:
        return "MASTERCARD"
    elif length in {13, 16} and card_number[0] == "4":
        return "VISA"
    else:
        return "INVALID"


main()
