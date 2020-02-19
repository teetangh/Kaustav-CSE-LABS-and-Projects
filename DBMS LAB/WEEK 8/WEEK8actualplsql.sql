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

select * from StudentTable;


SET SERVEROUTPUT ON;
-- q1

-- DECLARE
--     sgpa StudentTable.GPA%TYPE;
--     srollno StudentTable.RollNo%TYPE;
--     x NUMBER := 0;
-- BEGIN
--     -- while x < count(StudentTable.ID)
--     while x < 5
--         LOOP
--             DBMS_OUTPUT.PUT_LINE('Student Roll Number: ' || srollno(x) || 'Student GPA: ' || sgpa );
--         END LOOP;
-- END;
-- /

DECLARE
    sgpa StudentTable.GPA%TYPE;
    srollno StudentTable.RollNo%TYPE;
BEGIN
    srollno := '&R';
    select GPA into sgpa from StudentTable where RollNo = srollno;
    DBMS_OUTPUT.PUT_LINE('GPA for given student is: ' || TO_CHAR(sgpa));
END;
/

-- q2

    