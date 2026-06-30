-- LAB-3 EXTRA QUESTIONS
-- 1. Display all students whose city is ‘RAJKOT’ and branch is ‘COMPUTER’.
SELECT *
FROM STUDENT
WHERE CITY = 'RAJKOT' AND BRANCH = 'COMPUTER'

-- 2. Retrieve names and SPI of students whose SPI is less than 7.00.
SELECT SNAME , SPI
FROM STUDENT
WHERE SPI <7.00;

-- 3. Display all details of students whose ID is between 103 and 107.
SELECT *
FROM STUDENT
WHERE STDID BETWEEN 103 AND 107;

-- 4. Retrieve Student ID, Name, and Branch of students whose branch is ‘MECHANICAL’.
SELECT STDID, SNAME , BRANCH
FROM STUDENT
WHERE BRANCH = 'MECHANICAL';

-- 5. Display all records where the city is not ‘SURAT’.
SELECT *
FROM STUDENT
WHERE CITY <> 'SURAT';

-- 6. Display names of students whose branch is either ‘ELECTRICAL’ or ‘MECHANICAL’.
SELECT SNAME
FROM STUDENT
WHERE BRANCH IN ('ELECTRICAL','MECHANICAL');

-- 7. Retrieve all students whose SPI is not between 6.0 and 8.0.
SELECT *
FROM STUDENT
WHERE NOT SPI BETWEEN 6.0 AND 8.0;

-- 8. Display details of students whose city is NULL.
SELECT *
FROM STUDENT
WHERE CITY IS NULL;

-- 9. Display all students whose SPI is greater than 8.0 and who do not belong to either COMPUTER or
-- CIVIL branch.
SELECT *
FROM STUDENT
WHERE SPI >8.0 AND NOT BRANCH IN ('COMPUTER','CIVIL');

-- 10. Display all students whose branch is NULL and whose city is not NULL.
****
SELECT *
FROM STUDENT
WHERE BRANCH IS NULL AND CITY IS NOT NULL;

-- 11. Retrieve students whose SPI is greater than 7.5 and less than 9.0 but whose IDs are not between
-- 104 and 108.
SELECT *
FROM STUDENT
WHERE SPI >7.5 AND SPI <9.0 AND (NOT STDID BETWEEN 104 AND 108);

-- 12. Retrieve all records where the city is RAJKOT and the branch is not COMPUTER.
SELECT *
FROM STUDENT
WHERE CITY = 'RAJKOT' AND BRANCH != 'COMPUTER';

-- 13. Display students whose IDs are not between 102 and 107 and whose SPI is greater than 7.5.
SELECT *
FROM STUDENT
WHERE STDID NOT BETWEEN 102 AND 107 AND SPI >7.5;

-- 14. Retrieve students whose SPI is between 7.0 and 8.5 and who belong to COMPUTER, CIVIL, or
-- MECHANICAL branches.
SELECT *
FROM STUDENT
WHERE SPI BETWEEN 7.0 AND 8.5 AND NOT BRANCH IN ('COMPUTER','CIVIL','MECHANICAL');

-- 15. Display records where the branch is COMPUTER and city is not RAJKOT and SPI is greater than
-- 7.0.
SELECT *
FROM STUDENT
WHERE BRANCH='COMPUTER' AND CITY <> 'RAJKOT' AND SPI >7.0;

-- 16. Retrieve student name and id along with the city whose city is RAJKOT and SPI is less than 8.0, or
-- whose city is SURAT and SPI is greater than 8.0.
SELECT STDID, SNAME, CITY
FROM STUDENT
WHERE (CITY ='RAJKOT' AND SPI <8.0) OR (CITY = 'SURAT' AND SPI >8.0);

-- 17. Display students who belong to COMPUTER branch and have SPI greater than 8.0, or belong to
-- CIVIL branch and have SPI greater than 7.0.
SELECT *
FROM STUDENT
WHERE (BRANCH = 'COMPUTER' AND SPI > 8.0 )OR (BRANCH = 'CIVIL' AND SPI >7.0);

-- 18. Retrieve students whose IDs are in the range 101–110 but not in the range 104–107.
SELECT *
FROM STUDENT
WHERE STDID BETWEEN 101 AND 110 AND NOT STDID BETWEEN 104 AND 107;

-- 19. Display students whose city is RAJKOT and branch is COMPUTER, or whose city is SURAT and
-- branch is CIVIL.
SELECT *
FROM STUDENT
WHERE (CITY ='RAJKOT' AND BRANCH = 'COMPUTER') OR (CITY = 'SURAT' AND BRANCH = 'CIVIL');

-- 20. Retrieve student names whose city is neither RAJKOT nor SURAT.
SELECT SNAME 
FROM STUDENT
WHERE NOT CITY IN('RAJKOT','SURAT');