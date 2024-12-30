import random
import re

def validar_cpf(cpf: str) -> bool:
    cpf = re.sub(r'[^0-9]', '', cpf)

    # Checa se todos os dígitos são iguais
    if cpf == cpf[0] * len(cpf):
        return False

    # Validação do primeiro dígito
    nove_digitos = cpf[:9]
    contador_regressivo_1 = 10
    resultado_digito_1 = sum(int(digito) * contador_regressivo_1 for digito in nove_digitos)
    digito_1 = (resultado_digito_1 * 10) % 11
    digito_1 = digito_1 if digito_1 <= 9 else 0

    # Validação do segundo dígito
    dez_digitos = cpf[:9] + str(digito_1)
    contador_regressivo_2 = 11
    resultado_digito_2 = sum(int(digito) * contador_regressivo_2 for digito in dez_digitos)
    digito_2 = (resultado_digito_2 * 10) % 11
    digito_2 = digito_2 if digito_2 <= 9 else 0

    return cpf == f'{nove_digitos}{digito_1}{digito_2}'

def criar_cpf() -> str:
    nove_digitos = ''.join(str(random.randint(0, 9)) for _ in range(9))
    contador_regressivo_1 = 10
    resultado_digito_1 = sum(int(digito) * contador_regressivo_1 for digito in nove_digitos)
    digito_1 = (resultado_digito_1 * 10) % 11
    digito_1 = digito_1 if digito_1 <= 9 else 0

    dez_digitos = nove_digitos + str(digito_1)
    contador_regressivo_2 = 11
    resultado_digito_2 = sum(int(digito) * contador_regressivo_2 for digito in dez_digitos)
    digito_2 = (resultado_digito_2 * 10) % 11
    digito_2 = digito_2 if digito_2 <= 9 else 0

    return f'{nove_digitos}{digito_1}{digito_2}'
