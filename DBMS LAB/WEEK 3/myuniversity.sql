
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


-- q5
select course_id 
from section as Spring 
