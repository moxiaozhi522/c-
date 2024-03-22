#include<stdio.h>
#include<mysql.h>
#include "db_config.h"
#include "function.h"
#include "menu.h"
int main() {
	MYSQL mysql;
	mysql_init(&mysql);
	//主机，用户名，密码，数据库名称，端口号，套接字文件路径，客户端标志位。
	MYSQL* conn = mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_PWD, DB_NAME, 3306, NULL, 0);
	if (conn == NULL) {
		printf("Connect failed\n");
		return 1;
	}
	printf("Connect sucessful\n");

	menu(&mysql);
	mysql_close(conn);
}