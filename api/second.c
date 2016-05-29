#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
/*using select*/
#define passwd_len 20
void deal_result(MYSQL_RES *msg) {
    MYSQL_ROW row;
    while (row = mysql_fetch_row(msg)) {
        int i = 0;
        for (; i<mysql_num_fields(msg); ++i) {
            printf("%s ", row[i]);
        }
        printf("\n");
    }
}
int main(){
    MYSQL *handle = mysql_init((MYSQL *)0);
    const char *ip = "localhost";
    const char *user = "root";
    char passwd[passwd_len] = "";
    const char *db = "hgg";
    printf("please input the passwd:");
    scanf("%s", passwd);
    if (handle != NULL &&
        mysql_real_connect(handle, ip, user, passwd, db, 3306, NULL, 0)) {
        if (!mysql_select_db(handle, db)){
            char sql_quary[128] = "";
            getchar();
            printf("input sql quary:");
            fgets(sql_quary, sizeof(sql_quary)-1, stdin);
            if (!mysql_real_query(handle, sql_quary, strlen(sql_quary))){
                MYSQL_RES *res = mysql_store_result(handle);
                deal_result(res);
            }
            else {
                printf("send\n");
            }
        }
        else {
            printf("select db\n");
        }
    }
    else {
        printf("connect\n");
    }
    return 0;
}
