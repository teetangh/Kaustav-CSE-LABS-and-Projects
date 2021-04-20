drop table employee cascade constraints;
drop table DEPARTMENT cascade constraints;

create table employee (
  EmpNo numeric(5) not null,
  EmpName varchar2(10) not null,
  Gender varchar2(1) not null,
  salary numeric(5) not null,
  address varchar2(10) not null,
  Dno numeric(3)
);

create table DEPARTMENT
(
    DeptNo numeric(3) primary key,
    DeptName varchar2(10) unique,
    location varchar2(20)
);

alter table employee add constraint EmpNoPK primary key(EmpNo);
alter table employee add constraint Gen_check CHECK(Gender in 'M' or Gender in 'F');

insert into employee values(1111,'Kaustav','M',10000,'Gurgaon',101);
insert into employee values(2222,'Ashray','M',20000,'Banglore',202);
insert into employee values(3333,'karan','M',30000,'Hyd',303);
insert into employee values(4444,'Rmac','M',40000,'man',404);
insert into employee values(5555,'Sameer','M',50000,'kars',505);

-- alter table employee drop constraint Dno_FK;
-- alter table employee add constraint Dno_FK foreign key(Dno) references DEPARTMENT(DeptNo) on delete cascade;


