@"C:\Users\student.OSLAB-1031\Desktop\Kaustav C29\DBMS LAB\Main University Files\University DB\DDL+drop.sql"
@"C:\Users\student.OSLAB-1031\Desktop\Kaustav C29\DBMS LAB\Main University Files\University DB\smallRelationsInsertFile.sql"

SET SERVEROUTPUT ON;

set linesize 250
cl scr


-- q1
    CREATE TABLE salary_raise
    (
        instructor_id numeric(10),
        raise_date date,
        raise_amount numeric(7)
    );