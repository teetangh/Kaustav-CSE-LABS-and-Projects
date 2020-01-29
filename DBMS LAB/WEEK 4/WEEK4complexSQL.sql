-- q1
select course_id,count(id)
from takes
group by course_id;


-- q2
-- (OE Students also get selected)
-- select dept_name,count(ID) 
-- from takes natural join course
-- group by dept_name
-- having count(ID) > 10;

select dept_name,count(ID)
from student
group by dept_name
having count(ID) > 10;

-- q3
select dept_name,count(course_id) 
from course
group by dept_name;

-- q4
select dept_name,avg(salary) as average_salary
from instructor
group by dept_name
having avg(salary) > 42000;

-- q5
select sec_id,count(*) 
from section
where year = 2009 and semester = 'Spring'
group by sec_id;

-- q6
select * 
from prereq
order by course_id;


-- q7
select *
from instructor
order by salary desc;


-- q8
select dept_name,max(sum(salary))
from instructor
group by dept_name;
having sum(salary) >= total_salary;
