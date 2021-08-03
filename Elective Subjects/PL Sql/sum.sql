DECLARE
a number :=3;
b number :=3;
c number;
BEGIN
c := a + b;
dbms_output.put_line('sum is ' || c);
END;
/