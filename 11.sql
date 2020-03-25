SELECT title FROM
movies JOIN stars ON movies.id = stars.movie_id JOIN
people ON people.id = stars.person_id
WHERE name = "Chadwick Boseman" ORDER BY(SELECT rating FROM ratings) DESC
LIMIT 5