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


-- 

SELECT name, course_id
FROM instructor, teaches
WHERE instructor.ID = teaches.ID and instructor.dept_name = 'Art';

SELECT DISTINCT T.name
FROM instructor as T, instructor as S
WHERE T.salary > S.salary and S.dept_name ='Comp. Sci.';
