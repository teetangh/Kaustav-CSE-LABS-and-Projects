set linesize 120
drop table EMPLOYEE;
drop table DEPARTMENT;

-- q1
create table EMPLOYEE
(
	EmpNo number(5) not null,
	EmpName varchar2(20) not null,
	Gender varchar2(2) not null,
	Salary number(5) not null,
	Address varchar2(20) not null
	,
	DNo number(3)
);

-- q2 
create table DEPARTMENT
(
	DeptNo number(3) primary key,
	DeptName varchar2(10) unique,
	Location varchar2(20)
);


alter table EMPLOYEE add constraint Emp_pk primary key(EmpNo);

alter table EMPLOYEE add constraint Gen_check CHECK (Gender = 'M' or Gender = 'F');

-- q3
alter table EMPLOYEE add constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo);

-- q4
insert into EMPLOYEE
values(111, 'Kaustav', 'M', 11111, 'Gurgaon,India', 100);
insert into EMPLOYEE
values(222, 'Sameer', 'M', 22222, 'Ranchi,India', 200);
insert into EMPLOYEE
values(333, 'Sanskar', 'M', 33333, 'Delhi,India', 300);

insert into DEPARTMENT
values(100, 'CSE', 'Manipal');
insert into DEPARTMENT
values(200, 'ECE', 'Manipal');
insert into DEPARTMENT
values(300, 'MECH', 'Manipal');


-- delete from DEPARTMENT where DeptName = 'MECH'; 

-- alter table EMPLOYEE modify constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo) on delete cascade;

-- q7
alter table EMPLOYEE drop constraint DNo_Fk;

alter table EMPLOYEE add constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo) on delete cascade;

-- q8
alter table EMPLOYEE modify (Salary null);
alter table EMPLOYEE modify Salary default 10000;
insert into EMPLOYEE values (444, 'New One', 'M', NULL , 'Hyderabad,India', 400);
select * from EMPLOYEE;