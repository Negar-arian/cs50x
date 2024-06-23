SELECT title
FROM people, stars, ratings, movies
WHERE people.id = stars.person_id
AND stars.movie_id = ratings.movie_id
AND ratings.movie_id = movies.id
AND name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;


