--Consider above table schema and write following queries: 
--1. Retrive first five distinct movies along with their title from MovieDetails table. 
SELECT DISTINCT TOP 5 MOVIEID,TITLE
FROM MOVIEDETAILS

--2. Display the total of the BudgetUSD and BoxOfficeUSD assign the name TotalUSD from MovieFinancials.
SELECT BUDGETUSD+BOXOFFICEUSD TOTALUSD
FROM MOVIEFINANCIALS

--3. Insert the new row with this data (11,The Incredible Hulk, Action, Louis Leterrier,2008) in MovieDetails 
--table. 
INSERT INTO MovieDetails
VALUES
(11,'The Incredible Hulk', 'Action', 'Louis Leterrier',2008)

--4. Set the value of the genre to ‘Action’ of ‘Avengers:Endgame’ movie from MovieDetails table.
UPDATE MovieDetails
SET Genre ='ACTION'
WHERE Title='AVENGERS:ENDGAME'

--5. Delete the records with duration of 181 minutes from MovieRatingsDuration table.
DELETE FROM MovieRatingsDuration
WHERE DURATIONMIN=181

--6. Add a new column ‘Producer’ into the MovieDetails table.
ALTER TABLE MOVIEDETAILS
ADD PRODUCER VARCHAR(100)

--7. Delete records of MovieFinancials table without removing its table structure.
TRUNCATE TABLE MOVIEFINANCIALS

--8. Retrive all the movies from MovieDetails table with title starting with ‘The’.
SELECT *
FROM MovieDetails
WHERE Title LIKE 'THE%'

--9. Retrive name of directors includes ‘son’ from MovieDetails table.
SELECT Director
FROM MovieDetails
WHERE Director LIKE '%SON%'

--10. Convert and display title of all movies in uppercase. 
SELECT UPPER(TITLE) TITLE
FROM MovieDetails

--11. Display the highest rating from the MovieRatingsDuration table.
SELECT MAX(RATING)
FROM MovieRatingsDuration

--12. Calculate the years between current year and movies release year. 
SELECT TITLE,DATEPART(YEAR,GETDATE())-RELEASEYEAR
FROM MovieDetails

--13. Find the languages in which movies have an average rating of greater than 8.0. Display the language 
--and the average rating. 
SELECT LANGUAGE,AVG(RATING) AVG_RATING
FROM MovieRatingsDuration
GROUP BY Language
HAVING AVG(RATING)>8

--14. Retrieve the minimum,maximum,and average movie duration for each language the 
--MovieRatingsDuration table, but display only those languages where the average rating is greater than 
--7.5. 
SELECT LANGUAGE,MIN(DurationMin) MIN,MAX(DurationMin) MAX,AVG(DurationMin) AVG_DURATION
FROM MovieRatingsDuration
GROUP BY Language
HAVING AVG(RATING)>7.5

--15. Find the titles of movies whose budget is higher than the average budget of all movies.(Do not use 
--JOINS) 
--in
--16. Find the titles of movies that have a box office revenue greater than the average box office revenue of 
--all movies. 
--17. Create a view with Rating, Language and Country columns with no data and named it MovieReview. 
--18. List all movies that have the same director but different genres, displaying the director’s name, both 
--movie titles, and their respective genres. 
--19. Retrieve the title, director, and box office earnings for all movies that were released after 2010, along 
--with their ratings. 
--20. List all directors and the number of movies they have directed, but only include directors who have 
--directed more than 1 movie.