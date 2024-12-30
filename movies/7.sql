--7. Consulta SQL para listar todos os filmes lançados em 2010 e suas classificações,
-- em ordem decrescente por classificação:

SELECT title, rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY rating DESC, title;
