-- @C:\Users\student.OSLAB-1031\Desktop\DBSLab\UniversityDB\DDL+drop.sql
-- @C:\Users\student.OSLAB-1031\Desktop\DBSLab\UniversityDB\smallRelationsInsertFile.sql

-- q9
select name,dept_name
from student;

-- q10
select name
from instructor
where dept_name='Comp. Sci.';

-- q11
select title
from course
where credits = '3';

-- q12
select T.course_id , C.title
from takes T, course C
where T.course_id = C.course_id and id='12345';

-- q13
select name
from instructor
where salary between 40000 and 90000;

-- q14
select instructor.id
from instructor
where instructor.ID not in (select teaches.id
from teaches);

-- q15(not sure)
select student.name, course.title, takes.year
from student, course, takes, course, Section
where student.id = takes.id and takes.year = Section.year and course.course_id = takes.course_id and section.roomnumber='303';


-- q16
select name,T.course_id,title as c_name
from student S, takes T ,course C
where S.ID = T.ID and year = 2010 and T.course_id = C.course_id;

-- q17
select I1.name ,I1.salary as inst_salary 
from instructor I1
where I1.salary > some
(select  I2.salary
from instructor I2
where I2.dept_name = 'Comp. Sci.');

-- q18
select name
from instructor
where dept_name like '%ch%';

-- q19
select S.name,length(S.name)
from student S;

-- q20
select D.dept_name,substr(D.dept_name,3,3) as Substring
from department D;

-- q21
select upper(I.name)
from instructor I;
select lower(I.name)
from instructor I;

-- q22
insert into instructor
values(12345,'ABCDE','Comp. Sci.',NULL);

select name,dept_name,nvl(salary,1) as myoutput
from instructor 
order by name;


-- q23
select I.name,I.salary,ROUND(((I.salary)/3),-2) as Rounded_Salary
from instructor I;


-- q24
create table employee(emp_no number(5),emp_name varchar2(20),emp_address varchar2(50));

insert into employee values (1,'Kaustav','Gurgaon,India');
insert into employee values (2,'Karan','Bangalore,India');
insert into employee values (3,'Ranjan','Bangalore,India');
insert into employee values (4,'Ashray','Mangalore,India');
insert into employee values (5,'Sahaj','Manipal,India');


