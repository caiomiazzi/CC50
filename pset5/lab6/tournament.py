import csv
import sys
import random

# Number of simulations to run
N = 1000


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Lista para armazenar os times
    teams = []

    # Abrir o arquivo CSV fornecido na linha de comando
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            # Converter a classificação para inteiro e adicionar o time à lista
            teams.append({"team": row["team"], "rating": int(row["rating"])})

    # Dicionário para armazenar a contagem de vitórias de cada time
    counts = {}

    # Simular N torneios
    for _ in range(N):
        winner = simulate_tournament(teams)

        # Contabilizar a vitória no dicionário
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # Exibir a probabilidade de vitória de cada time
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simula um jogo. Retorna True se team1 ganhar, False caso contrário."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    # Calcula a probabilidade de vitória de team1
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    # Gera um número aleatório para determinar o vencedor
    return random.random() < probability


def simulate_round(teams):
    """Simula uma rodada. Retorna a lista de times vencedores."""
    winners = []

    # Simula jogos para todos os pares de times
    for i in range(0, len(teams), 2):
        # Se a equipe i vencer, adiciona ela aos vencedores
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simula um torneio. Retorna o nome do time vencedor."""
    # Simula o torneio até restar apenas um time
    while len(teams) > 1:
        teams = simulate_round(teams)

    # Retorna o nome da equipe vencedora
    return teams[0]["team"]


if __name__ == "__main__":
    main()
