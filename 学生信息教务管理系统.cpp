#include<stdio.h>
#include<stdlib.h>//使用了malloc函数以及exit函数
#include<string.h>
typedef struct Cour//积累各课程名称及其平均分的结构体
{	char course_name[50];//课程名
	double course_ave;//课程平均分
	char max_name[20];//该课程最高分的人名字
	double course_max;//该课程最高分
	int rank[5];//学生优、良、中、及格不及格的人数

}CLASS;
typedef struct Course//记录学生的课程名称和分数的结构体
{
	char course_name[50];
	double course_score;
}COURSE;
typedef struct student//记录学生信息的结构体
{
	int ID;//学生号
	char name[20];//学生姓名
	double ave;//学生平均分
	double sum;//学生总分
	COURSE course[20];//学生考试各门课程情况
	struct student* next;//next指针指向下一个结点
}STU;
int menu();//菜单函数
STU* Create_student1(STU* head);//键盘输入学生信息的函数
STU* Create_student2(STU* head);//从文件中添加学生信息的函数
STU* Del_student1(STU* head);//按学号删除学生信息的函数
STU* Del_student2(STU* head);//按姓名删除学生信息的函数
STU* Insert_student1(STU* head);//按学号插入学生信息的函数
STU* Insert_student2(STU* head);//按姓名插入学生信息的函数
STU* Search_student1(STU* head);//按学号查找学生信息的函数
STU* Search_student2(STU* head);//按姓名查找学生信息的函数；
void* Rank_student(STU* head);//成绩排序函数
void BubbleSort1(STU* head, int score_num);//按某门成绩冒泡排序函数
void BubbleSort2(STU* head);//按总成绩冒泡排序函数
void print1(STU* head);//显示学生信息到屏幕函数
void print2(STU* head);//显示学生信息到文件的函数
CLASS class_num[20];
int course_num;//课程总数
int stu_num;//学生总数
int main() {
	int select, op;//select代表菜单选项，op函数内部的某些选项
	STU* head;//head头结点
	STU* p;//临时结点
	head = NULL;
	while(true) {
		system("CLS");//清屏函数
		select = menu();//调用菜单
		if (select == 0)break;
		switch (select) {
		case 1:
			system("CLS");//清屏
			head = Create_student1(head);//建立学生成绩系统
			break;
		case 2:
			system("CLS");
			head = Create_student2(head);//建立学生成绩系统
			break;
		case 3:
			system("CLS");
			if (head == NULL) {//成绩系统没有学生信息，提示用户先输入学生信息
				printf("请先输入学生信息");
			}
			else {
				system("CLS");
				p = head->next;
				print1(head);//显示学生信息到屏幕

			}break;
		case 4:
			system("CLS");
			p = head->next;
			print2(head);//显示学生信息到文件
			break;
		case 5:
			system("CLS");
			printf("请输入删除方式：\n");
			printf("1.按学号删除\n");
			printf("2.按姓名删除\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Del_student1(head);//按学号删除学生信息
			}
			else {
				head = Del_student2(head);//按姓名删除学生信息
			}
			break;
		case 6:
			system("CLS");
			printf("请选择插入的方式：\n");
			printf("1.按学号插入\n");
			printf("2.按姓名插入\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Insert_student1(head);//按学号插入学生信息；

			}
			else {
				head = Insert_student2(head);//按姓名插入学生信息

			}
			break;
		case 7:
			system("CLS");
			printf("请选择查找的方式\n");
			printf("1.按学号查找\n");
			printf("1.按学号查找\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Search_student1(head);//按学号查找学生信息

			}
			else {
				head = Search_student2(head);//按姓名查找学生信息
			}
			break;
		case 8:
			system("CLS");
			Rank_student(head);//成绩排序函数
			break;
			

		}
		printf("请按Enter键继续\n");
		getchar();
		



	}
	return 0;

}
int menu() {//菜单函数
	int choice;
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("~*--------小型教务管理系统---------*~\n");
	printf("~*       1.从键盘添加学生信息      *~\n");
	printf("~*       2.从文件添加学生信息      *~\n");
	printf("~*       3.显示学生信息到屏幕      *~\n");
	printf("~*       4.显示学生信息到文件      *~\n");
	printf("~*       5.删除学生信息            *~\n");
	printf("~*       6.插入学生信息            *~\n");
	printf("~*       7.查找学生信息            *~\n");
	printf("~*       8.成绩排名                *~\n");
	printf("~*       0.退出                    *~\n");
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("请输入选项:");
	scanf_s("%d", &choice);
	getchar();
	return choice;
}
//键盘创建学生信息函数
STU* Create_student1(STU* head) {//添加学生信息的函数
	STU* p1 = NULL;
	STU* p2 = NULL;
	int i, j, k;
	head = (STU*)malloc(sizeof(STU));
	p2 = head;
	printf("请先输入学生人数");//输入本次考试学生总数
	scanf_s("%d", &stu_num);
	printf("请输入本次学生参加课程考试的数目：\n");
	scanf_s("%d", &course_num);
	getchar();
	printf("请输入本次各门课程考试成绩的名称：\n");
	//课程初始化
	for (i = 0; i < course_num; i++)
	{
		printf("第%d门课程：", i + 1);
		gets_s(class_num[i].course_name);//读取字符数组
		class_num[i].course_ave = 0;//初始化该课程的平均分
		class_num[i].course_max = 0;//初始化该课程的最高分
		for (k = 0; k < 5; k++) {
			class_num[i].rank[k] = 0;//初始化该课程的各等级人数；
		}

	}
	//学生信息相关
	for (i = 0; i < stu_num; i++) {
		system("CLS");
		p1 = (STU*)malloc(sizeof(STU));
		p2->next = p1;
		printf("请输入第%d个学生的信息：\n", i + 1);
		printf("学号：");
		scanf_s("%d", &p1->ID);
		printf("姓名：");
		getchar();
		gets_s(p1->name);
		p1->sum = 0;
		for (j = 0; j < course_num; j++) {
			printf("请输入%s成绩：", class_num[j].course_name);
			scanf_s("%lf", &p1->course[j].course_score);
			if (p1->course[j].course_score >= 90)
				class_num[j].rank[0]++;
			else if (p1->course[j].course_score >= 80)
				class_num[j].rank[1]++;
			else if (p1->course[j].course_score >= 70)
				class_num[j].rank[2]++;
			else if (p1->course[j].course_score >= 60)
				class_num[j].rank[3]++;
			else
				class_num[j].rank[4]++;
			//如果该名学生该门成绩比最高分高，则最高分改为这个学生
			if (p1->course[j].course_score > class_num[j].course_max) {
				class_num[j].course_max = p1->course[j].course_score;
				strcpy_s(class_num[j].max_name, p1->name);//记录课程的最高分学生名字
			}
			strcpy_s(p1->course[j].course_name, class_num[j].course_name);
			p1->sum += p1->course[j].course_score;//该学生当前总分加上此门课程的分数
			class_num[j].course_ave += p1->course[j].course_score;//该门课程平均分加上此学生该门课程成绩
		}
		p1->ave = p1->sum / course_num;//计算该学生的平均分
		p2 = p1;
	}
	//课程平均分相关
	for (j = 0; j < course_num; j++) {
		class_num[j].course_ave /= stu_num;//计算所有课程的平均分
	}
	p1->next = NULL;
	return head;

}
//文件创建学生信息函数---锻炼一下文件操作步骤
STU* Create_student2(STU* head) {
	FILE* fp;//文件指针fp
	char file_name[100] ="\0";
	printf("请输入文件所在位置及名称\n");
	printf("(just like:D:\\\\file.txt)\n");
	gets_s(file_name);//读取一个指定的文本文件
	//如果文件无法正常打开，则fopen函数返回一个NULL指针
	errno_t Err = fopen_s(&fp, file_name, "r+");
	if (Err !=0) {
		printf("打开文件：%s 失败！！\n", file_name);
		exit(0);//表示正常运行程序并退出程序
	}
	STU* p1 = NULL;
	STU* p2 = NULL;
	int i, j, k;
	head = (STU*)malloc(sizeof(STU));
	p2 = head;
	printf("请先输入学生人数");
	scanf_s("%d", &stu_num);
	printf("请先输入本次学生参加的课程考试的数目");
	scanf_s("%d", &course_num);
	getchar();
	printf("请先输入本次各门考试的名称");
	for (i = 0; i < course_num; i++) {
		printf("第%d门课程：", i + 1);
		gets_s(class_num[i].course_name);
		class_num[i].course_ave = 0;//初始化该课程的平均分
		class_num[i].course_max = 0;//初始化该课程的最高分
		for (k = 0; k < 5; k++) {
			class_num[i].rank[k] = 0;//初始化该课程的各等级人数
		}
	}
	for (i = 0; i < stu_num; i++) {
		system("CLS");
		p1 = (STU*)malloc(sizeof(STU));
		p2->next = p1;
		fscanf_s(fp, "%d", &p1->ID);
		fscanf_s(fp, "%s", p1->name);
		p1->sum = 0;
		for (j = 0; j < course_num; j++) {
			fscanf_s(fp, "%lf", &p1->course[j].course_score);//判断输入的学生成绩等级
			if (p1->course[j].course_score >= 90)
				class_num[j].rank[0]++;//存入该课程的等级数组中
			else if (p1->course[j].course_score >= 80)
				class_num[j].rank[1]++;
			else if (p1->course[j].course_score >= 70)
				class_num[j].rank[2]++;
			else if (p1->course[j].course_score >= 60)
				class_num[j].rank[3]++;
			else
				class_num[j].rank[4]++;
			//如果该名学生该门成绩比最高分要高，最高分为这个学生
			if (p1->course[j].course_score > class_num[j].course_max) {
				class_num[j].course_max = p1->course[j].course_score;
				strcpy_s(class_num[j].max_name, p1->name);
			}
			strcpy_s(p1->course[j].course_name, class_num[j].course_name);
			p1->sum += p1->course[j].course_score;//该学生当前总分加上此门课程分数
			class_num[j].course_ave += p1->course[j].course_score;//该门平均分加上此学生该门成绩
		}
		p1->ave = p1->sum / course_num;//计算该名学生的平均分
		p2 = p1;
	}
	for (j = 0; j < course_num; j++) {
		class_num[j].course_ave /= stu_num;//计算所有课程的平均分；
	}
	p1->next = NULL;
	fclose(fp);
	return head;


}
void print1(STU* head) {//显示学生信息到屏幕的函数
	STU* p;
	int i,j;
	int n = 9;
	p = head->next;
	printf("全体学生信息：\n");
	printf("---学号--------姓名-");
	for (j = 0; j < course_num; j++) {
		for (i = 0; i < n; i++)//控制输出格式
			printf("-");
		printf("%s", class_num[j].course_name);
	}
	printf("-----------总分--------------平均分");
	printf("\n");
	while (p != NULL) {//输出学生信息
		printf("%11d", p->ID);
		printf("%10s", p->name);
		for (j = 0; j < course_num; j++) {
			printf("%12.2lf", p->course[j].course_score);
		}
		printf("%13.2lf", p->sum);
		printf("%12.2lf", p->ave);
		p = p->next;
		printf("\n");

		

	}
	printf("各科平均分");//输出各科平均分
	n = 17;//控制格式
	for (j = 0; j < course_num; j++) {
		if (j > 0)//控制格式前几列
			n = 7;
		for (i = 0; i < n; i++)
			printf(" ");
		printf("%.2lf", class_num[j].course_ave);
	}
	printf("\n");
	printf("各科最高分：  ");//输出各科最高分
	for (j = 0; j < course_num; j++) {
		printf("%s:%s(%.21f)   ", class_num[j].course_name, class_num[j].max_name, class_num[j].course_max);

	}
	printf("\n");
	printf("各科各分段人数情况：    \n");
	for (j = 0; j < course_num; j++) {
		int stu_pass = 0;//记录及格人数
		for (int l = 0; l < 4; l++) {
			stu_pass += class_num[j].rank[l];
		}
		printf("%s:      ", class_num[j].course_name);
		printf("优(%2d人)     良（%2d人）  ", class_num[j].rank[0], class_num[j].rank[1]);
		printf("中(%2d人)     及格（%2d人） 不及格（%2d人）  ", class_num[j].rank[2], class_num[j].rank[3],class_num[j].rank[4]);
		printf("总及格人数： %2d    及格率（%4.2lf%%）\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
	}
}
void print2(STU* head)//显示学生信息到文件的函数
{
	STU* p;
	FILE* fb;
	errno_t Err = fopen_s(&fb, "D:\\信息.txt", "w");
	if (Err != 0) {
		printf("打开文件失败！\n");
		exit(0);//表示正常运行程序并退出程序
	}
	int i,j;
	int n = 9;
	p = head->next;
	fprintf(fb, "全体学生信息：\n");
	fprintf(fb, "---学号--------姓名-");
	for (j = 0; j < course_num; j++) {
		for (i = 0; i < n; i++)
			fprintf(fb, "-");
		if (n < 9)
			n++;
		fprintf(fb, "%s", class_num[j].course_name);
	}

	fprintf(fb, "-----------总分--------------平均分");
	fprintf(fb, "\n");
	while (p) {//输出学生信息
		fprintf(fb, "%8d", p->ID);
		fprintf(fb, "%12s", p->name);
		for (j = 0; j < course_num; j++) {
			fprintf(fb, "%13.2lf", p->course[j].course_score);
		}
		fprintf(fb, "%13.2lf", p->sum);
		fprintf(fb, "%12.2lf", p->ave);
		p = p->next;
		fprintf(fb, "\n");

	}
	fprintf(fb, "各科平均分：  ");
	for (j = 0; j < course_num; j++) {
		fprintf(fb, "%s(%.2lf)  ", class_num[j].course_name, class_num[j].course_ave);
	}
	fprintf(fb, "\n");
	fprintf(fb, "各科最高分：  ");
	for (j = 0; j < course_num; j++) {
		fprintf(fb, "%s:%s(%.2lf)  ", class_num[j].course_name,class_num[j].max_name, class_num[j].course_max);
	}
	fprintf(fb, "\n");
	fprintf(fb, "各科各分段人数情况：  \n");
	for (j = 0; j < course_num; j++) {
		int stu_pass = 2;
		for (int l = 0; l < 4; l++) {
			stu_pass += class_num[j].rank[l];
		}
		fprintf(fb, "%s:    ", class_num[j].course_name);
		fprintf(fb,"优(%2d人)     良（%2d人）  ", class_num[j].rank[0], class_num[j].rank[1]);
		fprintf(fb,"中(%2d人)     及格（%2d人） 不及格（%2d人）  ", class_num[j].rank[2], class_num[j].rank[3], class_num[j].rank[4]);
		fprintf(fb,"总及格人数： %2d    及格率（%4.2lf%%）\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
	}
	fclose(fb);
}
STU* Del_student1(STU* head) {//按学号删除学生信息的函数
	struct student* p1;//p1保存当前需要检查的结点地址
	struct student* p2=NULL;//p2保存当前检查过的结点地址
	int ID;
	int j, op1 = 1;
	if (head == NULL) {
		printf("学生信息不存在!\n");
		return head;
	}
	while (op1) {
		printf("请输入要删除的学生学号：");
		scanf_s("%d", &ID);
		p1 = head;
		while (p1->ID != ID && p1->next != NULL)//p1指向的结点不是所要寻找的，并且它不是最后一个结点，就继续往下找
		{
			p2 = p1;//保存当前结点的地址
			p1 = p1->next;//后移一个结点
		}
		if (p1->ID == ID) {//找到了
			if (p1 == head)//如果要删除的结点是头结点
			{
				head = p1->next;//头指针指向第一个结点的最后一个结点，也就是第二个结点，这样第一个结点就不住链表中，即删除
			}
			else {//如果是其他结点，则让原来指向当前结点的指针，指向它的下一个结点，完成删除
				p2->next = p1->next;
			}
			stu_num--;//学生总数减一
			for (j = 0; j < course_num; j++) {//重新计算各门课程的平均分，最高分，各等级人数
				if (strcmp(p1->name, class_num[j].max_name) == 0)//如果删除的学生为该课程的最高分
				{
					class_num[j].course_max = 0;
					STU* p2 = head;
					while (p2->next != NULL) {//重新查找最高分的学生
						if (p2->course[j].course_score > class_num[j].course_max) {
							class_num[j].course_max = p2->course[j].course_score;
							strcpy_s(class_num[j].max_name, p2->name);
						}
						p2 = p2->next;
					}


				}
				if (p1->course[j].course_score >= 90)//如果学生该门成绩大于等于90，则优的人数减一
					class_num[j].rank[0]--;
				else if (p1->course[j].course_score >= 80)//如果学生该门成绩大于等于90，则良的人数减一
					class_num[j].rank[1]--;
				else if (p1->course[j].course_score >= 70)//如果学生该门成绩大于等于90，则中的人数减一
					class_num[j].rank[2]--;
				else if (p1->course[j].course_score >= 60)//如果学生该门成绩大于等于90，则及格的人数减一
					class_num[j].rank[3]--;
				else //如果学生该门成绩大于等于90，则不及格的人数减一
					class_num[j].rank[4]--;
				class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
				class_num[j].course_ave /= stu_num;
			}
			printf("学生：%s(学号为%d)已经从该系统删除\n", p1->name, p1->ID);
			free(p1);
			p1 = NULL;

		}
		else //没有找到，则输出学号不存在
		{
			printf("学号%d不存在", ID);
		}
		printf("是否还想继续删除？（若想继续删除则输入1，否则输入0）");
		scanf_s("%d", &op1);
		system("CLS");//清屏函数
	}
	return head;
}
STU* Del_student2(STU* head) {//按姓名删除学生信息的函数
	struct student* p1;//p1保存当前需要检查的结点地址
	struct student* p2=NULL;//p2保存当前检查过的结点地址
	char name[20];
	int j, op1 = 1;
	if (head == NULL) {
		printf("学生信息表建立失败！\n");
		return head;
	}
	while (op1) {
		printf("请输入要删除的学生姓名：");
		getchar();//取前面的回车符
		gets_s(name);
		p1 = head;
		while (strcmp(p1->name, name) != 0 && p1->next != NULL)//p1指向的结点不是所要查找的，并且它不是最后一个结点，就继续找下去
		{
			p2 = p1;
			p1 = p1->next;

		}
		if (strcmp(p1->name, name) == 0)//找到了
		{
			if (p1 == head) {
				head = p1->next;//头指针指向第一个结点的后一个结点，也就是第二个结点，这样第一个结点就不在表中，即删除

			}
			else {//如果是其他结点，则让原来指向当前结点的指针，指向它的下一个结点，完成删除
				p2->next = p1->next;

			}
			stu_num--;//学生人数随之减一
			for (j = 0; j < course_num; j++) {//重新计算各门课程的平均分，最高分，各等级人数
				if (strcmp(p1->name, class_num[j].max_name) == 0) {
					class_num[j].course_max = 0;
					STU* p2 = head;
					while (p2->next != NULL) {//重新查找最高分的学生
						if (p2->course[j].course_score > class_num[j].course_max) {
							class_num[j].course_max = p2->course[j].course_score;
							strcpy_s(class_num[j].max_name, p2->name);
						}
						p2 = p2->next;
					}

				}
				if (p1->course[j].course_score >= 90)//如果学生该门成绩大于等于90，则优的人数减一
					class_num[j].rank[0]--;
				else if (p1->course[j].course_score >= 80)//如果学生该门成绩大于等于90，则良的人数减一
					class_num[j].rank[1]--;
				else if (p1->course[j].course_score >= 70)//如果学生该门成绩大于等于90，则中的人数减一
					class_num[j].rank[2]--;
				else if (p1->course[j].course_score >= 60)//如果学生该门成绩大于等于90，则及格的人数减一
					class_num[j].rank[3]--;
				else //如果学生该门成绩大于等于90，则不及格的人数减一
					class_num[j].rank[4]--;
				class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
				class_num[j].course_ave /= stu_num;
			}
			printf("学生：%s(学号为%d)已经从该系统删除\n", p1->name, p1->ID);
			free(p1);//释放当前结点
			p1 = NULL;

		}
		else {//没有找到，输出学生不存在
			printf("姓名%s不存在", name);

		}
		printf("是否还想继续删除?(若想继续删除则输入1,否则输入0)");
		scanf_s("%d", &op1);
		system("CLS");//清屏函数
	}
	return head;
}
STU* Insert_student1(STU* head) {//按学号插入学生信息的函数
	int ID, op, j, op1 = 1;
	while (op1) {
		STU* p1 = NULL, * p2 = NULL;//p1保存当前需要检查的结点地址
		STU *stud;
		stud = (STU*)malloc(sizeof(STU));
		printf("请输入要插入位置的学号：");
		scanf_s("%d", &ID);//输入待插入位置的学号
		printf("你想插在该学号前面或者后面");
		printf("1.前面，2.后面");
		scanf_s("%d", &op);
		printf("请输入你想插入的学生信息：\n");
		printf("学号：");
		scanf_s("%d", &stud->ID);
		getchar();
		printf("姓名：");
		gets_s(stud->name);
		stud->sum = 0;
		for (j = 0; j < course_num; j++)//重新计算各门课程的平均分，最高分，各等级人数
		{
			printf("请输入%s分数：", class_num[j].course_name);
			scanf_s("%lf", &stud->course[j].course_score);
			strcpy_s(stud->course[j].course_name, class_num[j].course_name);
			stud->sum += stud->course[j].course_score;
			class_num[j].course_ave = class_num[j].course_ave * stu_num + stud->course[j].course_score;
			if (stud->course[j].course_score > class_num[j].course_max)//如果加入的学生该门成绩比之前最高成绩要高，则该学生为该门课程最高分
			{
				class_num[j].course_max = stud->course[j].course_score;
				strcpy_s(class_num[j].max_name, stud->name);
			}
			if (stud->course[j].course_score >= 90)//如果该学生该门成绩大于等于90分,则优的人数加1
				class_num[j].rank[0]++;
			else if (stud->course[j].course_score >= 80)//如果该学生该门成绩大于等于80分,则良的人数加1
				class_num[j].rank[1]++;
			else if (stud->course[j].course_score >= 70)//如果该学生该门成绩大于等于70分,则中的人数加1
				class_num[j].rank[2]++;
			else if (stud->course[j].course_score >= 60)//如果该学生该门成绩大于等于60分,则及格的人数加1
				class_num[j].rank[3]++;
			else//如果该学生该门成绩小于等于60分,则不及格的人数加1
				class_num[j].rank[4]++;
		}
		stud->ave = stud->sum / course_num;
		stu_num++;//学生人数加1
		for (j = 0; j < course_num; j++) {
			class_num[j].course_ave /= stu_num;
		}
		if (head == NULL)//如果链表为空，则直接插入
		{
			head = stud;
			stud->next = NULL;
		}
		else {
			p1 = head;
			while (p1->ID != ID && p1->next != NULL) //p1指向的结点不是要查找的，并且它不是最后一个结点，则继续往下找
				{
					p2 = p1;
					p1 = p1->next;//后移一个结点
				}
			if (p1->ID == ID)//找到了
				{
					if (op == 2)//插入在后面
					{
						stud->next = p1->next;
						p1->next = stud;
					}
					else {//插在前面
						stud->next = p1;
						p2->next = stud;
					}
				}
			else {//如果没找到该位置的学号，则询问是否插在最后一个
					printf("没找到该位置的学号：\n");
					printf("是否需要将该学生插入到最后一个？（是则输入1，否则输入0）\n");
					int op1;
					scanf_s("%d", &op1);
					if (op1) {
						p1->next = stud;
						stud->next = NULL;
					}
				}
			}
			
		
		printf("是否还想继续插入？（继续输入1，否则输入0）\n");
		scanf_s("%d", &op1);
		system("CLS");
		
	}
	return head;
}
STU* Insert_student2(STU* head) {//按姓名插入学生信息的函数
	int op, j, op1 = 1;
	while (op1) {
		STU* p1 = NULL, * p2 = NULL;//p1保存当前需要检查的结点地址
		STU* stu1;
		stu1 = (STU*)malloc(sizeof(STU));
		printf("请输入要插入的位置的姓名：");
		char name[20];
		getchar();
		gets_s(name);
		printf("插在该姓名前面或者后面？");
		printf("1.前面，2.后面");
		scanf_s("%d", &op);
		printf("请输入你想插入的学生信息：\n");
		printf("学号：");
		scanf_s("%d", &stu1->ID);
		getchar();
		printf("姓名：");
		gets_s(stu1->name);
		stu1->sum = 0;
		for (j = 0; j < course_num; j++) {//重新计算各门课程的平均分，最高分，各等级人数
			printf("请输入%s分数：", class_num[j].course_name);
			scanf_s("%lf", &stu1->course[j].course_score);
			strcpy_s(stu1->course[j].course_name, class_num[j].course_name);
			stu1->sum += stu1->course[j].course_score;
			class_num[j].course_ave = class_num[j].course_ave * stu_num + stu1->course[j].course_score;
			if (stu1->course[j].course_score > class_num[j].course_max)//如果新加入的学生该门成绩比之前最高成绩还高，则该学生成绩为该门课程最高分
			{
				class_num[j].course_max = stu1->course[j].course_score;
				strcpy_s(class_num[j].max_name,stu1->name);
			}
			
			if (stu1->course[j].course_score >= 90)//如果该学生该门成绩大于等于90分,则优的人数加1
				class_num[j].rank[0]++;
			else if (stu1->course[j].course_score >= 80)//如果该学生该门成绩大于等于80分,则良的人数加1
				class_num[j].rank[1]++;
			else if (stu1->course[j].course_score >= 70)//如果该学生该门成绩大于等于70分,则中的人数加1
				class_num[j].rank[2]++;
			else if (stu1->course[j].course_score >= 60)//如果该学生该门成绩大于等于60分,则及格的人数加1
				class_num[j].rank[3]++;
			else//如果该学生该门成绩小于等于60分,则不及格的人数加1
				class_num[j].rank[4]++;

		}
		stu1->ave = stu1->sum / course_num;
		stu_num++;//学生人数加1
		for (j = 0; j < course_num; j++) {
			class_num[j].course_ave /= stu_num;
		}
		if (head == NULL)//如果链表为空，则直接插入
		{
			head = stu1;
			stu1->next = NULL;

		}
		else {
			p1 = head;
			while (strcmp(p1->name, name) != 0 && p1->next != NULL)//p1所指结点不是所要找的，并且它不是最后一个结点，继续往下找
			{
				p2 = p1;
				p1 = p1->next;
			}
			if (strcmp(p1->name, name) == 0)//找到了
			{
				if (op == 2) {
					stu1->next = p1->next;
					p1->next = stu1;//插入在p1结点下个结点
				}
				else {
					stu1->next = p1;
					p2->next = stu1;//插在p1结点的前一个结点
				}
			}
			else {
				printf("没找到该位置的姓名\n");
				printf("是否需要将该学生插入到最后一个？（是则输入1，否则输入0）\n");
				int op1;
				scanf_s("%d", &op1);
				if (op1) {
					p1->next = stu1;
					stu1->next = NULL;

				}
			}
		}
		printf("是否还想继续插入数据？（继续输入1，否则输入0）");
		scanf_s("%d", &op1);
		system("CLS");//清屏函数
	}
	return head;
}
STU* Search_student1(STU* head)//按学号查找学生信息的函数
{
	int ID, j = 0, op1 = 1;
	while (op1) {
		STU* p;
		p = head;
		printf("请输入要查找的学号:");
		scanf_s("%d", &ID);
		while (p->ID != ID && p->next != NULL)//p指向的结点不是所要找的，并且它不是最后一个结点，就继续往下找
		{
			p = p->next;
		}
		if (p->ID == ID)//找到了
		{
			printf("以下是该学生的基本信息：\n");
			printf("学号：%d\n", p->ID);
			printf("姓名：%s\n", p->name);
			printf("以下是本次考试情况：\n");
			for (j = 0; j < course_num; j++) {
				printf("%s成绩：%.2lf\n", class_num[j].course_name, p->course[j].course_score);
			}
			printf("平均分：%.2lf\n", p->ave);
			printf("总分：%.2lf\n", p->sum);
			printf("是否要修改该考生的成绩（如需修改输入1，否则输入0）");
			int op1;
			scanf_s("%d", &op1);
			while (op1) {//实现学生修改信息的功能
				getchar();
				char cou_name[20];
				double score=0.0;
				printf("请输入要修改的课程名：\n");
				gets_s(cou_name);
				printf("修改的分数：\n");
				scanf_s("%lf", score);
				for (j = 0; j < course_num; j++) {//重新计算各门课程的平均分，最高分，各等级人数
					if (strcmp(class_num[j].course_name, cou_name) == 0) {
						class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score+score;
						class_num[j].course_ave /= stu_num;
						break;
					}
				}
				if (p->course[j].course_score >= 90)            //如果该学生该门成绩大于等于90分,则优的人数减1
					class_num[j].rank[0]--;
				else if (p->course[j].course_score >= 80)        //如果该学生该门成绩大于等于80分,则良的人数减1
					class_num[j].rank[1]--;
				else if (p->course[j].course_score >= 70)        //如果该学生该门成绩大于等于70分,则中的人数减1
					class_num[j].rank[2]--;
				else if (p->course[j].course_score >= 60)        //如果该学生该门成绩大于等于60分,则及格的人数减1
					class_num[j].rank[3]--;
				else
					class_num[j].rank[4]--;                    //如果该学生该门成绩小于60分,则不及格的人数减1
				if (score >= 90)                                //如果该门成绩修改后大于等于90分,则优的人数加1
					class_num[j].rank[0]++;
				else if (score >= 80)                            //如果该门成绩修改后大于等于80分,则良的人数加1
					class_num[j].rank[1]++;
				else if (score >= 70)                            //如果该门成绩修改后大于等于70分,则中的人数加1
					class_num[j].rank[2]++;
				else if (score >= 60)                            //如果该门成绩修改后大于等于60分,则及格的人数加1
					class_num[j].rank[3]++;
				else
					class_num[j].rank[4]++;                    //如果该门成绩修改后小于60分,则不及格的人数加1
				if (score > class_num[j].course_max) {//如果该门成绩修改后比之前最高成绩还高，则该门成绩为该课程最高分
					class_num[j].course_max = score;
					strcpy_s(class_num[j].max_name, p->name);
				}
				p->course[j].course_score = score;
				printf("是否还需要修改该考生的其他成绩（需要则输入1，否则输入0）");
				scanf_s("%d", &op1);
			}
		}
		else {
			printf("该学生不在系统中\n");//没找到
		}
		printf("是否还想继续查找？（若想继续则输入1，否则输入0）");
		scanf_s("%d", &op1);
		system("CLS");//清屏函数
	}
	return head;
}
STU* Search_student2(STU* head) {//按姓名查找学生信息的函数
	int j = 0, op1 = 1;
	char name[20];
	while (op1) {
		STU* p;
		p = head;
		printf("请输入要查找的姓名：");
		getchar();
		gets_s(name);//输入要查找的姓名
		while (strcmp(p->name, name) != 0 && p->next != NULL)//p指向的结点不是要找的，并且它不是最后一个结点，就继续往下找
		{
			p = p->next;//后移指针

		}
		if (strcmp(p->name, name) == 0)//找到了，显示学生信息
		{
			printf("以下是该学生的基本信息：\n");
			printf("学号：%d\n", p->ID);
			printf("姓名：%s\n", p->name);
			printf("以下是本次考试情况:\n");
			for (j = 0; j < course_num; j++) {
				printf("%s成绩：%.2lf\n", class_num[j].course_name, p->course[j].course_score);
			}
			printf("平均分：%.2lf\n", p->ave);
			printf("总分：%.2lf\n", p->sum);
			printf("是否要修改该考生的成绩（如需修改输入1，否则输入0）");
			int op1;
			scanf_s("%d", &op1);
			while (op1) {//实现学生修改信息的功能
				getchar();
				char cou_name[20];
				double score=0.0;
				printf("请输入要修改的课程名：\n");
				gets_s(cou_name);
				printf("修改的分数：\n");
				scanf_s("%lf", score);
				for (j = 0; j < course_num; j++) {//重新计算各门课程的平均分，最高分，各等级人数
					if (strcmp(class_num[j].course_name, cou_name) == 0) {
						class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score + score;
						class_num[j].course_ave /= stu_num;
						break;
					}
				}
				if (p->course[j].course_score >= 90)            //如果该学生该门成绩大于等于90分,则优的人数减1
					class_num[j].rank[0]--;
				else if (p->course[j].course_score >= 80)        //如果该学生该门成绩大于等于80分,则良的人数减1
					class_num[j].rank[1]--;
				else if (p->course[j].course_score >= 70)        //如果该学生该门成绩大于等于70分,则中的人数减1
					class_num[j].rank[2]--;
				else if (p->course[j].course_score >= 60)        //如果该学生该门成绩大于等于60分,则及格的人数减1
					class_num[j].rank[3]--;
				else
					class_num[j].rank[4]--;                    //如果该学生该门成绩小于60分,则不及格的人数减1
				if (score >= 90)                                //如果该门成绩修改后大于等于90分,则优的人数加1
					class_num[j].rank[0]++;
				else if (score >= 80)                            //如果该门成绩修改后大于等于80分,则良的人数加1
					class_num[j].rank[1]++;
				else if (score >= 70)                            //如果该门成绩修改后大于等于70分,则中的人数加1
					class_num[j].rank[2]++;
				else if (score >= 60)                            //如果该门成绩修改后大于等于60分,则及格的人数加1
					class_num[j].rank[3]++;
				else
					class_num[j].rank[4]++;                    //如果该门成绩修改后小于60分,则不及格的人数加1
				if (score > class_num[j].course_max) {//如果该门成绩修改后比之前最高成绩还高，则该门成绩为该课程最高分
					class_num[j].course_max = score;
					strcpy_s(class_num[j].max_name, p->name);
				}
				p->course[j].course_score = score;
				printf("是否还需要修改该考生的其他成绩（需要则输入1，否则输入0）");
				scanf_s("%d", &op1);
			}
		}
		else
			printf("该学生不在系统中\n");//没找到
		printf("是否还想继续查找？（若继续则输入1，否则输入0）");
		scanf_s("%d", &op1);
		system("CLS");
	}
	return head;
}
void* Rank_student(STU* head)//成绩排序函数
{
	char cou_name[50];
	int j, op1;
	printf("请输入想要的排名方式：\n");//选择排序方式
	printf("1.单科成绩排名，2.总成绩排名");
	scanf_s("%d", &op1);
	getchar();
	if (op1 == 1) {
		printf("请输入要排名的课程名称");
		gets_s(cou_name);
		for (j = 0; j < course_num; j++)//寻找课程所在的下标
			if (strcmp(cou_name, class_num[j].course_name) == 0)
				break;
		BubbleSort1(head, j);
	}
	else
		BubbleSort2(head);
	return head;
}
void BubbleSort1(STU* head, int score_num) {//按某门成绩排序的函数
	STU* p, * prep, * temp, * tail;
	tail = NULL;
	while (head->next != tail) {
		prep = head;
		p = head->next;
		while (p->next != tail) {
			if (p->course[score_num].course_score < p->next->course[score_num].course_score) {
				temp = p->next;
				prep->next = p->next;
				p->next = p->next->next;
				prep->next->next = p;
				p = temp;
			}
			p = p->next;
			prep = prep->next;
		}
		tail = p;
	}
}
void BubbleSort2(STU* head) {
	STU* p, * prep, * temp, * tail;
	tail = NULL;
	while (head->next != tail) {
		prep = head;
		p = head->next;
		while (p->next != tail) {
			if (p->sum < p->next->sum) {
				temp = p->next;
				prep->next = p->next;
				p->next = p->next->next;
				prep->next->next = p;
				p = temp;
			}
			p = p->next;
			prep = prep->next;

		}
		tail = p;
	}
}