
-- q1
select course_id from section where semester = 'Fall' and year = 2009
UNION
select course_id from section where semester = 'Spring' and year = 2010;

-- q2
select course_id from section where semester = 'Fall' and year = 2009
INTERSECT
select course_id from section where semester = 'Spring' and year = 2010;

-- q3
select course_id from section where semester = 'Fall' and year = 2009
MINUS
select course_id from section where semester = 'Spring' and year = 2010;

-- q4
-- select course_id,count(*)
-- from takes
-- group by course_id;


-- q5
select distinct course_id
from section
where semester = 'Fall' and year = 2009 and 
course_id in 
(select course_id
from section 
where semester = 'Spring' and year = 2010);

-- q6
select count(distinct ID)
from takes
where (course_id,sec_id,semester,year)
in
(select course_id,sec_id,semester,year
from teaches 
where teaches.ID = 10101);

-- q7
select distinct course_id
from section
where semester = 'Fall' and year = 2009 and 
course_id not in 
(select course_id
from section 
where semester = 'Spring' and year = 2010);

-- q8
select S.name
from student S
where S.name in
(select I.name
from instructor I);
-- Better
select * from instructor,student where instructor.name = student.name;

-- q9
select *   -- can be only name
from instructor A
where A.salary > some
(select salary
from instructor B
where B.dept_name = 'Biology');
-- Better
select *    -- can be only name
from instructor A
where A.salary >
(select min(salary)
from instructor B
where B.dept_name = 'Biology');


-- q10
select *   -- can be only name
from instructor A
where A.salary > all
(select salary
from instructor B
where B.dept_name = 'Biology');

-- q11

-- select *
-- from instructor A
-- where (A.dept_name,A.salary) in
-- (select B.dept_name,avg(B.salary)
-- from instructor B
-- group by B.dept_name);

select A.dept_name,avg(A.salary)
from instructor A
group by A.dept_name
having avg(A.salary) >= all
(select avg(B.salary)
from instructor B
group by B.dept_name);

-- -- Brute Force Check
-- select dept_name , avg(salary)
-- from instructor
-- group by dept_name;


-- q12

select dept_name
from department
where budget <
(select avg(salary)
from instructor);


-- q13
select course_id
from section S
where S.semester = 'Fall' and year = 2009 and
exists
(select course_id
from section T
where T.semester = 'Spring' and T.year = 2010);

-- q14

select distinct S.ID,S.name
from student S
where not exists
((select course_id
from course
where dept_name = 'Biology') 
)
MINUS
(select T.course_id
from takes T
where S.ID = T.ID)); 


-- 
  select distinct S.ID,S.name
 from student S 
 where not exists 
 ((select course_id 
 from course
  where dept_name = 'Biology')
  minus
  (select course_id 
  from takes t
  where t.id = s.id));

-- q15

select T.course_id
from course T
where unique 
(select R.course_id
from section R
where R.year = 2009 and R.course_id = T.course_id);

select T.course_id
from course T
where 1>= 
(select count(R.course_id)
from section R
where R.year = 2009 and R.course_id = T.course_id);