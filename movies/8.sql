--8. Consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story:

SELECT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.title = 'Toy Story';
