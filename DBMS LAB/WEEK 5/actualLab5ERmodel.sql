-- q1
    select BDATE,ADDRESS
    from employee
    where Fname = 'John';


    select *
    from employee,department
    where employee.dno = department.dnumber
    and department.dname='Research';


-- q2
    -- select *
    -- from project
    -- where plocation = 'Stafford';

    select P.pnumber,D.dnumber,E.lname,E.address,E.Bdate
    from project P,department D,employee E
    where P.dnum = D.dnumber
    and D.mgr_ssn = E.ssn
    and P.plocation = 'Stafford';

-- q3
    select distinct(salary)
    from employee;

-- q4
    select e1.Fname as employee_Fname ,
            e1.lname as employee_lastname,
            e2.Fname as super_Fname,
            e2.lname as super_Lname 
    from employee e1,employee e2
    where e1.super_ssn = e2.ssn;

-- q5
    select * 
    from employee E,works_on W,project P
    where E.ssn = W.essn
    and W.pno = P.pnumber 
    and E.lname = 'Smith';

    -- select * 
    -- from works_on;

-- q6
    select *
    from employee
    where address like '%Houston TX%';

-- q7
    select fname,minit,lname,(salary*1.1) as new_sal  
    from employee E,works_on W,project P
    where E.ssn = W.essn
    and W.pno = P.pnumber 
    and P.pname = 'ProductX';

-- q8

    select * 
    from employee E,department D
    where E.dno = D.dnumber
    and D.dnumber = 5
    and E.salary between 30000 and 40000;

-- q9

    select fname,minit,lname,pname 
    from employee E,works_on W,project P
    where E.ssn = W.essn
    and W.pno = P.pnumber
    order by P.dnum,E.lname,E.fname;

    -- select * from employee;

-- q10


    select e1.fname as employee ,e2.fname as supervisor
    from employee e1 full outer join employee e2
        on e1.super_ssn = e2.ssn
    where e2.fname is NULL;

-- 18FEB2020
-- q11

    select e1.fname as employee ,e2.fname as supervisee
    from employee e1 full outer join employee e2
        on e1.ssn = e2.super_ssn
    where e1.fname = e2.fname
    and e1.sex = e2.sex;

-- q12()
    select e1.fname as employee ,e2.fname as supervisee
    from employee e1 full outer join employee e2
        on e1.ssn = e2.super_ssn
    where e2.fname is NULL;

-- q13

    select e1.fname as man_super,e2.fname as supervisee
    from employee e1 full outer join employee e2 on e1.ssn = e2.super_ssn,department D
    where e1.ssn = D.mgr_ssn
    and e2.fname is NOT NULL
    order by e1.fname;


-- q14

    select E.ssn as emp_ssn
    from employee E,works_on W,project P
    where E.ssn = W.essn
    and W.pno = P.pnumber
    and P.pnumber in (1,2,3);

-- q15

    -- select salary,MAX(salary),MIN(salary),AVG(salary)
    -- from employee;
    select count(ssn),SUM(salary),MAX(salary),MIN(salary),AVG(salary)
    from employee;


-- q16 

    select count(ssn),SUM(salary),MAX(salary),MIN(salary),AVG(salary)
    from employee E,department D
    where E.dno = D.dnumber
    and D.dname = 'Research';

-- q17

    select P.PNAME,P.PNUMBER,count(E.ssn)
    from employee E,works_on W,project P
    where E.ssn = W.essn
        and W.pno = P.pnumber
    group by (p.PNAME,p.PNUMBER);


-- q18

    select P.PNAME,P.PNUMBER,count(E.ssn)
    from employee E,works_on W,project P
    where E.ssn = W.essn
        and W.pno = P.pnumber
    group by (p.PNAME,p.PNUMBER)
    having count(E.ssn) > 2;

-- q19

    select dname,dno,count(E.ssn)
    from employee E,department D
    where E.dno = D.dnumber
        and E.salary > 40000
    group by (dname,dno)
    having count(E.ssn) > 5;

    