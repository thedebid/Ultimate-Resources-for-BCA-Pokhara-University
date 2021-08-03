DECLARE
rec hardware%ROWTYPE;
CURSOR hr(add character) is select * from hardware where address = add;
begin 
open hr('Pokhara');
loop
FETCH hr into rec;
exit when hr%notfound;
dbms_output.put_line('hardware id: '||rec.id);
dbms_output.put_line('hardware id: '||rec.name);
dbms_output.put_line('hardware id: '||rec.address);
end loop;
close hr;
end;
/ 
