#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
int main(){
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char tmp[256] = "";
    char dbusr[30] = "root";
    char dbpasswd[30] = "hggldgj..1314";
    char dbip[30] = "localhost";
    char dbname[50] = "class";
    char dbtable[30] = "stu";
    char *query = NULL;
    
    int x, y, rt;
    unsigned t;
    int count = 0;
    printf("input x, y:");
    scanf("%d, %d", &x, &y);
    fflush(stdin);

    con = mysql_init((MYSQL*)0);
    if (con != NULL &&
            mysql_real_connect(con, dbip, dbusr, 
                dbpasswd, dbname,3306, NULL, 0)) {
        if (!mysql_select_db(con, dbname)) {
            //printf("Select successful\n");
            //con->reconnect = 1;
            //query = "set names \'GBK\'";
            //rt = mysql_real_query(con, query, strlen(query));
            //if (rt) {
            //    printf("Error making query: %s!!!\n", mysql_error(con));
            //}
            //else {
            //    printf("query %s succeed!\n", query);
            //}
        }

    }
    else {
        printf("error\n");
    }
    sprintf(tmp, "insert into %s values(%s, %d, %d)", dbtable, "null", x, y);
    rt = mysql_real_query(con, tmp, strlen(tmp));
    if (rt) {
        printf("Error making query: %s", mysql_error(con));
    }
    else {
        printf("%s executed!!!!\n", tmp);
    }
    mysql_close(con);
    return 0;
}
