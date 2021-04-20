cl scr;
set linesize 200;

DROP TABLE MATCH CASCADE CONSTRAINTS;
DROP TABLE PLAYER CASCADE CONSTRAINTS;
DROP TABLE BATTING CASCADE CONSTRAINTS;


CREATE TABLE Match
(
    MatchID INTEGER PRIMARY KEY,
    TeamName1 VARCHAR2(20)NOT NULL,
    TeamName2 VARCHAR2(20)NOT NULL,
    Ground VARCHAR2(20) NOT NULL,
    MatchDate DATE
);

CREATE TABLE Player
(
    PlayerID INTEGER PRIMARY KEY,
    LastName VARCHAR2(20) NOT NULL,
    FirstName VARCHAR2(20) NOT NULL,
    Country VARCHAR2(20) NOT NULL,
    YearBorn INTEGER NOT NULL,
    BirthPlace VARCHAR2(20) NOT NULL
);

CREATE TABLE Batting
(
    MatchID INTEGER NOT NULL,
    PlayerID INTEGER NOT NULL,
    BattingOrder NUMBER,
    RunsScored NUMBER,
    PRIMARY KEY(MatchID,PlayerID),
    foreign key (MatchID) references Match,
    foreign key (PlayerID) references Player
);

-- MatchID in Batting table refers to MatchID of Match Table
-- PlayerID in Batting table refers to PlayerID of Player Table

-- ALTER TABLE Batting DROP CONSTRAINT MatchID_FK;
-- ALTER TABLE Batting DROP CONSTRAINT PlayerID_FK;
-- ALTER TABLE Batting ADD CONSTRAINT MatchID_FK FOREIGN key (MatchID) REFERENCES Match(MatchID) ON DELETE CASCADE;
-- ALTER TABLE Batting ADD CONSTRAINT PlayerID_FK FOREIGN key (PlayerID) REFERENCES Match(PlayerID) ON DELETE CASCADE;


-- 2

ALTER SESSION SET NLS_DATE_FORMAT = 'DD/MM/YYYY';

INSERT INTO Match VALUES (2675,'Australia','India','Melbourne','10/2/2008');
INSERT INTO Match VALUES (2688,'Australia','India','Syndey','2/3/2008');
INSERT INTO Match VALUES (2689,'Australia','India','Brisbane','4/3/2008');
INSERT INTO Match VALUES (2755,'India','West Indies','Brisbane','7/7/2010');
INSERT INTO Match VALUES (2750,'Sri Lanka','India','Brisbane','7/4/2010');


INSERT INTO Player VALUES(89001, 'Tendulkar', 'Sachin', 'India', 1973, 'Mumbai');
INSERT INTO Player VALUES(27002, 'Sharma', 'Ishant', 'India', 1988, 'Delhi');
INSERT INTO Player VALUES(99001, 'Lee', 'Brett', 'Australia', 1976, 'Wollongong');
INSERT INTO Player VALUES(98002, 'Lara', 'Brian', 'West Indies', 1969, 'Santa Cruz');
INSERT INTO Player VALUES(91001, 'Jayasurya', 'Sanath', 'Sri Lanka', 1969, 'Matara');


INSERT INTO Batting VALUES(2689, 89001, 71, 1);
INSERT INTO Batting VALUES(2688, 98002, 42, 2);
INSERT INTO Batting VALUES(2675, 27002, 0, 2);
INSERT INTO Batting VALUES(2689, 99001, 9, 2);
INSERT INTO Batting VALUES(2755, 89001, 44, 1);
INSERT INTO Batting VALUES(2750, 89001, 40, 4);
INSERT INTO Batting VALUES(2755, 27002, 29, 3);



-- 3a
select * 
FROM Player
WHERE Country = 'India' AND YearBorn > 1975;

-- 3b

SELECT *
FROM MATCH
WHERE TeamName1 = 'India' or TeamName1 = 'Australia';


-- 3c
SELECT LastName,FirstName
FROM Player
WHERE PlayerID = ALL (SELECT Batting.PlayerID
                        FROM Match,Batting
                         WHERE Match.Ground = 'Melbourne'
                         AND Batting.MatchID = Match.MatchID);

-- 3d
-- SELECT TOP 1 LastName,FirstName
-- FROM Player 
-- ORDER BY YearBorn DESC;

-- SELECT LastName,FirstName,MIN(YearBorn)
-- FROM PLAYER
-- ORDER BY YearBorn;

SELECT * 
FROM Player
WHERE YearBorn >= ALL
(SELECT YearBorn 
FROM Player);


-- 4
-- SET SERVER OUTPUT ON
    
-- DECLARE
--       ID INTEGER;
--       totalscored INTEGER;
--       num_to_word VARCHAR2(100); 
--       str		 VARCHAR2(100); 
--       len		 INTEGER; 
--       c		 INTEGER;
-- BEGIN
--   ID:=&inp;
--   Select sum(RunsScored) into totalscored from Batting where PlayerID=ID;
--   len := Length(totalscored); 

--   FOR i IN 1..len LOOP 
-- 		c := Substr(totalscored, i, 1);
--         IF c = '0' THEN
--           str := 'Zero';
--         ELSIF c = '1' THEN
--           str := 'One';
--         ELSIF c = '2' THEN
--           str := 'Two';
--         ELSIF c = '3' THEN
--           str := 'Three';
--         ELSIF c = '4' THEN
--           str := 'Four';
--         ELSIF c = '5' THEN
--           str := 'Five';
--         ELSIF c = '6' THEN
--           str := 'Six';
--         ELSIF c = '7' THEN
--           str := 'Seven';
--         ELSIF c = '8' THEN
--           str := 'Eight';
--         ELSIF c = '9' THEN
--           str := 'NINE';
--         END IF

-- 		num_to_word := (num_to_word ||str); 
-- 	END LOOP; 

-- 	dbms_output.Put_line(num_to_word); 
-- END; 
-- /

-- set SERVER OUTPUT ON

-- declare
-- 	player_id number(5);
-- 	runs number(4);
-- 	len integer;
-- 	c integer;
-- 	str varchar(20);
-- begin 
-- 	select sum(RunsScored) into runs
-- 	from batting
-- 	where playerid=&player_id;
-- 	len:=Length(runs);
-- 	FOR i IN 1..len 
-- 	LOOP
-- 		c := Substr(runs, i, 1); 
-- 		IF c = '0' THEN
-- 	        str := 'Zero';
-- 	    ELSIF c = '1' THEN
-- 	        str := 'One';
-- 	    ELSIF c = '2' THEN
-- 	        str := 'Two';
-- 	    ELSIF c = '3' THEN
-- 	        str := 'Three';
-- 	    ELSIF c = '4' THEN
-- 	        str := 'Four';
-- 	    ELSIF c = '5' THEN
-- 	        str := 'Five';
-- 	    ELSIF c = '6' THEN
-- 	        str := 'Six';
-- 	    ELSIF c = '7' THEN
-- 	        str := 'Seven';
-- 	    ELSIF c = '8' THEN
-- 	        str := 'Eight';
-- 	    ELSIF c = '9' THEN
-- 	        str := 'NINE';
-- 	    END IF;
-- 	dbms_output.put_line(str||' '); 
-- 	END LOOP;
-- end;
-- /

