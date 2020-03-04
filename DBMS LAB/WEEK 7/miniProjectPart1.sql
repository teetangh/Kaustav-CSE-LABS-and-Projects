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
create TABLE team_member(
  reg_no numeric(10) primary key,
  mem_name varchar2(10) NOT NULL,
  DOB date NOT NULL,
  deptartment varchar2(10) NOT NULL,
  gender char NOT NULL,
  contact_num numeric(10),
  email varchar2(25),
  hostel numeric(1),
  blood_gp char NOT NULL,
  check (gender in ('M', 'F'));
);
create TABLE outdoor_activities (
  pass_id varchar2(10) primary key,
  host_college varchar2(10) NOT NULL,
  Ac_date date NOT NULL,
  budget numeric(6) NOT NULL
);
create TABLE team (
  team_name varchar2(10) primary key,
  no_of_matches numeric(3) NOT NULL,
  no_of_wins numeric(3) NOT NULL,
  no_of_draws numeric(3) NOT NULL,
  cap_start_date date NOT NULL,
  cap_reg_no numeric(10) NOT NULL,
  pass_id varchar2(10) NOT NULL,
  FOREIGN KEY (pass_id) REFERENCES outdoor_activities(pass_id) ON DELETE CASCADE ON UPDATE CASCADE
);
create TABLE Belongs_to (
  reg_no numeric(10),
  team_name varchar2(10),
  primary key(reg_no, team_name),
  FOREIGN KEY (reg_no) REFERENCES team_member(reg_no) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE ON UPDATE CASCADE
);
create TABLE Coach (
  coach_id varchar2(10) primary key,
  coach_name varchar2(10) NOT NULL,
  mobile_num numeric(10),
  email_id varchar2(25),
  join_date date NOT NULL,
  salary numeric(6) NOT NULL,
  team_name varchar2(10) NOT NULL,
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE ON UPDATE CASCADE,
  check (salary > 10000)
);
create TABLE Equipments (
  item_name varchar2(10) primary key,
  amount numeric(3) NOT NULL,
  check (amount > 0)
);
create TABLE Issues (
  reg_no numeric(10),
  item_name varchar2(10),
  issue_date date NOT NULL,
  issue_amount numeric(3) NOT NULL,
  return_date date,
  primary key(reg_no, item_name),
  FOREIGN KEY (reg_no) REFERENCES team_member(reg_no) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (item_name) REFERENCES Equipments(item_name) ON DELETE CASCADE ON UPDATE CASCADE
);
create TABLE Manages (
  manager_id varchar2(10) primary key,
  manager_name varchar2(10) NOT NULL,
  contact_num numeric(10),
  email_id varchar2(25),
  gender char NOT NULL,
  salary numeric(6) NOT NULL,
  check (gender in ('M', 'F')),
  check (salary > 10000)
);
create TABLE Events (
  event_id varchar2(10) primary key,
  event_name varchar2(10) NOT NULL,
  venue varchar2(10) NOT NULL,
  chief_guest varchar2(10) NOT NULL,
  manager_id varchar2(10) NOT NULL,
  FOREIGN KEY (manager_id) REFERENCES Manages(manager_id) ON DELETE CASCADE ON UPDATE CASCADE
);
create TABLE Competes (
  team_name varchar2(10),
  event_id varchar2(10),
  year numeric(4) NOT NULL,
  primary key(team_name, event_id),
  FOREIGN KEY (team_name) REFERENCES team(team_name) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (event_id) REFERENCES Events(event_id) ON DELETE CASCADE ON UPDATE CASCADE
);
-- ON DELETE CASCADE ON UPDATE CASCADE