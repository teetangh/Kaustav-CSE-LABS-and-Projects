create table employee(emp_no number(5),emp_name varchar2(20),emp_address varchar2(50));

insert into employee values (1,'Kaustav','Gurgaon,India');

insert into employee values (2,'Karan','Bangalore,India');

insert into employee values (3,'Ranjan','Bangalore,India');

insert into employee values (4,'Ashray','Mangalore,India');

insert into employee values (5,'Sahaj','Manipal,India');

set linesize 150

select * from employee;

select * from employee where emp_address='Manipal,India';

alter table employee add(salary number(6));

update employee set salary = 700000 where emp_no=1;
update employee set salary = 800000 where emp_no=2;
update employee set salary = 700000 where emp_no=3;
update employee set salary = 600000 where emp_no=4;
update employee set salary = 900000 where emp_no=5;

update employee set salary = 999999;

delete from employee where emp_address='Mangalore,India';

rename employee to employee1;

drop table employee1;