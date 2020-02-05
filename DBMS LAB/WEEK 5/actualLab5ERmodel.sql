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
    select e1.Fname as employee_Fname ,e1.lname as employee_lastname,e2.Fname as super_Fname,e2.lname as super_Lname 
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


    select e1.fname,e2.fname
    from employee e1 left outer join employee e2
    on e1.super_ssn = e2.ssn
    where e2.fname is NULL;