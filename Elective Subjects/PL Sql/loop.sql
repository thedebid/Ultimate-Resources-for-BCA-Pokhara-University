DECLARE
a number :=1;
BEGIN
LOOP
dbms_output.put_line(a);
a:=a+1;
 IF a > 10 THEN 
         exit; 
      END IF;
END LOOP;
dbms_output.put_line('Program completed.'); 
END;
/

DECLARE 
   a number; 
BEGIN 
   FOR a in 1 .. 10 LOOP 
      dbms_output.put_line(a); 
  END LOOP; 
END; 
/

DECLARE 
   a number; 
i number :=2;
BEGIN 
   FOR a in 1 .. 5 LOOP 
      dbms_output.put_line(i); 
i := i +2;
  END LOOP; 
END; 
/


DECLARE
a number :=1;
b number :=2;
BEGIN
LOOP
dbms_output.put_line(b);
b := b+2;
a:=a+1;
 IF a > 5 THEN 
         exit; 
      END IF;
END LOOP;
dbms_output.put_line('Program completed.'); 
END;
/


