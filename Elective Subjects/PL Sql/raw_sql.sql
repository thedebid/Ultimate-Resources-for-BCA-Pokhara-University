/*create TABLE */
CREATE TABLE salesofficer( id int KEY auto_increment, name varchar(50), contact varchar(50), position varchar(60) );

CREATE TABLE area( id int PRIMARY KEY auto_increment, name varchar(20), code varchar(20) );

CREATE TABLE area_assign( id int PRIMARY KEY NOT NULL, sid int, aid int, FOREIGN KEY (aid) REFERENCES area(id), FOREIGN KEY (sid) REFERENCES salesofficer(id) );

CREATE TABLE hardware( id int PRIMARY KEY auto_increment, name varchar(40), address varchar(30), aid int, sid int, FOREIGN KEY (aid) REFERENCES area(id), FOREIGN KEY (sid) REFERENCES salesofficer(id) ); use college;

/*Drop TABLE */
DROP TABLE area;

DROP TABLE area_assign;

DROP TABLE salesofficer; 

alter TABLE hardware

DROP foreign key d; use college; 

alter TABLE area add column status enum('0', '1'); 

alter TABLE area modify status varchar(20);

/*INsert Data */
INSERT INTO area (name, code, status) values ('nawaplasari', 'nwl', 'active');


SELECT  *
FROM area;


SELECT  *
FROM area;

SELECT  *
FROM salesofficer;

INSERT INTO salesofficer(name, contact, position) values('samkishya', '89077896', 'Bank Manager');

SELECT  *
FROM area_assign;

INSERT INTO area_assign(id, sid, aid) values (3, 4, 2);

SELECT  *
FROM hardware;

INSERT INTO hardware(id, name, address, aid, sid) values (1, 'fdbsfgtb Supplier', 'xfgnfdh', 4, 2);

INSERT INTO hardware(id, name, address, aid) values (8, 'srthsr Supplier', 'Pulchowk', 3);

INSERT INTO hardware(id, name, address, aid) values (9, 'ABC Supplier', 'Gaindakot', 4);

INSERT INTO hardware(id, name, address, aid) values (10, 'Oxford Supplier', 'Gaindakot', 4); alter TABLE hardware

DROP column sid;

SELECT  *
FROM salesofficer
WHERE id='3'; 

SELECT  *
FROM hardware
WHERE aid='2'; 

SELECT  *
FROM hardware
WHERE aid=3
ORDER BY name DESC; update hardware 

SET aid = '1'
WHERE id=4; alter TABLE hardware add column lim int; update hardware 

SET lim = 200000
WHERE id=1; update hardware 

SET lim = 200000
WHERE id=2; update hardware 

SET lim = 100000
WHERE id=3; update hardware 

SET lim = 300000
WHERE id=4; update hardware 

SET lim = 400000
WHERE id=5; update hardware 

SET lim = 500000
WHERE id=6; update hardware 

SET lim = 600000
WHERE id=7; 

SELECT  TOP 2 *
FROM hardware;

SELECT  *
FROM hardware; use college; alter TABLE hardware add column due_amount varchar
(50
);

SELECT  name
       ,aid
       ,(lim - due_amount) AS due
FROM hardware
ORDER BY due DESC ;

SELECT  *
FROM hardware
WHERE (lim - due_amount) >500000 
AND lim >600000; 

SELECT  *
FROM hardware
WHERE lim BETWEEN 3000 AND 1000000; 

SELECT  *
FROM hardware
WHERE name like 'R%'; 
/*Agg Funcations */
SELECT  AVG(due_amount) AS average_amount
FROM hardware;

SELECT  MIN(due_amount) AS min_amount
FROM hardware;

SELECT  MAX(due_amount) AS max_amount
FROM hardware;

SELECT  COUNT(due_amount) AS total_hardware
FROM hardware;

SELECT  ucase(name)
FROM hardware;

SELECT  *
FROM hardware;

SELECT  aid
       ,SUM(due_amount)
FROM hardware
GROUP BY  aid;

SELECT  aid
       ,AVG(due_amount)
FROM hardware
GROUP BY  aid;

SELECT  aid
       ,COUNT(*)
FROM hardware
GROUP BY  aid;

SELECT  aid
       ,SUM(due_amount)
FROM hardware
GROUP BY  aid
HAVING SUM(due_amount)>50000;

SELECT  name
FROM area
WHERE id IN ( SELECT id FROM hardware GROUP BY aid); 

SELECT  name
FROM area
WHERE id IN ( SELECT id FROM hardware GROUP BY aid HAVING SUM(due_amount)>AVG(due_amount)); 

SELECT  hardware.name
       ,hardware.address
       ,hardware.lim
       ,hardware.due_amount
       ,area.name AS areaname
FROM hardware
INNER JOIN area
ON area.id= hardware.id;

INSERT INTO area (id, name, code, status) values (6, "Kawasoti", "KW00", "active");
/*Joins */
SELECT  h.name
       ,hardware.address
       ,hardware.lim
       ,hardware.due_amount
       ,area.name AS areaname
FROM hardware AS h
JOIN area
ON area.id= hardware.id;

SELECT  *
FROM salesofficer;

SELECT  salesofficer.name
       ,salesofficer.contact
       ,salesofficer.position
       ,area.name AS area_name
FROM area
LEFT JOIN area_assign
ON area.id = area_assign.aid
LEFT JOIN salesofficer
ON area_assign.sid = salesofficer.id;

SELECT  area.name
       ,area_assign.id AS area_name
FROM area
JOIN area_assign
ON area.id = area_assign.aid;

SELECT  *
FROM area_assign;

INSERT INTO area_assign (id, sid, aid) values (5, 4, 1);

SELECT  *
FROM hardware
HAVING SUM(due_amount) > AVG(due_amount);

SELECT  hardware.name
       ,area.name
FROM hardware
JOIN area
ON hardware.aid = area.id
WHERE area.name = 'narayangarh'; 