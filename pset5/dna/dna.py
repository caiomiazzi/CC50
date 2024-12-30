import csv
import sys


def main():
    # Checar uso correto da linha de comando
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Ler banco de dados CSV em uma lista de dicionários
    database = []
    with open(sys.argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            # Converter contagens de STRs para inteiros
            for key in row:
                if key != "name":
                    row[key] = int(row[key])
            database.append(row)

    # Ler sequência de DNA em uma string
    with open(sys.argv[2], "r") as txtfile:
        dna_sequence = txtfile.read()

    # Identificar STRs a serem analisados
    str_list = list(database[0].keys())[1:]  # Pega os cabeçalhos do CSV, exceto "name"

    # Calcular as contagens máximas de STRs na sequência de DNA
    str_counts = {}
    for str_seq in str_list:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)

    # Comparar contagens com banco de dados
    for person in database:
        match = True
        for str_seq in str_list:
            if person[str_seq] != str_counts[str_seq]:
                match = False
                break
        if match:
            print(person["name"])
            return

    # Caso nenhuma correspondência seja encontrada
    print("No match")


def longest_match(sequence, subsequence):
    """Retorna o maior número de repetições consecutivas de subsequence em sequence."""
    # Inicializar variáveis
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Verificar cada posição na sequência
    for i in range(sequence_length):
        count = 0

        # Continuar enquanto houver correspondência consecutiva
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        # Atualizar a contagem mais longa
        longest_run = max(longest_run, count)

    return longest_run


# Executar o programa principal
if __name__ == "__main__":
    main()
