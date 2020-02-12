create table StudentTable
(
    RollNo numeric (3),
    GPA numeric(2)
);

insert into StudentTable values(1,5.8);
insert into StudentTable values(2,6.5);
insert into StudentTable values(3,3.4);
insert into StudentTable values(4,7.8);
insert into StudentTable values(5,9.5);

SET SERVEROUTPUT ON;

DECLARE
    sgpa StudentTable.GPA%TYPE;
    srollno StudentTable.RollNo%TYPE;
    x NUMBER := 0;
BEGIN
    while x < count(StudentTable.ID)