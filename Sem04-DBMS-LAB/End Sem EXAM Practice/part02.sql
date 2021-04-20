set linesize 200;

cl scr;

CREATE table EMPLOYEE
(
    emp_no numeric(5),
    emp_name varchar2(20),
    emp_address varchar2(50)
);

INSERT INTO EMPLOYEE
VALUES(1, 'Kaustav', 'Gurgaon,India');

INSERT INTO EMPLOYEE
VALUES(2, 'Karan', 'Bangalore,India');

INSERT INTO EMPLOYEE
VALUES(3, 'Ranjan', 'Bangalore,India');

INSERT INTO EMPLOYEE
VALUES(4, 'Ashray', 'Mangalore,India');

INSERT INTO EMPLOYEE
VALUES(5, 'Sahaj', 'Manipal,India');

SELECT *
FROM EMPLOYEE;

SELECT *
FROM EMPLOYEE
WHERE emp_address like '%Manipal%';

ALTER TABLE EMPLOYEE
ADD
(salary numeric
(6));

UPDATE EMPLOYEE
SET salary = 700000
where emp_no = 1;

UPDATE EMPLOYEE
SET salary = 800000
where emp_no = 2;

UPDATE EMPLOYEE
SET salary = 100000
where emp_no = 3;

UPDATE EMPLOYEE
SET salary = 200000
where emp_no = 4;

UPDATE EMPLOYEE
SET salary = 300000
where emp_no = 5;

DELETE FROM EMPLOYEE
WHERE emp_address like 'Mangalore%';

-- RENAME EMPLOYEE TO EMPLOYEE_DATA;

-- DROP TABLE EMPLOYEE_DATA;

set linesize 100;

cl scr;

DROP TABLE EMPLOYEE
CASCADE CONSTRAINTS;

DROP TABLE DEPARTMENT
CASCADE CONSTRAINTS;

CREATE TABLE EMPLOYEE
(
    EmpNo NUMERIC(5) NOT NULL,
    EmpName VARCHAR2(20) NOT NULL,
    Gender VARCHAR2(2) NOT NULL,
    Salary NUMERIC(5) NOT NULL,
    Address VARCHAR2(20) NOT NULL,
    Dno NUMERIC(3)
);

CREATE TABLE DEPARTMENT
(
    DeptNo NUMERIC(3) PRIMARY KEY,
    DeptName VARCHAR2(10) UNIQUE,
    Location VARCHAR2(20)
);

ALTER TABLE EMPLOYEE
ADD CONSTRAINT Emp_pk PRIMARY KEY(EmpNo);

ALTER TABLE EMPLOYEE
ADD CONSTRAINT Gen_Check CHECK(
        Gender = 'M'
        or Gender = 'F'
    );

TRUNCATE TABLE EMPLOYEE;

TRUNCATE TABLE DEPARTMENT;

INSERT INTO EMPLOYEE
VALUES(
        111,
        'Kaustav',
        'M',
        11111,
        'Gurgaon,India',
        100
);

INSERT INTO EMPLOYEE
VALUES(222, 'Sameer', 'M', 22222, 'Ranchi,India', 200);

INSERT INTO EMPLOYEE
VALUES(
        333,
        'Ramu Kaka',
        'M',
        33333,
        'Gurgaon,India',
        300
);

INSERT INTO DEPARTMENT
VALUES(100, 'CSE', 'Manipal');

INSERT INTO DEPARTMENT
VALUES(111, 'Kaustav', 'Manipal');

SELECT *
FROM EMPLOYEE;

SELECT *
FROM DEPARTMENT;

TRUNCATE TABLE EMPLOYEE;

TRUNCATE TABLE DEPARTMENT;

ALTER TABLE EMPLOYEE DROP CONSTRAINT Dno_FK;

ALTER TABLE EMPLOYEE
ADD CONSTRAINT Dno_FK FOREIGN KEY(DNO) REFERENCES DEPARTMENT(DeptNo) ON DELETE CASCADE;

SELECT name,
    dept_name
FROM STUDENT;

SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.';

SELECT course_id
FROM COURSE
WHERE credits = '3';

SELECT T.course_id,
    C.title
FROM takes T,
    course C
WHERE T.course_id = C.course_id
    AND id = '12345';

SELECT *
FROM INSTRUCTOR
WHERE SALARY BETWEEN 40000 AND 90000;

SELECT instructor.id
FROM instructor
WHERE instructor.id NOT IN (
        SELECT ID
FROM teaches
    );

SELECT student.name,
    course.title,
    takes.year,
    section.room_number
FROM student,
    course,
    takes,
    section
WHERE student.id = takes.id
    AND takes.year = section.year
    AND course.course_id = takes.course_id
    AND section.room_number = '514';

SELECT name,
    T.course_id,
    title as c_name
FROM student S,
    takes T,
    course C
WHERE S.ID = T.ID
    AND year = 2010
    AND T.course_id = C.course_id;

SELECT I1.name,
    I1.salary as inst_salary
FROM instructor I1
WHERE I1.salary > SOME (
        SELECT I2.salary
FROM instructor I2
WHERE I2.dept_name = 'Comp. Sci.'
    );

SELECT instructor.name
FROM instructor
WHERE instructor.dept_name like '%ch%'
SELECT student.name,
    LENGTH(student.name)
FROM student;

SELECT D.deptname,
    SUBSTR(D.deptname, 3, 3) as subtring
FROM department D;

SELECT upper(I.name)
FROM instructor I;

INSERT INTO instructor
VALUES(12345, 'ABCDE', 'Comp. Sci.', NULL);

SELECT name,
    dept_name,
    nvl(salary, 1) as my_output
FROM instructor
ORDER BY name;

SELECT instructor.salary,
    ROUND((instructor.salary / 3), -2) as rounded_salary
FROM instructor;

DROP TABLE EMPLOYEE
CASCADE CONSTRAINTS;

CREATE table EMPLOYEE
(
    emp_no numeric(5),
    emp_name varchar2(20),
    emp_address varchar2(50)
);

INSERT INTO EMPLOYEE
VALUES(1, 'Kaustav', 'Gurgaon,India');

INSERT INTO EMPLOYEE
VALUES(2, 'Karan', 'Bangalore,India');

INSERT INTO EMPLOYEE
VALUES(3, 'Ranjan', 'Bangalore,India');

INSERT INTO EMPLOYEE
VALUES(4, 'Ashray', 'Mangalore,India');

INSERT INTO EMPLOYEE
VALUES(5, 'Sahaj', 'Manipal,India');

ALTER TABLE EMPLOYEE
ADD Emp_DOB DATE;

UPDATE EMPLOYEE
SET Emp_DOB = '04-Feb-89';

-- SELECT sysdate FROM dual;

-- ALTER SESSION SET nls_date_format = 'dd-mon-yyyy hh24:mi:ss';

-- SELECT sysdate FROM dual;

SELECT TO_CHAR(Emp_DOB, 'DD-MON-YYYY')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'DD-MON-YY')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'DD-MM-YYYY')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'YEAR')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'Year')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'year')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'Day')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'day')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'Month')
FROM EMPLOYEE;

SELECT TO_CHAR(Emp_DOB, 'month')
FROM EMPLOYEE;

SELECT last_day(Emp_DOB)
FROm EMPLOYEE
where Emp_no = 1;

SELECT TO_CHAR(last_day(Emp_DOB), 'DAY')
FROM EMPLOYEE
where Emp_no = 1;

SELECT Emp_name,
    ROUND((sysdate - Emp_DOB) / 365) as Emp_age
FROM Employee;

SELECT Emp_name,
    next_day(add_months(Emp_DOB, 60 * 12), 'Saturday')
FROM EMPLOYEE;

SELECT emp_name,
    Emp_DOB
FROM EMPLOYEE
WHERE EXTRACT(
        YEAR
        FROM Emp_DOB
    ) = 1989;

SELECT emp_name,
    Emp_DOB
FROM EMPLOYEE
WHERE EXTRACT(
        YEAR
        FROM Emp_DOB
    ) between 1980 and 1990;

SELECT emp_name,
    Emp_DOB
FROM EMPLOYEE
WHERE EXTRACT(
        YEAR
        FROM Emp_DOB
    ) + 60 = 2049;

@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\DDL+drop.sql";

@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\smallRelationsInsertFile.sql";

    SELECT course_id
    FROM section
    WHERE semester = 'Fall'
        and year = 2009
UNION
    SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and year = 2010;

    SELECT course_id
    FROM section
    WHERE semester = 'Fall'
        and year = 2009
INTERSECT
    SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and year = 2010;

SELECT course_id
FROM section
WHERE semester = 'Fall'
    and year = 2009
MINUS
SELECT course_id
FROM section
WHERE semester = 'Spring'
    and year = 2010;

SELECT title
FROM course
WHERE course_id NOT IN (
        SELECT course_id
FROM takes
    );

SELECT course_id
FROM section
WHERE semester = 'Fall'
    AND year = 2009
    AND course_id IN (
        SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        AND year = 2010
    );

SELECT DISTINCT course_id
FROM section
WHERE semester = 'Fall'
    and YEAR = 2009
    and course_id NOT IN (
        SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and YEAR = 2010
    );

SELECT S.name
FROM student S
WHERE S.name IN (
        SELECT I.name
FROM instructor I
    );

SELECT *
FROM instructor A
WHERE A.salary > some (
        SELECT salary
FROM instructor B
WHERE B.dept_name = 'Comp. Sci.'
    );

SELECT *
FROM instructor A
WHERE A.salary > all (
        SELECT salary
FROM instructor B
WHERE B.dept_name = 'Comp. Sci.'
    );

SELECT A.dept_name,
    avg(A.salary)
FROM instructor A
GROUP BY A.dept_name
HAVING avg(A.salary) >= all (
        SELECT B.dept_name,
    avg(B.salary)
FROM instructor B
GROUP BY B.dept_name
    );

-- SELECT DISTINCT S.ID, S.name
-- FROM student S
-- WHERE NOT EXISTS (
--       (
--     SELECT course_id
--     FROM course
--     where dept_name = 'Comp. Sci.'
--     )
-- MINUS
-- (
--     SELECT course_id
--     FROM takes T
--     WHERE T.ID = S.ID
--     )
-- );

SELECT T.course_id
FROM course T
WHERE 1>=
(SELECT count(R.course_id)
FROM section R
WHERE R.year = 2009 and R.course_id = T.courseId);

SELECT name 
FROM student S , takes T , course C
WHERE

SELECT dept_name , count(ID)
FROM student
GROUP BY dept_name
HAVING count(ID) > 1;