--Part – A:  
--1. Implement scalar function to return "Welcome to DBMS Lab". 
CREATE OR ALTER FUNCTION FN_WELCOME()
RETURNS VARCHAR(30)
AS
BEGIN
RETURN 'WELCOME TO DBMS LAB'
END

--2. Implement scalar function to calculate simple interest. 
CREATE OR ALTER FUNCTION FN_SIMPLE_INTEREST
(@P DECIMAL(4,2),@R DECIMAL(4,2),@T DECIMAL(4,2))
RETURNS DECIMAL(5,2)
AS
BEGIN
RETURN (@P*@R*@T)/100
END

--3. Implement scalar function to find difference in days between two dates. 
CREATE OR ALTER FUNCTION FN_DATE_DIFF
(@D1 DATETIME,@D2 DATETIME)
RETURNS INT
AS
BEGIN
RETURN ABS(DATEDIFF(DAY,@D1,@D2))
END

SELECT DBO.FN_DATE_DIFF(12-09-2026,25-09-2026)

--4. Implement scalar function to check whether number is odd or even. 
CREATE OR ALTER FUNCTION FN_ODD_EVEN
(@NUM INT)
RETURNS VARCHAR(30)
AS
BEGIN
IF(@NUM%2=0)
RETURN 'EVEN'
ELSE
RETURN 'ODD'
RETURN NULL
END

SELECT DBO.FN_ODD_EVEN(7)

--5. Implement scalar function to print numbers from 1 to N. 
CREATE OR ALTER FUNCTION FN_PRINT_N
(@N INT)
RETURNS VARCHAR(100)
AS
BEGIN
DECLARE @ANS VARCHAR(100),@I INT=1
WHILE (@I<=@N)
BEGIN
SET @ANS =CONCAT_WS(',',@ANS,@I)
SET @I=@I+1
END
RETURN @ANS
END

SELECT DBO.FN_PRINT_N(10)
 
--Part – B:  
--6. Implement scalar function to calculate factorial of given number. 
CREATE OR ALTER FUNCTION FN_FACTORIAL
(@N INT)
RETURNS INT
AS
BEGIN
DECLARE @I INT=1,@ANS INT=1
WHILE (@I<=@N)
BEGIN
SET @ANS=@ANS*@I
SET @I=@I+1
END
RETURN @ANS
END

SELECT DBO.FN_FACTORIAL(5)

--7. Implement scalar function to check palindrome number. 
CREATE OR ALTER FUNCTION FN_PALINDROME
(@N INT)
RETURNS VARCHAR(30)
AS
BEGIN
IF @N = REVERSE(@N)
RETURN 'PALINDROME'
ELSE 
RETURN 'NOT PALINDROME'
RETURN NULL
END

SELECT DBO.FN_PALINDROME(1221)

--8. Implement scalar function to find maximum of three numbers.
CREATE OR ALTER FUNCTION FN_MAX_THREE
(@N1 INT,@N2 INT,@N3 INT)
RETURNS INT
AS
BEGIN
DECLARE @MAX INT
IF @N1>@N2 AND @N1>@N3
SET @MAX=@N1
ELSE IF @N2>@N3
SET @MAX=@N2
ELSE 
SET @MAX=@N3
RETURN @MAX
END

SELECT DBO.FN_MAX_THREE(12,4,8)

--9. Implement scalar function to calculate square and cube of a number. 
CREATE OR ALTER FUNCTION FN_SQ_CUBE


--From the table EMPLOYEE perform the following queries:  
--Part – C:  
--10. Implement scalar function to return employee full details using EID. 
--11. Implement scalar function to return highest salary from a given department. 
--12. Implement scalar function to count total employees in EMPLOYEE table. 
--13. Implement scalar function to find total experience of employee using JoiningYear. 
--14. Implement scalar function to return total number of employees in a given department. 
--15. Implement scalar function to count total employees from a given city. 