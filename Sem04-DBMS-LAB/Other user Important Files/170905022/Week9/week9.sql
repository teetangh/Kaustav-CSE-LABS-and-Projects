 declare
 a number := '&a';
 b number := '&b';
 c number;
 begin
 c := sum_number(a, b);
 dbms_output.put_line(c);
 end;
  /

create or replace procedure dept_instructor(name varchar) is
instruct varchar(10);
begin
select name into instruct from instructor where instructor.dept_name = name;
dbms_output.put_line(instruct);
end;
/ 

declare
dept varchar(10) := '&dept';
begin

dept_instructor(dept);
end;
/

