SELECT DISTINCT name
FROM people
INNER JOIN directors ON directors.person_id = people.id
INNER JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0;

