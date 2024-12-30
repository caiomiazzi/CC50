--6. Consulta SQL para determinar a avaliação média de todos os filmes lançados em 2012:

SELECT AVG(rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2012;
