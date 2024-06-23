SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id=people.id
where movie_id in (SELECT movie_id FROM people
JOIN stars ON stars.person_id=people.id
JOIN movies ON stars.movie_id=movies.id
where name = "Kevin Bacon" and birth = 1958) and name != "Kevin Bacon"

