CREATE TABLE MovieDetails (
    MovieID INT PRIMARY KEY,
    Title VARCHAR(100),
    Genre VARCHAR(100),
    Director VARCHAR(100),
    ReleaseYear INT
);

CREATE TABLE MovieFinancials (
    FinancialID INT PRIMARY KEY,
    BudgetUSD DECIMAL(12,2),
    BoxOfficeUSD DECIMAL(12,2),
    MovieID INT,
    FOREIGN KEY (MovieID) REFERENCES MovieDetails(MovieID)
);

CREATE TABLE MovieRatingsDuration (
    RatingID INT PRIMARY KEY,
    DurationMin INT,
    Rating DECIMAL(12,2),
    Language VARCHAR(100),
    Country VARCHAR(100),
    MovieID INT,
    FOREIGN KEY (MovieID) REFERENCES MovieDetails(MovieID)
);
-- 10 rows for MovieDetails
INSERT INTO MovieDetails (MovieID, Title, Genre, Director, ReleaseYear)
VALUES
(1, 'The Last Horizon', 'Drama', 'Arjun Mehta', 2018),
(2, 'Shadow City', 'Crime', 'Arjun Mehta', 2020),
(3, 'Firestorm', 'Action', 'Vikram Patel', 2021),
(4, 'Lost in Time', 'Sci-Fi', 'Neha Kapoor', 2019),
(5, 'Silent Echo', 'Thriller', 'Rahul Verma', 2022),
(6, 'Ocean Dreams', 'Romance', 'Priya Shah', 2017),
(7, 'The Hidden Truth', 'Mystery', 'Amit Desai', 2023),
(8, 'Warrior Spirit', 'Action', 'Karan Singh', 2020),
(9, 'Broken Strings', 'Musical', 'Ananya Rao', 2016),
(10, 'Beyond the Stars', 'Adventure', 'Rohan Joshi', 2024);


-- 10 rows for MovieFinancials
INSERT INTO MovieFinancials (FinancialID, BudgetUSD, BoxOfficeUSD, MovieID)
VALUES
(101, 15000000.00, 45000000.00, 1),
(102, 22000000.00, 68000000.00, 2),
(103, 50000000.00, 145000000.00, 3),
(104, 35000000.00, 92000000.00, 4),
(105, 18000000.00, 51000000.00, 5),
(106, 12000000.00, 38000000.00, 6),
(107, 25000000.00, 75000000.00, 7),
(108, 42000000.00, 130000000.00, 8),
(109, 10000000.00, 29000000.00, 9),
(110, 60000000.00, 175000000.00, 10);


-- 10 rows for MovieRatingsDuration
INSERT INTO MovieRatingsDuration 
(RatingID, DurationMin, Rating, Language, Country, MovieID)
VALUES
(201, 125, 8.20, 'Hindi', 'India', 1),
(202, 138, 7.80, 'English', 'USA', 2),
(203, 142, 8.50, 'English', 'USA', 3),
(204, 130, 7.90, 'Hindi', 'India', 4),
(205, 118, 8.10, 'English', 'UK', 5),
(206, 110, 7.50, 'Hindi', 'India', 6),
(207, 135, 8.40, 'English', 'Canada', 7),
(208, 150, 8.70, 'Hindi', 'India', 8),
(209, 105, 7.60, 'English', 'USA', 9),
(210, 145, 9.00, 'English', 'USA', 10);

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
WITH AVG_MOV AS
(
SELECT TITLE,BUDGETUSD,AVG(BUDGETUSD) OVER(ORDER BY BUDGETUSD ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AVG_BUG
FROM MOVIEFINANCIALS MF,MovieDetails M
WHERE MF.MOVIEID = M.MOVIEID
)
SELECT TITLE
FROM AVG_MOV
WHERE BudgetUSD>AVG_BUG


--16. Find the titles of movies that have a box office revenue greater than the average box office revenue of 
--all movies. 
WITH AVG_MOV AS
(
SELECT TITLE,BoxOfficeUSD,AVG(BoxOfficeUSD) OVER(ORDER BY BOXOFFICEUSD ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AVG_BUG
FROM MOVIEFINANCIALS MF,MovieDetails M
WHERE MF.MOVIEID = M.MOVIEID
)
SELECT TITLE
FROM AVG_MOV
WHERE BoxOfficeUSD>AVG_BUG

--17. Create a view with Rating, Language and Country columns with no data and named it MovieReview. 
CREATE VIEW MOVIEREVIEW AS
SELECT RATING,LANGUAGE,COUNTRY
FROM MovieRatingsDuration
WHERE 0=1

--18. List all movies that have the same director but different genres, displaying the director’s name, both 
--movie titles, and their respective genres. 
WITH CTE AS
(
SELECT MD1.TITLE T1,MD1.DIRECTOR D1,MD1.GENRE G1,MD2.TITLE T2,MD2.DIRECTOR D2,MD2.GENRE G2
FROM MovieDetails MD1
CROSS JOIN MovieDetails MD2
)
SELECT D1,T1,G1,T2,G2
FROM CTE
WHERE D1=D2 AND T1!=T2 AND G1!=G2

--19. Retrieve the title, director, and box office earnings for all movies that were released after 2010, along 
--with their ratings. 
--20. List all directors and the number of movies they have directed, but only include directors who have 
--directed more than 1 movie.