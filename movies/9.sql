SELECT DISTINCT name
FROM people
INNER JOIN movies ON stars.movie_id = movies.id
INNER JOIN stars ON people.id = stars.person_id
WHERE year = 2004
ORDER BY birth;

