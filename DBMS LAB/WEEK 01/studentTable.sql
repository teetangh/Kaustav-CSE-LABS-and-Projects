create table STUDENT(reg_no number(5),stu_name varchar2(20),stu_age number(5),stu_dob date,subject1_marks number(4,2),subject2_marks number(4,2),subject3_marks number(4,1));

insert into STUDENT values (101,'AAA',16,'03-jul-88',80,90,98);

select * from STUDENT;

alter table student add(Gender char(7));

alter table student drop column Gender;

describe student

alter table student modify(stu_age number(3));

rename student to students;

describe students

select * from students;

Truncate table students;

delete from students;

drop table students;

select * from tab;



show linesize;

set linesize 120;

show linesize;


create table STUDENT(reg_no number(5),stu_name varchar2(20),stu_age number(5),stu_dob date,subject1_marks number(4,2),subject2_marks number(4,2),subject3_marks number(4,1));

insert into STUDENT values (101,'AAA',16,'03-jul-88',80,90,98);

select subject1_marks + subject2_marks + subject3_marks tot_marks from student;

insert into student(reg_no,stu_name)values(102,'KRISH');

select * from student;

delete from student where reg_no = 102;

delete from STUDENT;

insert into STUDENT values (101,'AAA',16,'03-jul-88',80,90,98);

insert into student(reg_no,stu_name)values(102,'KRISH');

delete from student where reg_no = 102;

update STUDENT set stu_name='MANAV';

update STUDENT set stu_name='YADAV' where reg_no=101;

commit;