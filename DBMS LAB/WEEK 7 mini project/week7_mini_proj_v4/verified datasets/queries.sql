drop TABLE team_member cascade constraints;
drop TABLE outdoor_activities cascade constraints;
drop TABLE team cascade constraints;
drop TABLE Belongs_to cascade constraints;
drop TABLE Coach cascade constraints;
drop TABLE Equipments cascade constraints;
drop TABLE Issues cascade constraints;
drop TABLE Manages cascade constraints;
drop TABLE Events cascade constraints;
drop TABLE Competes cascade constraints;
create TABLE team_member
(
  reg_no numeric(10) primary key,
  mem_name varchar2(30) NOT NULL,
  DOB date NOT NULL,
  deptartment varchar2(30) NOT NULL,
  gender char NOT NULL,
  contact_num numeric(10),
  email varchar2(50),
  hostel numeric(2),
  blood_gp varchar(3) NOT NULL,
  check (gender in ('M', 'F'))
);
create TABLE outdoor_activities
(
  pass_id varchar2(10) primary key,
  host_college varchar2(30) NOT NULL,
  Ac_date date NOT NULL,
  budget numeric(6) NOT NULL
    CHECK (budget BETWEEN 5000 and 10000)
);
create TABLE team
(
  team_name varchar2(30) primary key,
  no_of_matches numeric(3) NOT NULL,
  no_of_wins numeric(3) NOT NULL,
  no_of_draws numeric(3) NOT NULL,
  cap_start_date date NOT NULL,
  cap_reg_no numeric(10) NOT NULL,
  pass_id varchar2(10) NOT NULL,
  FOREIGN KEY (pass_id) REFERENCES outdoor_activities(pass_id) ON DELETE CASCADE,
  FOREIGN KEY (cap_reg_no) REFERENCES team_member(reg_no) ON DELETE CASCADE
);
create TABLE Belongs_to
(
  reg_no numeric(10),
  team_name varchar2(30),
  primary key(reg_no, team_name),
  FOREIGN KEY (reg_no) REFERENCES team_member(reg_no) ON DELETE CASCADE,
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE
);
create TABLE Coach
(
  coach_id varchar2(10) primary key,
  coach_name varchar2(30) NOT NULL,
  mobile_num numeric(10),
  email_id varchar2(25),
  join_date date NOT NULL,
  salary numeric(6) NOT NULL,
  team_name varchar2(30) NOT NULL,
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE,
  check (salary > 10000)
);
create TABLE Equipments
(
  item_name varchar2(30) primary key,
  amount numeric(3) NOT NULL,
  check (amount BETWEEN 50 and 100)
);
create TABLE Issues
(
  reg_no numeric(10),
  item_name varchar2(30),
  issue_date date NOT NULL,
  issue_amount numeric(3) NOT NULL,
  return_date date,
  primary key(reg_no, item_name),
  FOREIGN KEY (reg_no) REFERENCES team_member(reg_no) ON DELETE CASCADE,
  FOREIGN KEY (item_name) REFERENCES Equipments(item_name) ON DELETE CASCADE
);
create TABLE Manages
(
  manager_id varchar2(10) primary key,
  manager_name varchar2(30) NOT NULL,
  contact_num numeric(10),
  email_id varchar2(25),
  gender char NOT NULL,
  salary numeric(6) NOT NULL,
  check (gender in ('M', 'F')),
  check (salary > 10000)
);
create TABLE Events
(
  event_id varchar2(10) primary key,
  event_name varchar2(30) NOT NULL,
  venue varchar2(30) NOT NULL,
  chief_guest varchar2(30) NOT NULL,
  manager_id varchar2(10) NOT NULL,
  FOREIGN KEY (manager_id) REFERENCES Manages(manager_id) ON DELETE CASCADE
);
create TABLE Competes
(
  team_name varchar2(30),
  event_id varchar2(10),
  year numeric(4) NOT NULL,
  primary key(team_name, event_id),
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE,
  FOREIGN KEY (event_id) REFERENCES Events(event_id) ON DELETE CASCADE
);

-- q1
    -- Find Captain of particular team
    SELECT *
    FROM team_member FULL OUTER JOIN team 
    ON team_member.reg_no = team.cap_reg_no
    where team_name = 'Football';

-- q2
    -- Find all students who didnt return equipments and the equipment name
    SELECT mem_name,equipments.item_name
    FROM team_member,issues,equipments
    WHERE team_member.reg_no = issues.reg_no 
        AND issues.item_name = equipments.item_name
        AND issues.return_date is NULL;

-- q3
    -- Find the team_name and their budgets who indulged in outdoor actvities in the year 2017 
    SELECT team_name,host_college,budget
    FROM team,outdoor_activities
    WHERE team.pass_id = outdoor_activities.pass_id
    AND extract (year from Ac_date) = 2017;
    
-- q4
    -- Find all the members of athletics team and their coaches
    SELECT team_member.mem_name,coach.coach_name 
    FROM team_member,Belongs_to,team,coach
    WHERE team_member.reg_no = Belongs_to.reg_no
    AND Belongs_to.team_name = team.team_name
    AND team.team_name = coach.team_name
    AND team.team_name = 'Athletics';

-- q5
    -- Find count of all the team members
    drop VIEW team_member_count;
    create view team_member_count(team_name,mem_count) as (
        SELECT team.team_name ,COUNT(distinct team_member.reg_no)
        FROM team_member,belongs_to,team
        where team_member.reg_no = belongs_to.reg_no
        and belongs_to.team_name = team.team_name
        GROUP BY team.team_name );

        SELECT * from team_member_count;

-- q6
    -- Find the names of the teams that competed in an event managed by James and also the event name 
    SELECT team_name,event_name
    FROM team natural join competes natural join events natural join manages
    WHERE manager_name = 'James';


-- q7
    -- Find equipments with minimum with minimum stock
    SELECT *
    FROM equipments
    where amount = (SELECT MIN(amount) FROM equipments );
    SELECT *
    FROM equipments
    where amount = (SELECT MAX(amount) FROM equipments );

-- q8
    -- 