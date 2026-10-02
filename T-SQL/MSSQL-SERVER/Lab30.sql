--Part – A: 
--1. Handle Divide by Zero Error and Print message like: Error occurs that is - Divide by zero error. 
BEGIN TRY
DECLARE @N1 INT = 5
DECLARE @N2 INT = @N1/0
END TRY
BEGIN CATCH
PRINT 'Error occurs that is - Divide by zero error'
END CATCH

--2. Try to convert string to integer and handle the error using try…catch block. 
BEGIN TRY
DECLARE @NUM INT = CAST('HELLO' AS varchar)
END TRY
BEGIN CATCH
PRINT 'CANNOT CONVERT STRING TO NUMBER'
END CATCH

--3. Create a procedure that prints the sum of two numbers: take both numbers as integer & handle 
--exception with all error functions if any one enters string value in numbers otherwise print result. 
CREATE OR ALTER PROC TWOSUM
@N1 INT,@N2 INT
AS
BEGIN
BEGIN TRY 
DECLARE @RES INT = @N1+@N2
PRINT 'ANS IS '+ CAST(@RES AS VARCHAR)
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_PROCEDURE() ERR_PROC
END CATCH
END

EXEC TWOSUM 4, 'P'

--4. Handle a Primary Key Violation while inserting data into STUDENT_INFO table and print the error 
--details such as the error message, error number, severity, and state. 
BEGIN TRY
INSERT INTO STUDENT_INFO
VALUES(105,'MEET','ME')
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_SEVERITY() ERR_SVRTY,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH

--5. Throw custom exception using stored procedure which accepts RNO as input & that throws Error like 
--no RNO is available in database. 
CREATE OR ALTER PROC ACC_RNO
@RNO INT
AS
BEGIN
BEGIN TRY
THROW 50001,'NO RNO IS AVAILABLE IN DATABASE',2
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH
END

EXEC ACC_RNO 122
--Part – B 
--6. Create a stored procedure to update employee SALARY and throw custom exception if salary is 
--negative or zero (Use EMPLOYEE Table). 
CREATE PROC DISP_SAL
@SALARY INT
AS
BEGIN 
BEGIN TRY
IF @SALARY<=0
THROW 50002,'SALARY CANNOT BE NEGATIVE OR ZERO',2
ELSE
BEGIN
UPDATE EMPLOYEE
SET SALARY=@SALARY
END
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH
END

EXEC DISP_SAL -10000

--7. Handle a Foreign Key Violation while inserting data into RESULT table and print appropriate error 
--message (Use RESULT Table). 
BEGIN TRY
INSERT INTO RESULT
VALUES(17,9,120)
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH

--8. Handle Invalid Date Format while inserting data into DEPOSIT table. 
BEGIN TRY
INSERT INTO DEPOSIT
VALUES()
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH

--9. Create a stored procedure that validates gender column and throws error if value is other than male or 
--female (Use EMPLOYEE Table). 
CREATE OR ALTER PROC 

--10. Create a stored procedure that accepts joiningyear and throws custom exception if entered year is 
--greater than current year (Use EMPLOYEE Table). 
CREATE OR ALTER PROC JOINYEAR_VALIDATE
@YEAR INT
AS
BEGIN
BEGIN TRY
IF @YEAR > DATEPART(YEAR,GETDATE())
THROW 50003,'JOINING YEAR CANNOT BE GREATER THAN CURRENT YEAR',3
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH
END

EXEC JOINYEAR_VALIDATE 2027
--Part – C 
--10. Create a stored procedure to delete employee record and handle exception if employee does not exist. 
CREATE OR ALTER PROC DELETE_EMP
@ID INT
AS
BEGIN
BEGIN TRY
DELETE FROM EMPLOYEE
WHERE EID=@ID
END TRY
BEGIN CATCH
SELECT ERROR_MESSAGE() ERR_MSG,ERROR_LINE() ERR_LINE,ERROR_NUMBER() ERR_NM,ERROR_STATE() ERR_STATE
END CATCH
END

EXEC DELETE_EMP 123
--11. Create a stored procedure that throws custom exception if department name is NULL during insertion.