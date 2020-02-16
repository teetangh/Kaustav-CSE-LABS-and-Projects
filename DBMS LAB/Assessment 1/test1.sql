drop table author cascade constraints; 
drop table book cascade constraints; 

create table author
(
	aid numeric(4) primary key,
	name varchar2(10),
	country varchar2(10)
);

create table book
(
	bid numeric(2),
	aid	numeric(4),
	title varchar2(10),
	chapters numeric(1),
	primary key(bid,aid),
	foreign key(aid) references author
);

insert into author values(1000,'Nanda','INDIA');
insert into author values(2000,'Gopal','USA');
insert into author values(3000,'Bala','USA');
insert into author values(4000,'Guru','INDIA');
insert into author values(5000,'Swamy','INDIA');

insert into book values(10,1000,'Java',5);
insert into book values(40,2000,'C++',3);
insert into book values(30,2000,'RDBMS',5);
insert into book values(30,3000,'RDBMS',2);
insert into book values(10,4000,'Java',4);
insert into book values(40,4000,'C++',3);

-- q1
select distinct book.title
from author,book
where author.aid = book.aid
and author.country = 'INDIA';

-- q2
select author.name,count(bid) as bid_count
from author,book
where author.aid = book.aid
group by author.name
having count(bid) >= all
(select count(bid) as bid_count
from author,book
where author.aid = book.aid
group by author.name);


-- select name,max(bid_count)
-- from (select author.name,count(bid) as bid_count
-- from author,book
-- where author.aid = book.aid
-- group by author.name);