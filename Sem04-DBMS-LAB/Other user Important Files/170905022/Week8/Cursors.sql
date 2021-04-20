DECLARE
		
CURSOR instruct(dept instructor.dept_name%TYPE) IS SELECT * FROM INSTRUCTOR;
inst_row instructor%ROWTYPE;
salary instructor.salary%TYPE;
id instructor.ID%TYPE;

x INT := 0;

BEGIN

open instruct;

while(x < 5) LOOP

FETCH instruct INTO inst_row;

if inst_row %FOUND THEN

FETCH inst_row.ID INTO id;
FETCH inst_row.salary INTO salary;

salary := salary * 0.05;

INSERT INTO salary_raise VALUES(salary, id, '24-Jan-3829');

END IF;

END LOOP;

END;
/
