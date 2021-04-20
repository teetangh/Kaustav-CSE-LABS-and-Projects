-- UNIVERSITY DB

select name,dept_name
from student;

select *
from instructor I
where I.dept_name = 'Comp. Sci.';

select *
from course C
where C.dept_name = 'Comp. Sci.';

select *
from takes T,course C
where T.course_id = C.course_id and T.ID = 12345;

select *
from instructor 
where salary between 40000 and 90000;

select *
from instructor
where instructor.ID not in 
(
    select teaches.ID
    from teaches    
); 

select student.name,course.title,takes.year
from student ,course ,takes ,section 
where 
student.ID = takes.ID and
takes.year = section.year and
takes.course_id = course.course_id and
section.room_number =  101;

select *
from student,takes,course
where
student.ID = takes.ID and 
takes.course_id = course.course_id and
takes.year = 2010;

select *
from instructor T1
where T1.salary > some
(
    select salary
    from instructor T2
    where T2.dept_name = 'Comp. Sci.'
);


select *
from instructor
where instructor.dept_name like '%a%';


select name,length(name)
from student;


select D.dept_name,substr(D.dept_name,3,3) as Substring
from department D;

select upper(I.name)
from instructor I;
select lower(I.name)
from instructor I;

insert into instructor values
(12345,'ABCDE','Comp. Sci.',NULL);

select name,dept_name,nvl(salary,1) as myputput
from instructor
order by name;

select I.name,ROUND((I.salary/3),-2) as Rounded_salary
from instructor I
order by I.name;

