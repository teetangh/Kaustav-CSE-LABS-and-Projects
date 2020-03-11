set linesize 250
cl scr

drop table STUDENT cascade constraints;

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


SELECT * FROM STUDENT;

-- PL SQL BASIC QUERIES

    -- problem 1
    SET SERVEROUTPUT ON
    DECLARE 
        dname CONSTANT STUDENT.dept_name%type := 'History';
    BEGIN
        DELETE FROM STUDENT WHERE dept_name = dname;
        IF SQL%FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Delete succeeded for department: '|| dname);
        ELSE
            DBMS_OUTPUT.PUT_LINE('No STUDENT of department');
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
    BEGIN
    END
    /




