import random
import re
import sys

# Função para validar um CPF
def validar_cpf(cpf: str) -> bool:
    # Remove pontos e traço
    cpf = re.sub(r'[^0-9]', '', cpf)

    # Verifica se o CPF tem 11 dígitos
    if len(cpf) != 11:
        return False

    # Verifica se o CPF tem todos os números iguais (ex: 111.111.111-11)
    if cpf == cpf[0] * len(cpf):
        return False

    # Calculando o primeiro dígito verificador
    nove_digitos = cpf[:9]
    contador_regressivo_1 = 10
    resultado_digito_1 = sum(int(digito) * contador_regressivo_1 for digito, contador_regressivo_1 in zip(nove_digitos, range(10, 1, -1)))
    digito_1 = (resultado_digito_1 * 10) % 11
    digito_1 = digito_1 if digito_1 <= 9 else 0

    # Calculando o segundo dígito verificador
    dez_digitos = cpf[:9] + str(digito_1)
    contador_regressivo_2 = 11
    resultado_digito_2 = sum(int(digito) * contador_regressivo_2 for digito, contador_regressivo_2 in zip(dez_digitos, range(11, 1, -1)))
    digito_2 = (resultado_digito_2 * 10) % 11
    digito_2 = digito_2 if digito_2 <= 9 else 0

    # Gera o CPF completo com os dois dígitos verificadores
    cpf_gerado = f'{nove_digitos}{digito_1}{digito_2}'

    return cpf == cpf_gerado

# Função para gerar um CPF válido aleatório
def gerar_cpf() -> str:
    # Gera os 9 primeiros dígitos aleatórios
    nove_digitos = ''.join(str(random.randint(0, 9)) for _ in range(9))

    # Calculando o primeiro dígito verificador
    contador_regressivo_1 = 10
    resultado_digito_1 = sum(int(digito) * contador_regressivo_1 for digito, contador_regressivo_1 in zip(nove_digitos, range(10, 1, -1)))
    digito_1 = (resultado_digito_1 * 10) % 11
    digito_1 = digito_1 if digito_1 <= 9 else 0

    # Calculando o segundo dígito verificador
    dez_digitos = nove_digitos + str(digito_1)
    contador_regressivo_2 = 11
    resultado_digito_2 = sum(int(digito) * contador_regressivo_2 for digito, contador_regressivo_2 in zip(dez_digitos, range(11, 1, -1)))
    digito_2 = (resultado_digito_2 * 10) % 11
    digito_2 = digito_2 if digito_2 <= 9 else 0

    # Gera o CPF completo com os dois dígitos verificadores
    return f'{nove_digitos}{digito_1}{digito_2}'

# Função principal de interação com o usuário
def main():
    # Solicita o CPF para validação
    cpf_input = input('Digite seu CPF (formato 746.824.890-70): ')

    if validar_cpf(cpf_input):
        print(f'{cpf_input} é um CPF válido.')
    else:
        print(f'{cpf_input} é um CPF inválido.')

    # Solicita a geração de um CPF válido
    gerar_novamente = input('Gostaria de gerar um CPF válido aleatório? (s/n): ')
    if gerar_novamente.lower() == 's':
        cpf_gerado = gerar_cpf()
        print(f'CPF gerado: {cpf_gerado}')

if __name__ == "__main__":
    main()
