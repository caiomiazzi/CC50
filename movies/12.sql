--12. Consulta SQL para listar os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos:

SELECT m.title
FROM movies m
JOIN stars s1 ON m.id = s1.movie_id
JOIN stars s2 ON m.id = s2.movie_id
JOIN people p1 ON s1.person_id = p1.id
JOIN people p2 ON s2.person_id = p2.id
WHERE p1.name = 'Johnny Depp' AND p2.name = 'Helena Bonham Carter';

