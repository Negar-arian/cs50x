SELECT AVG(rating)
FROM ratings
JOIN movies ON ratings.movie_id = movies.id
GROUP BY year
HAVING year = 2012;
