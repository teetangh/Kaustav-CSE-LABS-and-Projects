
select course_id from takes 
count(course_id) >= ALL (select count(*) from takes group by course_id);

select name, title from student, course 
join takes on takes.ID = student.ID   
where dept_name = 'Biology';

select takes.ID, semester from takes join student on student.ID = takes.ID where semester = 'Spring';

select name, title from student, course join takes on student.ID = takes.ID;