select course_id,count(id)
from takes
group by course_id;

select dept_name,count(ID)
from student
group by dept_name
having count(ID) > 2;

select dept_name,count(course_id)
from course
group by dept_name;

select dept_name,avg(salary) as average_salary
from instructor
group by dept_name
having avg(salary) > 42000;

select sec_id,count(*)
from section
where semester = 'Spring' and year = 2009
group by sec_id;


select *
from prereq
order by course_id;

select *
from instructor
order by salary desc;

select dept_name , sum(salary) as output
from instructor
group by dept_name
having sum(salary) >= all 
(select sum(salary)
from instructor
group by dept_name);

select R.dept_name,avg(R.salary)
from instructor R
group by R.dept_name
having R.dept_name in
(select S.dept_name
from instructor S
group by S.dept_name
having avg(S.salary)>42000);

select sec_id,count(course_id)
from section 
where semester = 'Spring' and year = 2010
group by sec_id;


select distinct instructor.name 
from instructor natural join teaches , student natural join takes 
where instructor.dept_name = student.dept_name
and student.dept_name = 'Comp. Sci.';


select dept_name,avg(salary)
from instructor
group by dept_name
having avg(salary) > 50000 and count(id) > 2;

with max_budget(value) as
(select max(budget)
from department)
select dept_name,budget
from department,max_budget
where department.budget = max_budget.value;