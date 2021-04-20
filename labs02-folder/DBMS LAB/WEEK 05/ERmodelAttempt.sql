drop table employee cascade constraints;
drop table department cascade constraints;

drop table prereq cascade constraints;
drop table time_slot cascade constraints;
drop table advisor cascade constraints;
drop table takes cascade constraints;
drop table student cascade constraints;
drop table teaches cascade constraints;
drop table section cascade constraints;
drop table instructor cascade constraints;
drop table course cascade constraints;
drop table department cascade constraints;
drop table classroom cascade constraints;


drop table EMPLOYEE cascade constraints;
drop table DEPARTMENT cascade constraints;
drop table DEPT_LOCATIONS cascade constraints;
drop table PROJECT cascade constraints;
drop table WORKS_ON cascade constraints;
drop table DEPENDENT cascade constraints;
drop table dept_locations cascade constraints;

create table department
(
    dept_name varchar2(10),
    dept_location varchar2(10),
    dept_num numeric(3),

    primary key(dept_name,dept_num)
);
create table employee
( 
  SSN numeric(10) primary key
  sex varchar2(1),
  Bdate DATE,
  Fname varchar2(10) not null,
  Mname varchar2(10),
  Lname varchar2(10) not null,
  Address varchar2(20),
  Salary numeric(6),

  dept_num numeric(3),
  superssn numeric(19),
  StartDate DATE

  check( sex in ('M','F'))
  foreign key(dept_num) references department
  foreign key(superssn) references employee
);


create table project
(
    project_name varchar2(10) primary key,
    project_num numeric(3),
    project_location varchar2(20)
);

-- foreign key on the many side

create table dependent
(
    dependent_name varchar2(10),
    sex varchar2(1),
    Bdate DATE,
    Relationship varchar2(10)
);

create table works_on
(
    ssn numeric(10),
    project_num numeric(10),
    hours numeric(3)

    foreign key(ssn) references employee
    foreign key(project_num) references project

);

create table dept_locations
(
    dept_num numeric(3)
    dept_location varchar2(10),

    primary key (dept_num,dept_location)
);
