SELECT DISTINCT people.name FROM people JOIN stars
ON people.id = stars.person_id 
WHERE name != 'Kevin Bacon'
AND stars.movie_id IN (SELECT movies.id from (movies JOIN stars
ON movies.id = stars.movie_id) JOIN people
ON stars.person_id = people.id
WHERE people.name = 'Kevin Bacon' AND people.birth = 1958) ;
