--10. Consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme
-- que recebeu uma classificação de pelo menos 9,0:

SELECT DISTINCT p.name
FROM people p
JOIN directors d ON p.id = d.person_id
JOIN movies m ON d.movie_id = m.id
JOIN ratings r ON m.id = r.movie_id
WHERE r.rating >= 9.0;
