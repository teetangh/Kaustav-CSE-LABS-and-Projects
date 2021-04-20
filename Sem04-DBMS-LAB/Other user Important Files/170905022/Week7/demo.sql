/*

declare

roll INT := '&roll';
t INT;

begin

SELECT GPA into t FROM StudentTable WHERE RollNo = roll;

DBMS_OUTPUT.PUT_LINE('GPA:' || t);

END;
/

*/



/*

declare

grade CHAR(1);

begin

grade := '&Grade';

if grade >=0 AND grade < 4 then
DBMS_OUTPUT.PUT_LINE('F');

elsif grade >=4 AND grade < 5 then
DBMS_OUTPUT.PUT_LINE('E');

elsif grade >=5 AND grade < 6 then
DBMS_OUTPUT.PUT_LINE('D');

elsif grade >=6 AND grade < 7 then
DBMS_OUTPUT.PUT_LINE('C');

elsif grade >=7 AND grade < 8 then
DBMS_OUTPUT.PUT_LINE('B');

elsif grade >=9 AND grade < 10 then
DBMS_OUTPUT.PUT_LINE('A');

else
DBMS_OUTPUT.PUT_LINE('INVALID');

end if;

end;

/

*/

/*

declare

T INT;

begin

for i in 100..104 LOOP

select GPA into T from StudentTable where RollNo = i;
DBMS_OUTPUT.PUT_LINE('GPA is ' || T);

end LOOP;

end;

/

*/

declare 

rollNo NUMBER;
g INT;
grade VARCHAR2(2);

begin

rollNo := 100;

while rollNo < 105
 LOOP

SELECT GPA into g from StudentTable WHERE RollNo = rollNo;


if g >=0 AND g < 4 then
grade := 'F';

elsif g >=4 AND g < 5 then
grade := 'E';

elsif g >=5 AND g < 6 then
grade := 'D';

elsif g >=6 AND g < 7 then
grade := 'C';

elsif g >=7 AND g < 8 then
grade := 'B';

elsif g >=9 AND g < 10 then
grade := 'A';

END IF;

UPDATE StudentTable SET LetterGrade = g where RollNo = rollNo;

rollNo := rollNo + 1;



END LOOP;

END;

/

/


























