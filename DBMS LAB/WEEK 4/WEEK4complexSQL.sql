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
select dept_name,sum(salary) as total_salary
from instructor
group by dept_name
having sum(salary) >= all (select sum(salary) 
from instructor
group by dept_name);


-- q9

select R.dept_name,avg(R.salary)
from instructor R
group by R.dept_name
having R.dept_name in
(select S.dept_name
from instructor S
group by S.dept_name
having avg(S.salary) > 42000);


-- q10

select sec_id,count(course_id) 
from section
where semester = 'Spring' and year =2010
group by sec_id; 

-- q11

-- select * 
-- from teaches full outer join takes 
-- using (course_id,sec_id,semester,year);

-- select course_id,sec_id,semester,year,teaches.ID as teaches_id,takes.ID as takes_id 
-- from teaches inner join takes 
-- using (course_id,sec_id,semester,year);


select *
from instructor natural join teaches
where teaches.course_id in
(
select course_id 
from student natural join takes
where student.dept_name = 'Comp. Sci.' 
);

select distinct (name)
from
(select instructor.name
from instructor natural join teaches,student natural join takes
where instructor.dept_name = student.dept_name
and student.dept_name = 'Comp. Sci.'
);
select distinct (name)
from
(select instructor.name
from instructor natural join teaches,student natural join takes
where student.dept_name = 'Comp. Sci.'
);

-- q12

select dept_name,avg(salary)
from instructor
group by dept_name
having avg(salary)>50000 and count(id)>2;



-- select dept_name,avg_sal,count
-- from
-- (
-- select dept_name,avg(salary)
-- from avg_sal,count(*) as count_i from instructor
-- group by dept_name
-- )
-- where avg_sal > 50000 and count_i > 5;

-- q13
    with max_budget(value) as
    (select max(budget)
    from department)
    select dept_name,budget
    from department,max_budget
    where department.budget = max_budget.value;

-- q14
   with 
   dept_total(dept_name,value) as
   ( select dept_name,sum(salary)
     from instructor
     group by dept_name),
    dept_total_avg(value) as
    (select avg(value) from dept_total)
    select dept_name 
    from dept_total,dept_total_avg
    where dept_total.value >= dept_total_avg.value;

-- q15
    with 
    count_section(sec_id,total) as 
    (select sec_id,count(ID)
    from takes 
    where semester = 'Fall' and year = 2009
    group by sec_id),
    high_count_section(value) as 
    (select max(total) from count_section)
    select sec_id,total
    from count_section,high_count_section
    where total = value;
    
-- Naive
    select I.dept_name
    from instructor I ,dept_tot
    group by I.dept_name
    having avg(I.salary) < dept_tot.value;
    
-- q16
    with
    fin_tot_cred(value1) as
    (select sum (tot_cred)
    from student
    where dept_name = 'Finance'),
    dept_tot_cred(dept_name,value2) as
    (select dept_name , sum(tot_cred)
    from student
    group by dept_name)
    select *
    from fin_tot_cred,dept_tot_cred
    where value1 < value2;


-- q17
    savepoint SAFEONE;
    delete from instructor where dept_name = 'Finance';
    rollback;

-- q18
    delete from course where dept_name = 'Comp. Sci.';
    rollback;


-- q19(Wrong)
    update student set dept_name = 'IT' where dept_name = 'Comp. Sci.';
    rollback;

-- q20(Wrong)
    update instructor set salary 
    case when salary > 100000 then salary * 1.05
    else salary * 1.03
    END;

-- q21(Wrong)
    insert into student(id,name,dept_name,tot_cred) (select id,name,dept_name,0 from instructor);
    
-- q22
    delete from instructor where salary < (select avg(salary) from instructor);
