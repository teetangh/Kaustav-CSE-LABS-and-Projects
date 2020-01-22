select name
from instructor
where	instructor.ID = '22222';


select
  instructor.ID,
  department.building
from instructor,
  department
where
  instructor.dept_name = 'physics';