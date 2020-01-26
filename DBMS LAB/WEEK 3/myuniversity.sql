
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
