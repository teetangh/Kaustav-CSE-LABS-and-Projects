select course_id from section where semester = 'Fall' and year = 2009
UNION
select course_id from section where semester = 'Spring' and year = 2010;

select course_id from section where semester = 'Fall' and year = 2009
INTERSECT
select course_id from section where semester = 'Spring' and year = 2010;

select course_id from section where semester = 'Fall' and year = 2009
MINUS
select course_id from section where semester = 'Spring' and year = 2010;

select course_id
from course
where course_id not in
(select course_id
from takes);



select course_id
from section 
where semester = 'Fall' and year = 2009
and course_id in
(select course_id
from section
where semester = 'Spring' and year = 2010);


select count(distinct ID)
from takes 
where (course_id,sec_id,semester,year) in
(select course_id,sec_id,semester,year
from teaches
where teaches.ID = 10101);

select distinct course_id
from section
where semester = 'Fall' and year = 2009 and course_id not in
(select course_id
from section
where semester = 'Spring' and year = 2010);

select S.name
from student S
where S.name in 
(select I.name
from instructor I);

select A.name,A.salary
from instructor A
where A.salary > some
(select B.salary
from instructor B
where B.dept_name = 'Comp. Sci.'); 

select A.name,A.salary
from instructor A
where A.salary > all
(select B.salary
from instructor B
where B.dept_name = 'Comp. Sci.'); 


select A.dept_name,avg(A.salary)
from instructor A
group by A.dept_name
having avg(A.salary) >= all
(select avg(B.salary)
from instructor B
group by B.dept_name);


select distinct S.course_id
from section S
where S.semester = 'Fall' and S.year = 2009 and 
exists
(
    select T.course_id
    from section T
    where T.semester = 'Spring' and T.year = 2010
);


select distinct S.ID,S.name
from student S
where not exists
((
    select course_id
    from course
    where dept_name = 'Comp. Sci.'
)
MINUS
(
    select course_id
    from takes T
    where T.ID = S.ID
));

select C.course_id
from course C
where 1>=
(   select count(R.course_id)
    from section R
    where R.year = 2009 and C.course_id = R.course_id);

select name
from student S,takes T,course C
where S.ID = T.ID
and T.course_id = C.course_id
and C.dept_name = 'Comp. Sci.'
group by (name)
having count(name)>=2;

select dept_name,avg_salary
from (
select dept_name,avg(salary) as avg_salary
from instructor
group by dept_name
)
where avg_salary > 42000;

drop view all_courses
create view all_courses as
(
    select course.course_id,sec_id,building,room_number
    from course,section
    where course.course_id = section.course_id
    and section.semester = 'Fall'
    and section.year = 2009
    and course.dept_name = 'Physics'
);

select course_id
from all_courses;

drop view department_total_salary; 
create view department_total_salary as
(select dept_name,sum(salary) as total_salary
from instructor
group by dept_name);