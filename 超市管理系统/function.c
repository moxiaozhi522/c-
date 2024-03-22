#include "function.h"

//-----���ò���------//
int create_database(MYSQL* conn) {
	char query[100];
	sprintf_s(query,100,"create database product_info;");
	return mysql_query(conn, query);
}
int create_table_ItemInfo(MYSQL* conn) {
	char query[100];
	sprintf_s(query, 100, "create table item_info(id varchar(10) not null primary key, name varchar(10) not null, price int not null, inventory int not null;");
	return mysql_query(conn, query);

}
int create_table_LoginInfo(MYSQL* conn) {
	char query[1024];
	sprintf_s(query, 1024, "create table login_info(id varchar(10) not null primary key, name varchar(10) not null, pwd varchar(10) not null;");
	return mysql_query(conn, query);
}
int create_table_BasicInfo(MYSQL* conn) {
	char query[1024];
	sprintf_s(query, 1024, "create table basic_info(id varchar(10) not null primary key, name varchar(10) not null, sex varchar(5) not null, age varchar(3) not null, tel_number varchar(11) not null;");
	return mysql_query(conn, query);
}
int show_tables(MYSQL* conn) {
	char query[100];
	char sql[100];
	printf("Enter to select the table:\n");
	scanf_s("%s", sql);
	sprintf_s(query, 100, "select * from %s;", sql);
	return mysql_query(conn, query);
}
int add_item(MYSQL* conn, char id[], char name[], int price, int inventory) {
	char query[100];
	sprintf_s(query, 100, "insert into item_info values(\"%s\", \"%s\", % d, % d); ", id, name, price, inventory);
	if (mysql_query(conn, query)) {//����Ʒ�Ѵ��ڣ������x
		sprintf_s(query, 100, "update item_info set inventory=inventory+(%d) where id=(\"%s\");", inventory, id);
		return mysql_query(conn, query);
	}
	return 0;
}
int delete_item(MYSQL* conn, char id[], char name[]) {
	char query[100];
	sprintf_s(query, 100, "delete from item_info where id=(\"%s\") and name=(\"%s\");", id, name);
	return mysql_query(conn, query);
}
int show_item(MYSQL* conn, MYSQL_RES* res) {
	char query[100];
	char str[] = "id               name            price             inventory";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from item_info;");
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s ", row[i]);
		}
		printf("\n");
	}
	mysql_free_result(res);
	return 0;
}
int show_item_id(MYSQL* conn, MYSQL_RES* res, char id[]) {
	char query[100];
	char str[] = "id               name     price    inventory";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from item_info where id=\"%s\";", id);
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s", row[i]);
		}
		printf("\n");
	}
	mysql_free_result(res);
	return 0;
}
int add_login(MYSQL* conn, char id[], char name[], char pwd[]) {
	char query[100];
	sprintf_s(query, 100, "insert into login_info values(\"%s\",\"%s\",\"%s\");", id, name, pwd);
	return mysql_query(conn, query);
}
int delete_login(MYSQL* conn, char id[], char name[]) {
	char query[100];
	sprintf_s(query, 100, "delete from login_info where id=(\"%s\") and name=(\"%s\");", id, name);
	return mysql_query(conn, query);

}
int show_login(MYSQL* conn, MYSQL_RES *res) {
	char query[100];
	char str[] = "id        name      pwd";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from login_info;");
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s", row[i]);
		}
		printf("\n");
	}
	mysql_free_result(res);
	return 0;
}
int show_login_id(MYSQL* conn, MYSQL_RES* res, char id[]) {
	char query[100];
	char str[] = "id     name     pwd";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from login_info where id=\"%s\";", id);
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s ", row[i]);
		}
		printf("\n");

	}
	mysql_free_result(res);
	return 0;
}

int add_basic(MYSQL* conn, char id[], char name[], char sex[], char age[], char tel_number[]) {
	char query[1024];
	sprintf_s(query, 100, "insert into basic_info values(\"%s\",\"%s\",\"%s\",\"%s\");", id, name, sex, age, tel_number);
	return mysql_query(conn, query);
}
int delete_basic(MYSQL* conn, char id[], char name[]) {
	char query[100];
	sprintf_s(query, 100, "delete from basic_info where id=(\"%s\") and name=(\"%s\");", id, name);
	return mysql_query(conn, query);
}
int show_basic(MYSQL* conn, MYSQL_RES* res) {
	char query[100];
	char str[] = "id                name          sex         age          tel_number";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from basic_info");
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for (int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s ", row[i]);
		}
		printf("\n");
	}
	mysql_free_result(res);
	return 0;
}
int show_basic_id(MYSQL* conn, MYSQL_RES* res, char id[]) {
	char query[100];
	char str = "id           name          sex       age            tel_number";
	MYSQL_ROW row;
	sprintf_s(query, 100, "select * from basic_info where id=\"%s\";", id);
	mysql_query(conn, query);
	res = mysql_use_result(conn);
	printf("%s\n", str);
	while ((row = mysql_fetch_row(res))) {
		for(int i = 0; i < mysql_num_fields(res); i++) {
			printf("%-15s", row[i]);
		}
		printf("\n");
	}
	mysql_free_result(res);
	return 0;
}