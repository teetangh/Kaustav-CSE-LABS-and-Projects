set linesize 250
cl scr

drop table STUDENT cascade constraints;
drop table STUDENTS cascade constraints;

create table STUDENT(reg_no number(5),stu_name varchar2(20),stu_age number(5),stu_dob date,subject1_marks number(4,2),subject2_marks number(4,2),subject3_marks number(4,1));


select * from STUDENT;

alter table STUDENT add(Gender char(7));
alter table student add(dept_name varchar2(20));

alter table student drop column Gender;

describe student

alter table student modify(stu_age number(3));


rename student to students;
insert into STUDENTS values (101,'AAA',16,'03-jul-88',80,90,98,'History');
insert into STUDENTS values (102,'BBB',17,'28-jun-89',81,92,97,'Bio');
insert into STUDENTS values (103,'CCC',18,'28-may-78',82,91,95,'History');
insert into STUDENTS values (104,'DDD',19,'19-feb-98',83,93,93,'CSE');
insert into STUDENTS values (105,'EEE',20,'12-jan-18',84,94,91,'ECE');
insert into STUDENTS values (106,'FFF',21,'10-mar-98',86,95,96,'MECH');

select subject1_marks + subject2_marks + subject3_marks tot_marks from STUDENTS;


select * from STUDENTS;

-- 

    DECLARE 
        dname CONSTANT student.dept_name%type := 'History';
    BEGIN
        DELETE FROM STUDENT where dept_name = dname;
        IF SQL%FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Delete succeeded for department: '|| dname) 