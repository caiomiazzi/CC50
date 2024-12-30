--9. Consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lançado em 2004,
-- ordenado por ano de nascimento:

SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.year = 2004
ORDER BY p.birth;
