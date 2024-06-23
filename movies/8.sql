SELECT name 
FROM people
INNER JOIN stars ON people.id = person_id
INNER JOIN movies ON movie_id = movies.id
WHERE movies.title = "Toy Story";


