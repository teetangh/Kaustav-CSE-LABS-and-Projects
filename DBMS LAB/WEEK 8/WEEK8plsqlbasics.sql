SET SERVEROUTPUT ON

DECLARE 
    message varchar2(20):='Hello Worlds';
BEGIN
    DBMS_OUTPUT.PUT_LINE(message);
END;
/

DECLARE
    grade char(1);
BEGIN
    grade := '&g';
IF grade = 'A' THEN
    DBMS_OUTPUT.PUT_LINE('Excellent');
ELSIF grade = 'B' THEN
    DBMS_OUTPUT.PUT_LINE('Very Good');
ELSIF grade = 'C' THEN
    DBMS_OUTPUT.PUT_LINE('Good');
ELSIF grade = 'D' THEN
    DBMS_OUTPUT.PUT_LINE('Fair');
ELSIF grade = 'E' THEN
    DBMS_OUTPUT.PUT_LINE('Poor');
ELSE
    DBMS_OUTPUT.PUT_LINE('No Such Grade');
END IF;
END;
/

DECLARE 
    x NUMBER := 0;
BEGIN 
    LOOP
        DBMS_OUTPUT.PUT_LINE('Inside LOOP: x = ' || TO_CHAR(x));
        x := x + 1;
        IF x>3 THEN EXIT;
        END IF;
    END LOOP;
-- After Exit Control Resumes Here
DBMS_OUTPUT.PUT_LINE('After LOOP: x=' || TO_CHAR(x));
END;
/


DECLARE 
    x NUMBER := 0;
BEGIN
    while x < 4
        LOOP
            DBMS_OUTPUT.PUT_LINE('Inside while LOOP: = ' || TO_CHAR(x));
            x := x+1;
        END LOOP;
END;
/


BEGIN
    DBMS_OUTPUT.PUT_LINE('lower_bound<upper_bound');

    FOR i in 1..3 LOOP
        DBMS_OUTPUT.PUT_LINE(i);
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('lower_bound = upper_bound');

    FOR i in 2..2 LOOP
        DBMS_OUTPUT.PUT_LINE(i);
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('lower_bound > upper_bound');
    FOR i in 3..1 LOOP
        DBMS_OUTPUT.PUT_LINE(i);
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Reverse Loop');
    FOR i IN REVERSE 1..3 LOOP
        DBMS_OUTPUT.PUT_LINE(i);
    END LOOP;
END;
/



