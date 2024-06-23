SELECT COUNT(title)
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
GROUP BY rating
HAVING rating = 10;
