create table employee
(
    emp_no numeric(3),
    emp_name varchar2(10),
    emp_address varchar2(30)
);

insert into employee values(111,'AAAA','a1');
insert into employee values(222,'bbbb','b2');
insert into employee values(333,'ccc','c3');
insert into employee values(444,'dddd','d4');
insert into employee values(555,'eeee','e5');

select *
from employee
where emp_address = 'e5';

alter table employee add(salary numeric(6));


update employee set salary = 50000;

delete from employee where emp_address = 'e5';

rename employee to myemployee;
