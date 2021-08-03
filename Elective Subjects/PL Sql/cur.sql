DECLARE
rows number(2);
BEGIN

Update hardware set address = 'Pokhara';
if sql%notfound then
dbms_output.put_line('no hardware found');
elsif sql%found then
rows := sql%rowcount;
dbms_output.put_line(rows ||' hardware updated');
end if;
end;
/

