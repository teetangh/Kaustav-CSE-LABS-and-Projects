set linesize 250
cl scr

drop table STUDENT cascade constraints;
drop table DEPARTMENT cascade constraints;

create table STUDENT(reg_no number(5),stu_name varchar2(20),stu_age number(5),stu_dob date,subject1_marks number(4,2),subject2_marks number(4,2),subject3_marks number(4,1));


SELECT * FROM STUDENT;

alter table STUDENT add(Gender char(7));
alter table STUDENT add(dept_name varchar2(20));

alter table STUDENT drop column Gender;

describe STUDENT

alter table STUDENT modify(stu_age number(3));

insert into STUDENT values (101,'AAA',16,'03-jul-88',80,90,98,'History');
insert into STUDENT values (102,'BBB',17,'28-jun-89',81,92,97,'Bio');
insert into STUDENT values (103,'CCC',18,'28-may-78',82,91,95,'History');
insert into STUDENT values (104,'DDD',19,'19-feb-98',83,93,93,'CSE');
insert into STUDENT values (105,'EEE',20,'12-jan-18',84,94,91,'ECE');
insert into STUDENT values (106,'FFF',21,'10-mar-98',86,95,96,'MECH');

SELECT subject1_marks + subject2_marks + subject3_marks tot_marks FROM STUDENT;



CREATE TABLE DEPARTMENT
(
    dept_name varchar2(10),
    BUDGET NUMERIC(7)
);

INSERT INTO DEPARTMENT values('History',65000);
INSERT INTO DEPARTMENT values('Bio',85000);
INSERT INTO DEPARTMENT values('CSE',95000);
INSERT INTO DEPARTMENT values('ECE',75000);
INSERT INTO DEPARTMENT values('MECH',85000);

CREATE TABLE INSTRUCTOR
(
    ID NUMERIC (5),
    name varchar2(10),
    dept_name varchar2(10),
    salary NUMERIC(7)
);

INSERT INTO INSTRUCTOR values(3000,'abc','History',55000);
INSERT INTO INSTRUCTOR values(3001,'def','Bio',65000);
INSERT INTO INSTRUCTOR values(3002,'ghi','CSE',75000);
INSERT INTO INSTRUCTOR values(3003,'jkl','ECE',85000);
INSERT INTO INSTRUCTOR values(3004,'mno','MECH',95000);


SELECT * FROM STUDENT;
SELECT * FROM DEPARTMENT;


-- PL SQL BASIC QUERIES

    -- problem 1
    SET SERVEROUTPUT ON
    DECLARE 
        dname CONSTANT STUDENT.dept_name%type := 'History';
    BEGIN
        DELETE FROM STUDENT WHERE dept_name = dname;
        IF SQL%FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Delete succeeded for DEPARTMENT: '|| dname);
        ELSE
            DBMS_OUTPUT.PUT_LINE('No STUDENT of DEPARTMENT');
        END IF;
    END;
    /

    -- problem 2
    DECLARE
        dname CONSTANT STUDENT.dept_name%TYPE := 'CSE';
        CURSOR C1 is (SELECT stu_name FROM STUDENT WHERE dept_name = dname);
        sname STUDENT.stu_name%type;
    BEGIN
        DBMS_OUTPUT.PUT_LINE('--------------------');
            OPEN C1;
                LOOP
                    -- fetches student name into variable
                    FETCH c1 into sname;
                    EXIT WHEN c1%NOTFOUND;
                    DBMS_OUTPUT.PUT_LINE(RPAD(('Name: '|| sname),10));
                END LOOP;
            CLOSE C1;
        DBMS_OUTPUT.PUT_LINE('--------------------');
    END;
    /

    -- problem 3
    DECLARE
        CURSOR C1 is SELECT * FROM DEPARTMENT;
        vBudget DEPARTMENT.BUDGET%TYPE := 0;
        vdname DEPARTMENT.dept_name%TYPE := 0;
    BEGIN
        FOR dept in C1
        LOOP
            IF dept.BUDGET > vBudget THEN
                vBudget := dept.BUDGET;
                vdname := dept.dept_name;
            END IF;
        END LOOP;
        DBMS_OUTPUT.PUT_LINE('Max. Budget: '|| vBudget || ' Dept: '|| vdname);
    END;
    /


    -- problem 4
    DECLARE 
        CURSOR C1 is SELECT * FROM DEPARTMENT for UPDATE;
    BEGIN
        for dept in c1
        LOOP 
            IF dept.Budget <= 70000 THEN
                UPDATE DEPARTMENT set Budget = Budget * 1.2 WHERE CURRENT OF C1;
            ELSIF dept.Budget > 70000 AND dept.Budget <= 100000 THEN
                UPDATE DEPARTMENT set Budget = Budget * 1.15 WHERE CURRENT OF C1;
            ELSE
                UPDATE DEPARTMENT set Budget = Budget * 1.1 WHERE CURRENT OF C1;
            END IF;
        END LOOP;
    END;
    /

    SELECT * FROM DEPARTMENT;

    -- problem 5
    DECLARE 
        CURSOR c (dname INSTRUCTOR.dept_name%TYPE) 
        IS
        SELECT * FROM INSTRUCTOR WHERE dept_name = dname;
    BEGIN
        FOR tmp in  C('CSE')
        LOOP
            DBMS_OUTPUT.PUT_LINE(' Emp_No is ' || tmp.ID );
            DBMS_OUTPUT.PUT_LINE(' Emp_Name is ' || tmp.name );
            DBMS_OUTPUT.PUT_LINE(' Emp_Dept is ' || tmp.dept_name );
            DBMS_OUTPUT.PUT_LINE(' Emp_Salary is ' || tmp.salary );
            DBMS_OUTPUT.PUT_LINE(' ------------------- ' );
        END LOOP;
    END;
    /