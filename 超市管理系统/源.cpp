#include<stdio.h>
#include<mysql.h>
#include "db_config.h"
#include "function.h"
#include "menu.h"
int main() {
	MYSQL mysql;
	mysql_init(&mysql);
	//�������û��������룬���ݿ����ƣ��˿ںţ��׽����ļ�·�����ͻ��˱�־λ��
	MYSQL* conn = mysql_real_connect(&mysql, DB_HOST, DB_USER, DB_PWD, DB_NAME, 3306, NULL, 0);
	if (conn == NULL) {
		printf("Connect failed\n");
		return 1;
	}
	printf("Connect sucessful\n");

	menu(&mysql);
	mysql_close(conn);
}