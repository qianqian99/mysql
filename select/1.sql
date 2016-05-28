-- select sname, sno, prof from XSQK;
-- select sname, sno, prof from XSQK group by prof;
-- select sno, sname, prof from XSQK order by sno;
-- select sno, sname, prof from XSQK order by sno desc;
-- select distinct prof, sno, sname from XSQK order by sno;
-- select * from XSQK where sname like 'fan%';
/*查询计算机学院的女生*/
/*select * from XSQK
where dept = 'jisuanji' and sex = 'female';*/
/*查询有dept有学生*/
/*没有group时，对最后的结果进行基数，有group, count for every group*/
/*select dept, count(*) from XSQK
group by dept;*/
-- select * from KC where time <> 45;
/*确定集合*/
-- select * from XS_KC where cno in ('102', '103');
/*课程得分最高的学号*/
-- select sno, cno, MAX(sscore) from XS_KC group by cno; 
/*101课程高分与低分的差距*/
/*select MAX(sscore) as high, MIN(sscore) as low, MAX(sscore)-MIN(sscore) as diff
from XS_KC
where cno = '101';*/
-- select cno, count(*)  from XS_KC group by cno order by count(*) ;
-- select * from XS_KC where sscore > 60 order by sscore desc;
-- select cno, count(sno) as num from XS_KC group by cno having count(sno) >=3 ;
