--Implement Advanced Stored Procedures with Conditions and Logic 
-- From the table EMPLOYEE perform the following queries:  
--Part – A:  
--1. Create a stored procedure to generate department-wise salary statistics like total salary, average 
--salary, minimum salary, and maximum salary. (User enter only department name) 
CREATE PROC PR_DEPT_WISE
@DEPT VARCHAR(30)
AS
BEGIN
SELECT @DEPT, SUM(SALARY) TOTAL,AVG(SALARY) AVG_SAL,MIN(SALARY) MIN_SAL,MAX(SALARY) MAX_SAL
FROM EMPLOYEE
WHERE DEPARTMENT=@DEPT
END

EXEC PR_DEPT_WISE 'IT'

--2. Create a stored procedure that accepts a joining year and displays employees who joined that year. 
CREATE PROC PR_EMP_JOIN
@YEAR INT
AS
BEGIN
SELECT FIRSTNAME
FROM EMPLOYEE
WHERE JOININGYEAAR=@YEAR
END

EXEC PR_EMP_JOIN 2024

--3. Create a stored procedure for dynamic employee search using parameters (User may enter partial city 
--name). 
CREATE PROC PR_EMP_SEARCH
@KEYWORD VARCHAR(30) =''
AS
BEGIN
SELECT *
FROM EMPLOYEE
WHERE CITY LIKE '%'+@KEYWORD+'%'
END

EXEC PR_EMP_SEARCH 'RA'

--4. Create a stored procedure that accepts a salary amount and displays employees earning more than the 
--entered salary. 
CREATE PROC PR_EMP_BY_SAL
@SAL DECIMAL(7,2)
AS
BEGIN
SELECT * FROM EMPLOYEE
WHERE SALARY>@SAL
END

EXEC PR_EMP_BY_SAL 10000

--5. Create a stored procedure to display top N highest paid employees from each department (Value of N 
--is entered by user). 
CREATE PROC PR_EMP_N_HIGHEST
@N INT 
AS
BEGIN
WITH CTE
AS
(SELECT FIRSTNAME,DENSE_RANK() OVER(PARTITION BY DEPARTMENT ORDER BY SALARY DESC ) DR
FROM EMPLOYEE)
SELECT FIRSTNAME FROM CTE 
WHERE DR<=@N
END

EXEC PR_EMP_N_HIGHEST 1

--6. Create a stored procedure to increase salary department-wise by a given percentage. (User Enter 
--Department Name and %, e.g. Computer 10). 
CREATE OR ALTER PROC PR_INCREASE_SAL
@DEPT VARCHAR(30),
@PER DECIMAL(4,2)
AS
BEGIN
UPDATE EMPLOYEE
SET SALARY=SALARY+SALARY*@PER/100
WHERE DEPARTMENT=@DEPT
END

EXEC PR_INCREASE_SAL 'ADMIN',10

--7. Create a stored procedure to display employees having experience greater than or equal to the entered 
--years. 
CREATE OR ALTER PROC PR_EMP_BY_EXP
@YEAR INT 
AS
BEGIN
SELECT * FROM EMPLOYEE
WHERE DATEPART(YEAR,GETDATE())-JOININGYEAAR > @YEAR
END

EXEC  PR_EMP_BY_EXP 2

--8. Create a stored procedure that accepts a number as input and displays details of the last N employees 
--who joined the organization. 
CREATE PROC PR_LAST_N_EMP
@N INT
AS
BEGIN
WITH CTE AS
(SELECT FIRSTNAME,ROW_NUMBER() OVER(ORDER BY JOININGYEAAR DESC) RN
FROM EMPLOYEE)
SELECT FIRSTNAME
FROM CTE
WHERE RN<=@N
END

EXEC PR_LAST_N_EMP 5
 
--From the table AUTHOR, PUBLISHER and BOOK perform the following queries:  
--Part – B:  
--9. Create a stored procedure that accepts an author name and displays all books written by that author. 
--10. Create a stored procedure that accepts a publication year and displays books published after that year. 
--11. Create a stored procedure that accepts a country name and displays all authors from that country with 
--their books. 
--12. Create a stored procedure that accepts a number as input and displays the top N most expensive books 
--with author and publisher details. 
 
--Part – C:  
--13. Create a stored procedure that accepts a publisher name and displays the total number of books 
--published by that publisher. 
--14. Create a stored procedure that accepts a price range (Min Price Max Price) and displays books whose 
--prices fall within that range. 
--15. Create a stored procedure that accepts an author ID and deletes all books written by that author. 