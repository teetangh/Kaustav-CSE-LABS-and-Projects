create table employee
( 
  SSN numeric(10) primary key
  sex varchar2(1),
  Bdate DATE,
  Fname varchar2(10),
  Mname varchar2(10),
  Lname varchar2(10),
  Address varchar2(20),
  Salary numeric(6),

  dept_num numeric(3),
  superssn numeric(19),
  StartDate DATE

  check( sex in ('M','F'))
  foreign key(dept_num) references department
  foreign key(superssn) references employee
);

create table department
(
    dept_name varchar2(10),
    dept_location varchar2(10),
    dept_num numeric(3)

    primary key(dept_name,dept_num)
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

create table dept_location
(
    dept_num numeric(3)
    dept_location varchar2(10),

    primary key (dept_num,dept_location)
);
