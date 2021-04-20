-- Name of 1st highest Salary
select name
from instructor
where salary = (select max(salary) from instructor);

-- 2nd highest salary
select max(salary)
from instructor
where salary <> 
(select max(salary)
from instructor);
	

select name
from instructor
where salary =
(select max(salary)
from instructor
where salary <> 
(select max(salary)
from instructor));
	