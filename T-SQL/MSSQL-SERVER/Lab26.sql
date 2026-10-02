--From the table STUDENT perform the following queries:  
--Part – A: 
--1. Create a table valued function to display all student records. 
CREATE OR ALTER FUNCTION FN_STU_RECORDS()
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT)

SELECT * FROM FN_STU_RECORDS()

--2. Create a table valued function that accepts CITY and returns all students from that city. 
CREATE OR ALTER FUNCTION FN_STU_CITY
(@CITY VARCHAR(30))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE CITY=@CITY)

SELECT * FROM FN_STU_CITY('RAJKOT')

--3. Create a table valued function that accepts BRANCH and returns all students of that branch. 
CREATE OR ALTER FUNCTION FN_STU_BRANCH
(@BRANCH VARCHAR(30))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE BRANCH=@BRANCH)

SELECT * FROM FN_STU_BRANCH('COMPUTER')

--4. Create a table valued function that accepts SPI and returns students whose SPI is greater than entered 
--SPI. 
CREATE OR ALTER FUNCTION FN_STU_SPI
(@SPI DECIMAL(4,2))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE SPI>@SPI)

SELECT * FROM FN_STU_SPI(8)

--5. Create a table valued function that accepts MIN_SPI and MAX_SPI and returns students whose SPI lies 
--between given range. 
CREATE OR ALTER FUNCTION FN_STU_SPI_RANGE
(@MINSPI DECIMAL(4,2),@MAXSPI DECIMAL(4,2))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE SPI BETWEEN @MINSPI AND @MAXSPI)

SELECT * FROM FN_STU_SPI_RANGE(8,9)
--Part – B:  
--6. Create a table valued function that accepts STDID and returns details of that student. 
CREATE OR ALTER FUNCTION FN_STU_ID
(@ID INT)
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE STDID=@ID)


SELECT * FROM FN_STU_ID(101)
--7. Create a table valued function that accepts CITY and returns students whose SPI is greater than 7 from 
--that city. 
CREATE OR ALTER FUNCTION FN_STU_CITY_SPI
(@CITY VARCHAR(30))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE CITY=@CITY AND SPI>7)

SELECT * FROM FN_STU_CITY_SPI('RAJKOT')

--8. Create a table valued function that accepts BRANCH and returns students whose SPI is less than 8 from 
--that branch. 
CREATE OR ALTER FUNCTION FN_STU_BRANCH_SPI
(@BRANCH VARCHAR(30))
RETURNS TABLE
AS
RETURN
(SELECT * FROM STUDENT
WHERE BRANCH=@BRANCH AND SPI<8)

SELECT * FROM FN_STU_BRANCH_SPI('COMPUTER')

--9. Create a table valued function that accepts TOPN and returns top N students based on SPI.
CREATE OR ALTER FUNCTION FN_TOP_STU
(@N INT)
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT SNAME,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT)
SELECT SNAME 
FROM CTE
WHERE DR<=@N)

SELECT * FROM FN_TOP_STU(5)

--10. Create a table valued function that accepts BRANCH and returns highest SPI student from that branch. 
CREATE OR ALTER FUNCTION FN_STU_BRANCH_HIGH
(@BRANCH VARCHAR(30))
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT SNAME,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT
WHERE BRANCH=@BRANCH)
SELECT SNAME 
FROM CTE
WHERE DR=1)

SELECT * FROM FN_STU_BRANCH_HIGH('COMPUTER')
--Part – C:  
--11. Create a table valued function that accepts CITY and returns total students from that city. 
CREATE OR ALTER FUNCTION FN_CITY_TOTAL
(@CITY VARCHAR(30))
RETURNS TABLE
AS
RETURN
(SELECT COUNT(*) CNT FROM STUDENT
WHERE CITY=@CITY)

SELECT * FROM FN_CITY_TOTAL('RAJKOT')

--12. Create a table valued function that accepts BRANCH and returns students ordered by SPI in descending 
--order. 
CREATE OR ALTER FUNCTION FN_BRANCH_ORDER_SPI
(@BRANCH VARCHAR(30))
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT SNAME,SPI,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT
WHERE BRANCH=@BRANCH)
SELECT SNAME,SPI FROM CTE
)

SELECT * FROM FN_BRANCH_ORDER_SPI('COMPUTER')
--13. Create a table valued function that accepts CITY and returns top 3 student from that city based on SPI.
CREATE OR ALTER FUNCTION FN_TOP3_STU_CITY
(@CITY VARCHAR(30))
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT SNAME,SPI,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT
WHERE CITY=@CITY
)
SELECT SNAME,SPI
FROM CTE
WHERE DR<=3
)

SELECT * FROM FN_TOP3_STU_CITY('RAJKOT')

--14. Create a table valued function that accepts STDID and returns student rank based on SPI (RANK).
CREATE OR ALTER FUNCTION FN_STU_RANK
(@ID INT)
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT STDID,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT
)
SELECT DR
FROM CTE
WHERE STDID=@ID
)

SELECT * FROM FN_STU_RANK(102)

--15. Create a table valued function that accepts BRANCH and returns students having second highest SPI 
--from that branch.
CREATE OR ALTER FUNCTION FN_SECOND_BRANCH
(@BRANCH VARCHAR(30))
RETURNS TABLE
AS
RETURN
(WITH CTE AS
(SELECT SNAME,DENSE_RANK() OVER(ORDER BY SPI DESC) DR
FROM STUDENT
WHERE BRANCH=@BRANCH
)
SELECT SNAME
FROM CTE
WHERE DR=2
)

SELECT * FROM FN_SECOND_BRANCH('COMPUTER')