-- 11. Consulta SQL para listar os títulos dos cinco filmes com melhor classificação
-- (em ordem) que Chadwick Boseman estrelou, começando com os de maior classificação:

SELECT m.title
FROM movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON s.person_id = p.id
JOIN ratings r ON m.id = r.movie_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5;
