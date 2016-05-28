create table XSQK
(
    sno char(6) not null primary key,
    sname char(8) not null,
    sex char(6) not null default 'male',
    birth date not null,
    prof char(10) not null,
    dept char(10) not null,
    tel char(11)
);
