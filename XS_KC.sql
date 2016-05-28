create table XS_KC
(
    sno char(6) not null,
    cno char(3) not null,
    constraint Fson foreign key(sno) references XSQK(sno),
    constraint Fcno foreign key(cno) references KC(cno),
    sscore tinyint check(sscore between 0 and 100)
);
