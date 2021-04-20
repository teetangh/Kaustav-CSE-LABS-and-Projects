-- @C:\Users\Kaustav\Desktop\sqlPractice\UniversityDB\DDL+drop.sql
-- @C:\Users\Kaustav\Desktop\sqlPractice\UniversityDB\smallRelationsInsertFile.sql

select name
from instructor
where instructor.ID ='22222';


select instructor.id, department.building
from instructor, department
where instructor.dept_name='Physics';

select distinct dept_name
from instructor;

select all dept_name
from instructor;

-- select '437'; doesn't work
-- select '437' as FOO  doesnt work

select dept_name
from instructor;


select ID, name, salary/12
from instructor;

select ID, name, salary/12 as monthly_salry
from instructor;

select *
from instructor
where dept_name = 'Comp. Sci.';


select *
from instructor
where dept_name = 'Comp. Sci.' and salary > 80000;

select *
from instructor, teaches;

select *
from instructor natural join teaches ;

select *
from instructor, teaches
where instructor.ID = teaches.ID;


-- Below code Same as
-- select * from instructor natural join teaches;

-- Art wouldnt work
select name, course_id
from instructor, teaches
where instructor.ID = teaches.ID and instructor.dept_name='Biology';

-- Not working with as
-- as doesnt 
select distinct T.name
from instructor T, instructor S
where T.salary > S.salary and S.dept_name = 'Comp. Sci.';

select *
from instructor T, instructor S
where T.salary > S.salary and S.dept_name = 'Comp. Sci.';

select name
from instructor
where name like '%a%';

select name
from instructor
where name like '__%';

select distinct name
from instructor
order by name desc;

select *
from instructor
order by name desc,dept_name;

select name
from instructor
where salary between 90000 and 100000;


-- -- Not working
select name, course_id
from instructor, teaches
where (instructor.ID,dept_name) = (teaches.ID,'Biology');


	(select course_id
	from section
	where semester = 'Fall' and year = 2009)
union
	(select course_id
	from section
	where semester = 'Spring' and year = 2010);

	(select course_id
	from section
	where semester = 'Fall' and year = 2009)
intersect
	(select course_id
	from section
	where semester = 'Spring' and year = 2010);

-- except doesnt work
(select course_id
from section
where semester = 'Fall' and year = 2009)
minus
(select course_id
from section
where semester = 'Spring' and year = 2010);

select distinct T.salary
from instructor T, instructor S
where T.salary < S.salary;

-- select  *
-- from instructor T,instructor S
-- where T.salary < S.salary;

select distinct salary
from instructor;

-- Gives the largest Salary 
(select distinct salary
from instructor)
minus
(select distinct T.salary
from instructor T, instructor S
where T.salary < S.salary);


select avg(salary)
from instructor
where dept_name = 'Comp. Sci.';


select count(distinct ID)
from teaches
where semester = 'Spring' and year = '2010';

select count(*)
from course;

select dept_name, avg(salary) as avg_salary
from instructor
group by dept_name;


-- Wrong CUSTOM GROUPING
-- select dept_name,ID,avg(salary) as avg_salary
-- from instructor
-- group by dept_name,ID;

select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary) > 42000;

select sum(salary)
from instructor;


select distinct course_id
from section
where semester = 'Fall' and year = 2009 and
	course_id in (select course_id
	from section
	where semester = 'Spring' and year = 2010);


select distinct course_id
from section
where semester = 'Fall' and year = 2009 and
	course_id not in (select course_id
	from section
	where semester = 'Spring' and year = 2010);


select *
from takes
where (course_id,sec_id,semester,year) in
(select course_id, sec_id, semester, year
from teaches
where teaches.ID = 10101);

select distinct T.name
from instructor T, instructor S
where T.salary > S.salary and S.dept_name = 'Biology';

-- Bio salary guy was 72k
-- Comp. Sci. multiple guys but minm was 65k
select *
from instructor
where salary > some(select salary
from instructor
where dept_name = 'Comp. Sci.');

-- Dont make spelling mistakes
select *
from instructor
where salary > all
(select salary
from instructor
where dept_name ='Comp. Sci.');


select course_id
from section S
where semester = 'Fall' and year = 2009
	and exists 
(select *
	from section T
	where semester = 'Spring' and year = 2010
		and S.course_id = T.course_id	
);

-- NOT UNDERSTANDING/Working
select distinct S.ID, S.name
from student S
where not exists 
((select course_id
from course
where dept_name = 'Biology')
minus
(select T.course_id
from takes T
where S.ID = T.ID)
);

-- Inverted it
-- Finds students who didnt takes Bio Courses(IG)
select *
from student S
where exists
((select T.course_id
from takes T
where S.ID = T.ID)
minus
(select course_id
from course
where dept_name = 'Biology')
);

-- -- unique Constraint Doesnt work in SQL
-- -- Use distinct in inner Subquery
-- select T.course_id
-- from course T
-- where unique
-- (select R.course_id
-- from section R
-- where T.course_id = R.course_id and R.year = 2009);


select T.course_id
from course T 
where 1 >= (select count (R.course_id) from section R where T.course_id = R.course_id and R.year = 2009);


