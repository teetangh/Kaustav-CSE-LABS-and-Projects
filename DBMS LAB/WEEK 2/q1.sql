set linesize 120

drop table EMPLOYEE;
drop table DEPARTMENT;

create table EMPLOYEE (
	EmpNo number(5) not null,
	EmpName varchar2(20) not null,
	Gender varchar2(2) not null, 
	Salary number(5) not null,
	Address varchar2(20) not null
	,DNo number(3));

create table DEPARTMENT(
	DeptNo number(3) primary key,
	DeptName varchar2(10) unique,
	Location varchar2(20));

alter table EMPLOYEE add constraint Emp_pk primary key(EmpNo);

alter table EMPLOYEE add constraint Gen_check CHECK (Gender = 'M' or Gender = 'F');

insert into EMPLOYEE values(111,'Kaustav','M',11111,'Gurgaon,India',100);
insert into EMPLOYEE values(222,'Sameer','M',22222,'Ranchi,India',200);
insert into EMPLOYEE values(333,'Ramu Kaka','M',33333,'Gurgaon,India',300);

insert into DEPARTMENT values(100,'CSE','Manipal');
insert into DEPARTMENT values(200,'ECE','Manipal');
insert into DEPARTMENT values(300,'MECH','Manipal');

alter table EMPLOYEE add constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo);

-- delete from DEPARTMENT where DeptName = 'MECH'; 

-- alter table EMPLOYEE modify constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo) on delete cascade;

alter table EMPLOYEE drop constraint DNo_Fk;

alter table EMPLOYEE add constraint DNo_Fk foreign key (DNo) references DEPARTMENT(DeptNo) on delete cascade;


