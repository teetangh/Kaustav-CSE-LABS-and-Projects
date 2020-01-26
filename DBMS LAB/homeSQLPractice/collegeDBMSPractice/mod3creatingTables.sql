drop table instructor
cascade constraints;

CREATE TABLE instructor
(
	ID char(5),
	name VARCHAR2(20) not null,
	dept_name VARCHAR2(20),
	salary NUMERIC(8, 2),
	PRIMARY KEY(ID),
	FOREIGN KEY(dept_name) REFERENCES department
);

drop table student
cascade constraints;
create TABLE student
(
	ID VARCHAR2(5),
	name VARCHAR2(20) not null,
	dept_name VARCHAR2(20),
	tot_cred NUMERIC(3,0),
	PRIMARY KEY (ID),
	FOREIGN KEY (dept_name) REFERENCES department
);

drop table takes
cascade constraints;
create table takes
(
	ID VARCHAR2(5),
	course_id VARCHAR2(8),
	sec_id VARCHAR2(8),
	semester VARCHAR2(6),
	year NUMERIC(4,0),
	grade VARCHAR2(2),
	PRIMARY KEY (ID,course_id,sec_id,semester,year),
	FOREIGN KEY (ID) REFERENCES student,
	FOREIGN KEY (course_id,sec_id,semester,year) REFERENCES section
);

drop table course
cascade constraints;

create table course
(
	course_id VARCHAR2(8),
	title VARCHAR2(50),
	dept_name VARCHAR2(20),
	credits NUMERIC(2,0),
	PRIMARY KEY (course_id),
	FOREIGN KEY (dept_name) REFERENCES department
);

insert into instructor
values
	('10201', 'Smith', 'Biology', 66000);
insert into instructor
values
	('10202', 'Jenny', 'Physics', 57000);

select *
from instructor;

delete from instructor;

select *
from instructor;

insert into instructor
values
	('10201', 'Smith', 'Biology', 66000);
insert into instructor
values
	('10202', 'Jenny', 'Physics', 57000);

select *
from instructor;

alter table instructor add gender VARCHAR2(10);
alter table instructor drop gender;



