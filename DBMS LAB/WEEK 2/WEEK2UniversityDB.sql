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

select T.course_id , C.title
from takes T, course C
where T.course_id = C.course_id and id='12345';

select *
from instructor
where salary between 40000 and 90000

select instructor.id
from instructor
where instructor.ID not in (select teaches.id
from teaches);


select student.name, course.title, takes.year
from student, course, takes, course, Section
where student.id = takes.id and takes.year = Section.year and course.course_id = takes.course_id and section.roomnumber='303';