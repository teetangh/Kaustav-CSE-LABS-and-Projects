-- cl scr;

-- set linesize 170;

-- cl scr;

-- SELECT * FROM tab;

CREATE TABLE instructor (
    ID char(5),
    name VARCHAR2(20),
    dept_name varchar2(20),
    salary numeric(8, 2)
);

CREATE TABLE student (
    ID varchar2(5),
    name varchar2(20) not NULL,
    dept_name varchar(20),
    tot_cred numeric(30),
    primary key ID,
    foreign key (dept_name) REFERENCES department
);

CREATE TABLE takes (
    ID varchar2(5),
    course_ID varchar2(8),
    sec_id varchar2(8),
    semester varchar2(6),
    year numeric(4, 0),
    grade varchar2(2),
    primary key(ID, course_id, sec_id, semester, year),
    foreign key(course_id, sec_id, semester, year) references section
);

INSERT INTO instructor
VALUES('10211', 'Smith', 'Biology', 66000);

delete FROM instructor;

-- ------------------------------------------
SELECT owner,
    object_name,
    object_type
FROM ALL_OBJECTS
WHERE owner = 'sys'
    and object_type = 'TABLE';

show user;

SELECT user
FROM dual;

SELECT distinct username
FROM user_users;

------------------------------
@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\DDL+drop.sql";

@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\smallRelationsInsertFile.sql";

SELECT name
FROM instructor;

SELECT DISTINCT dept_name
FROM instructor;

SELECT All dept_name
FROM instructor;

SELECT *
FROM instructor;

SELECT 'A'
FROM instructor;

SELECT ID,
    name,
    salary / 12
FROM instructor;

SELECT ID,
    name,
    salary / 12 as monthly_salary
FROM instructor;

-- Use single quotes not double quotes
SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.';

SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.'
    and salary > 80000;

SELECT *
FROM instructor,
    teaches;

SELECT *
FROM instructor,
    teaches
WHERE instructor.ID = teaches.ID;

SELECT *
FROM instructor,
    teaches
WHERE instructor.dept_name = 'Comp. Sci.'
    and instructor.ID = teaches.ID;

-- as keyword doesnt work in oracle sql
SELECT distinct T.name
FROM instructor T,
    instructor S
WHERE T.salary > S.salary
    and S.dept_name = 'Comp. Sci.';

SELECT *
FROM instructor I
WHERE I.name like '%sa%';

SELECT distinct name
FROM instructor
order by name desc;

cl scr;

SELECT distinct name,
    dept_name
FROM instructor
order by name,
    dept_name;

cl scr;

SELECT name
FROM instructor
WHERE salary between 90000 and 100000;

cl scr;

SELECT name,
    course_id
FROM instructor,
    teaches
WHERE instructor.id = teaches.id
    and instructor.dept_name = 'Comp. Sci.';

-- WHERE (instructor.id , dept_name) == (teaches.id , "Comp. Sci.");

cl scr;

(
    SELECT course_id
    FROM section
    WHERE semester = 'Fall'
        and year = 2009
)
UNION
(
    SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and year = 2010
);

(
    SELECT course_id
    FROM section
    WHERE semester = 'Fall'
        and year = 2009
)
INTERSECT
(
    SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and year = 2010
);

(
    SELECT course_id
    FROM section
    WHERE semester = 'Fall'
        and year = 2009
)
MINUS
(
    SELECT course_id
    FROM section
    WHERE semester = 'Spring'
        and year = 2010
);

SELECT distinct T.salary
FROM instructor T,
    instructor S
WHERE T.salary < S.salary;

SELECT name
FROM instructor
WHERE salary is NULL;

(
    SELECT DISTINCT salary
    FROM instructor
)
EXCEPT (
        SELECT distinct T.salary
        FROM instructor T,
            instructor S
        WHERE T.salary < S.salary
    );

-- Aggregate Functions
SELECT avg(salary)
FROM instructor
WHERE instructor.dept_name = 'Comp. Sci.';

SELECT count(DISTINCT ID)
FROM teaches
WHERE semester = 'Spring'
    and year = 2010;

SELECT count(*)
FROM course;

SELECT dept_name,
    avg(salary) as avg_salary
FROM instructor
GROUP BY dept_name;

SELECT dept_name,
    avg(salary) as avg_salary
FROM instructor
GROUP BY dept_name
HAVING AVG(salary) > 42000;

SELECT sum(salary)
FROM instructor;

SELECT DISTINCT course_id
FROM section
WHERE semester = 'Fall'
    and year = '2009'
    AND course_id IN (
        SELECT course_id
        FROM section
        WHERE semester = 'Spring'
            and year = '2010'
    );

SELECT DISTINCT course_id
FROM section
WHERE semester = 'Fall'
    and year = '2009'
    AND course_id NOT IN (
        SELECT course_id
        FROM section
        WHERE semester = 'Spring'
            and year = '2010'
    );

SELECT count(distinct ID)
FROM takes
WHERE (course_id, sec_id, semester, year) IN (
        SELECT course_id,
            sec_id,
            semester,
            year
        FROM teaches
        WHERE teaches.ID = 10101
    );

SELECT DISTINCT T.salary
FROM instructor T,
    instructor S
WHERE T.salary > S.salary
    AND S.dept_name = 'Comp. Sci.';

SELECT name
FROM instructor
WHERE salary > some (
        SELECT salary
        FROM instructor
        WHERE dept_name = 'Comp. Sci.'
    );

SELECT name
FROM instructor
WHERE salary > all (
        SELECT salary
        FROM instructor
        WHERE dept_name = 'Comp. Sci.'
    );

SELECT course_id
FROM section S
WHERE semester = 'Fall'
    AND year = 2009
    AND EXISTS (
        SELECT *
        FROM section T
        WHERE semester = 'Spring'
            AND year = 2010
            AND S.course_id = T.course_id
    );

-- SELECT DISTINCT S.ID,
--     S.name
-- FROM student S
-- WHERE NOT EXISTS (
--         (
--             SELECT course_id
--             FROM course
--             WHERE dept_name = 'Comp. Sci.'
--         )
--         EXCEPT (
--                 SELECT T.course_id
--                 FROM takes T
--                 WHERE S.ID = T.ID
--             )
--     );

SELECT *
FROM student S
WHERE NOT EXISTS (
        (
            SELECT T.course_id
            FROM takes T
            WHERE S.ID = T.ID
        )
        MINUS
        (
            SELECT course_id
            FROM course
            WHERE dept_name = 'Comp. Sci.'
        )
    );

-- SELECT T.course_id
-- FROM course T
-- WHERE 1 > (
--         SELECT R.course_id
--         FROM section R
--         WHERE T.course_id = R.course_id
--             AND R.year = 2009
--     );

-- Subqueries in the FROM CLAUSE
SELECT dept_name,
    avg_salary
FROM (
        SELECT dept_name,
            avg(salary) as avg_salary
        FROM instructor
        GROUP BY dept_name
    )
WHERE avg_salary > 42000;

SELECT dept_name,
    avg_salary
FROM (
        SELECT dept_name,
            avg(salary)
        FROM instructor
        GROUP BY dept_name
    ) as dept_avg(dept_name, avg_salary)
WHERE avg_salary > 42000;

-- WITH CLAUSE
-- be careful with dept_name
WITH max_budget(value) as (
    SELECT max(budget)
    FROM department
)
SELECT department.dept_name
FROM department,
    max_budget
WHERE department.budget = max_budget.value;

WITH dept_total(dept_name, value) as (
    SELECT dept_name,
        sum(salary)
    FROM instructor
    GROUP BY dept_name
),
dept_total_avg(value) as (
    SELECT avg(value)
    FROM dept_total
)
SELECT dept_name
FROM dept_total,
    dept_total_avg
WHERE dept_total.value > dept_total_avg.value;

SELECT dept_name,
    (
        SELECT COUNT(*)
        FROM instructor
        WHERE department.dept_name = instructor.dept_name
    )
FROM department;

-- Delete rows from table 'INSTRUCTOR'
DELETE FROM INSTRUCTOR
WHERE dept_name = 'Finance';

DELETE FROM INSTRUCTOR
WHERE dept_name IN (
        SELECT dept_name
        FROM department
        WHERE building = 'Watson'
    );

-- Delete rows from table 'instructor'
DELETE FROM instructor
WHERE salary < (
        SELECT avg(salary)
        FROM instructor
    );

-- Insert rows into table 'course'
INSERT INTO course (
        -- columns to insert data into
        course_id,
        title,
        dept_name,
        credits
    )
VALUES (
        -- first row: values for the columns in the list above
        'CS-437',
        'Database Systems',
        'Comp. Sci.',
        4
    );

INSERT into STUDENT
VALUES ('3003', 'Green', 'Finance', null);

INSERT into STUDENT
SElECT ID,
    name,
    dept_name,
    0
FROM instructor;

UPDATE instructor
SET salary = salary * 1.03
WHERE salary > 100000;

UPDATE instructor
SET salary = salary * 1.05
WHERE salary <= 100000;

UPDATE instructor
SET salary = case
        WHEN salary <= 100000 then SALARY * 1.05
        ELSE salary * 1.03
    END;

UDPATE student S
SET tot_cred = (
        SELECT sum(credits)
        FROM takes,
            course
        WHERE takes.course_id = course.course_id
            AND S.ID = takes.ID
            AND takes.grade <> 'F'
            AND takes.grade IS NOT NULL
    );

-- Views
@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\DDL+drop.sql";

@"C:\Users\Kaustav\Desktop\MY CODE\All Kaustav Labs Latest\KaustavLABS2 06 Jan 2019\DBMS LAB\Main University Files\University DB\smallRelationsInsertFile.sql";

create VIEW faculty as
SELECT ID,
    name,
    dept_name
FROM instructor;

SELECT name
FROM faculty
WHERE dept_name = 'Comp. Sci.';

CREATE VIEW departments_total_salary(dept_name, total_salary) as
SELECT dept_name,
    sum(salary)
FROM instructor
GROUP BY dept_name;

-- select owner as schema_name, 
--        view_name
-- from sys.all_views
-- order by owner, 
--          view_name;

-- select owner as schema_name, 
--        view_name
-- from sys.dba_views
-- order by owner, 
--          view_name;

CREATE view physics_fall_2009 as
SELECT course.course_id,
    sec_id,
    building,
    room_number
FROM course,
    section
WHERE course.course_id = section.course_id
    AND course.dept_name = 'Physics'
    AND section.semester = 'Fall'
    AND section.year = '2009';

CREATE view physics_fall_2009_watson as
SELECT course_id,
    room_number
FROM physics_fall_2009
WHERE building = 'Watson';

CREATE VIEW physics_fall_2008_watson_another as (
    SELECT course_id,
        room_number
    FROM (
            SELECT course.course_id,
                building,
                room_number
            from course,
                section
            where course.course_id = section.course_id
                and course.dept_name = 'Physics'
                and section.semester = 'Fall'
                and section.year = '2009'
        )
    where building = 'Watson'
);
