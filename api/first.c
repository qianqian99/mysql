#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
int main(){
    MYSQL *con = mysql_init((MYSQL*)0);
    char usr[] = "root";
    char passwd[] = "hggldgj..1314";
    char db[] = "class";
    char table[] = "stu";
    char ip[] = "localhost";
    if (con == NULL) {
        printf("init error\n");
    }
    if (!mysql_real_connect(con, ip, usr, passwd, db, 3306, NULL, 0)) {
        printf("connect error\n");
    }
    if (mysql_select_db(con, db)) {
        printf("select db error\n");
    }
    char name[20] = "";
    char sql_quary[256] = "";
    int x = 0;
    int y = 0;
    scanf("%s %d %d", name, &x, &y);
    sprintf(sql_quary, "insert into %s values(%s, %d, %d)", table, name, x, y);
    int res = mysql_real_query(con, sql_quary, strlen(sql_quary));
    if (res) {
        printf("mysql_real_query error\n");
    }
    mysql_close(con);
    return 0;

}
