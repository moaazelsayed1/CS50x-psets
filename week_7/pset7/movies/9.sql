SELECT people.name FROM people
WHERE people.id IN (SELECT DISTINCT people.id FROM (people JOIN stars
ON people.id = stars.person_id)
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004) ORDER by people.birth;