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

alter table employee add Emp_DOB DATE ;

update employee set Emp_DOB = '04-FEB-20';

SELECT TO_CHAR( Emp_DOB, 'DD-MON-YYYY' ) FROM employee;
SELECT TO_CHAR( Emp_DOB, 'DD-MON-YY' ) FROM employee;
SELECT TO_CHAR( Emp_DOB, 'DD-MM-YY' ) FROM employee;

-- q25
select TO_CHAR(Emp_DOB,'YEAR') from employee;
select TO_CHAR(Emp_DOB,'Year') from employee;
select TO_CHAR(Emp_DOB,'year') from employee;

-- q26
select TO_CHAR(Emp_DOB,'DAY') from employee;
select TO_CHAR(Emp_DOB,'Day') from employee;

-- q27
select TO_CHAR(Emp_DOB,'MONTH') from employee;
select TO_CHAR(Emp_DOB,'Month') from employee;

-- q28
select last_day(Emp_DOB) from employee where emp_no = 1;
select TO_CHAR(last_day(Emp_DOB),'DAY') from employee where emp_no = 1;

-- q29
select emp_name,ROUND((sysdate -Emp_DOB )/365)as Emp_age
from employee;

-- q30
select emp_name,next_day(add_months(Emp_DOB,60*12),'Saturday') as result
from employee;

-- q31
select emp_name,Emp_DOB
from employee
where extract(year from Emp_DOB) = 2020;

-- q32
select emp_name,Emp_DOB
from employee
where extract(year from Emp_DOB) between 2019 and 2021;

-- q33
select emp_name,Emp_DOB
from employee
where (extract(year from Emp_DOB)) + 60 = 2080;




