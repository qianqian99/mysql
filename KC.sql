create table KC
(
    cno char(3) not null primary key,
    cname char(20) not null,
    teacher char(10),
    openTerm tinyint check(openTerm between 1 and 6),
    time tinyint default 60 ,
    score tinyint not null
);
