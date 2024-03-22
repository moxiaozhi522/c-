#include<stdio.h>
#include<stdlib.h>//ʹ����malloc�����Լ�exit����
#include<string.h>
typedef struct Cour//���۸��γ����Ƽ���ƽ���ֵĽṹ��
{	char course_name[50];//�γ���
	double course_ave;//�γ�ƽ����
	char max_name[20];//�ÿγ���߷ֵ�������
	double course_max;//�ÿγ���߷�
	int rank[5];//ѧ���š������С����񲻼��������

}CLASS;
typedef struct Course//��¼ѧ���Ŀγ����ƺͷ����Ľṹ��
{
	char course_name[50];
	double course_score;
}COURSE;
typedef struct student//��¼ѧ����Ϣ�Ľṹ��
{
	int ID;//ѧ����
	char name[20];//ѧ������
	double ave;//ѧ��ƽ����
	double sum;//ѧ���ܷ�
	COURSE course[20];//ѧ�����Ը��ſγ����
	struct student* next;//nextָ��ָ����һ�����
}STU;
int menu();//�˵�����
STU* Create_student1(STU* head);//��������ѧ����Ϣ�ĺ���
STU* Create_student2(STU* head);//���ļ������ѧ����Ϣ�ĺ���
STU* Del_student1(STU* head);//��ѧ��ɾ��ѧ����Ϣ�ĺ���
STU* Del_student2(STU* head);//������ɾ��ѧ����Ϣ�ĺ���
STU* Insert_student1(STU* head);//��ѧ�Ų���ѧ����Ϣ�ĺ���
STU* Insert_student2(STU* head);//����������ѧ����Ϣ�ĺ���
STU* Search_student1(STU* head);//��ѧ�Ų���ѧ����Ϣ�ĺ���
STU* Search_student2(STU* head);//����������ѧ����Ϣ�ĺ�����
void* Rank_student(STU* head);//�ɼ�������
void BubbleSort1(STU* head, int score_num);//��ĳ�ųɼ�ð��������
void BubbleSort2(STU* head);//���ܳɼ�ð��������
void print1(STU* head);//��ʾѧ����Ϣ����Ļ����
void print2(STU* head);//��ʾѧ����Ϣ���ļ��ĺ���
CLASS class_num[20];
int course_num;//�γ�����
int stu_num;//ѧ������
int main() {
	int select, op;//select����˵�ѡ�op�����ڲ���ĳЩѡ��
	STU* head;//headͷ���
	STU* p;//��ʱ���
	head = NULL;
	while(true) {
		system("CLS");//��������
		select = menu();//���ò˵�
		if (select == 0)break;
		switch (select) {
		case 1:
			system("CLS");//����
			head = Create_student1(head);//����ѧ���ɼ�ϵͳ
			break;
		case 2:
			system("CLS");
			head = Create_student2(head);//����ѧ���ɼ�ϵͳ
			break;
		case 3:
			system("CLS");
			if (head == NULL) {//�ɼ�ϵͳû��ѧ����Ϣ����ʾ�û�������ѧ����Ϣ
				printf("��������ѧ����Ϣ");
			}
			else {
				system("CLS");
				p = head->next;
				print1(head);//��ʾѧ����Ϣ����Ļ

			}break;
		case 4:
			system("CLS");
			p = head->next;
			print2(head);//��ʾѧ����Ϣ���ļ�
			break;
		case 5:
			system("CLS");
			printf("������ɾ����ʽ��\n");
			printf("1.��ѧ��ɾ��\n");
			printf("2.������ɾ��\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Del_student1(head);//��ѧ��ɾ��ѧ����Ϣ
			}
			else {
				head = Del_student2(head);//������ɾ��ѧ����Ϣ
			}
			break;
		case 6:
			system("CLS");
			printf("��ѡ�����ķ�ʽ��\n");
			printf("1.��ѧ�Ų���\n");
			printf("2.����������\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Insert_student1(head);//��ѧ�Ų���ѧ����Ϣ��

			}
			else {
				head = Insert_student2(head);//����������ѧ����Ϣ

			}
			break;
		case 7:
			system("CLS");
			printf("��ѡ����ҵķ�ʽ\n");
			printf("1.��ѧ�Ų���\n");
			printf("1.��ѧ�Ų���\n");
			scanf_s("%d", &op);
			if (op == 1) {
				head = Search_student1(head);//��ѧ�Ų���ѧ����Ϣ

			}
			else {
				head = Search_student2(head);//����������ѧ����Ϣ
			}
			break;
		case 8:
			system("CLS");
			Rank_student(head);//�ɼ�������
			break;
			

		}
		printf("�밴Enter������\n");
		getchar();
		



	}
	return 0;

}
int menu() {//�˵�����
	int choice;
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("~*--------С�ͽ������ϵͳ---------*~\n");
	printf("~*       1.�Ӽ������ѧ����Ϣ      *~\n");
	printf("~*       2.���ļ����ѧ����Ϣ      *~\n");
	printf("~*       3.��ʾѧ����Ϣ����Ļ      *~\n");
	printf("~*       4.��ʾѧ����Ϣ���ļ�      *~\n");
	printf("~*       5.ɾ��ѧ����Ϣ            *~\n");
	printf("~*       6.����ѧ����Ϣ            *~\n");
	printf("~*       7.����ѧ����Ϣ            *~\n");
	printf("~*       8.�ɼ�����                *~\n");
	printf("~*       0.�˳�                    *~\n");
	printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
	printf("������ѡ��:");
	scanf_s("%d", &choice);
	getchar();
	return choice;
}
//���̴���ѧ����Ϣ����
STU* Create_student1(STU* head) {//���ѧ����Ϣ�ĺ���
	STU* p1 = NULL;
	STU* p2 = NULL;
	int i, j, k;
	head = (STU*)malloc(sizeof(STU));
	p2 = head;
	printf("��������ѧ������");//���뱾�ο���ѧ������
	scanf_s("%d", &stu_num);
	printf("�����뱾��ѧ���μӿγ̿��Ե���Ŀ��\n");
	scanf_s("%d", &course_num);
	getchar();
	printf("�����뱾�θ��ſγ̿��Գɼ������ƣ�\n");
	//�γ̳�ʼ��
	for (i = 0; i < course_num; i++)
	{
		printf("��%d�ſγ̣�", i + 1);
		gets_s(class_num[i].course_name);//��ȡ�ַ�����
		class_num[i].course_ave = 0;//��ʼ���ÿγ̵�ƽ����
		class_num[i].course_max = 0;//��ʼ���ÿγ̵���߷�
		for (k = 0; k < 5; k++) {
			class_num[i].rank[k] = 0;//��ʼ���ÿγ̵ĸ��ȼ�������
		}

	}
	//ѧ����Ϣ���
	for (i = 0; i < stu_num; i++) {
		system("CLS");
		p1 = (STU*)malloc(sizeof(STU));
		p2->next = p1;
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("ѧ�ţ�");
		scanf_s("%d", &p1->ID);
		printf("������");
		getchar();
		gets_s(p1->name);
		p1->sum = 0;
		for (j = 0; j < course_num; j++) {
			printf("������%s�ɼ���", class_num[j].course_name);
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
			//�������ѧ�����ųɼ�����߷ָߣ�����߷ָ�Ϊ���ѧ��
			if (p1->course[j].course_score > class_num[j].course_max) {
				class_num[j].course_max = p1->course[j].course_score;
				strcpy_s(class_num[j].max_name, p1->name);//��¼�γ̵���߷�ѧ������
			}
			strcpy_s(p1->course[j].course_name, class_num[j].course_name);
			p1->sum += p1->course[j].course_score;//��ѧ����ǰ�ּܷ��ϴ��ſγ̵ķ���
			class_num[j].course_ave += p1->course[j].course_score;//���ſγ�ƽ���ּ��ϴ�ѧ�����ſγ̳ɼ�
		}
		p1->ave = p1->sum / course_num;//�����ѧ����ƽ����
		p2 = p1;
	}
	//�γ�ƽ�������
	for (j = 0; j < course_num; j++) {
		class_num[j].course_ave /= stu_num;//�������пγ̵�ƽ����
	}
	p1->next = NULL;
	return head;

}
//�ļ�����ѧ����Ϣ����---����һ���ļ���������
STU* Create_student2(STU* head) {
	FILE* fp;//�ļ�ָ��fp
	char file_name[100] ="\0";
	printf("�������ļ�����λ�ü�����\n");
	printf("(just like:D:\\\\file.txt)\n");
	gets_s(file_name);//��ȡһ��ָ�����ı��ļ�
	//����ļ��޷������򿪣���fopen��������һ��NULLָ��
	errno_t Err = fopen_s(&fp, file_name, "r+");
	if (Err !=0) {
		printf("���ļ���%s ʧ�ܣ���\n", file_name);
		exit(0);//��ʾ�������г����˳�����
	}
	STU* p1 = NULL;
	STU* p2 = NULL;
	int i, j, k;
	head = (STU*)malloc(sizeof(STU));
	p2 = head;
	printf("��������ѧ������");
	scanf_s("%d", &stu_num);
	printf("�������뱾��ѧ���μӵĿγ̿��Ե���Ŀ");
	scanf_s("%d", &course_num);
	getchar();
	printf("�������뱾�θ��ſ��Ե�����");
	for (i = 0; i < course_num; i++) {
		printf("��%d�ſγ̣�", i + 1);
		gets_s(class_num[i].course_name);
		class_num[i].course_ave = 0;//��ʼ���ÿγ̵�ƽ����
		class_num[i].course_max = 0;//��ʼ���ÿγ̵���߷�
		for (k = 0; k < 5; k++) {
			class_num[i].rank[k] = 0;//��ʼ���ÿγ̵ĸ��ȼ�����
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
			fscanf_s(fp, "%lf", &p1->course[j].course_score);//�ж������ѧ���ɼ��ȼ�
			if (p1->course[j].course_score >= 90)
				class_num[j].rank[0]++;//����ÿγ̵ĵȼ�������
			else if (p1->course[j].course_score >= 80)
				class_num[j].rank[1]++;
			else if (p1->course[j].course_score >= 70)
				class_num[j].rank[2]++;
			else if (p1->course[j].course_score >= 60)
				class_num[j].rank[3]++;
			else
				class_num[j].rank[4]++;
			//�������ѧ�����ųɼ�����߷�Ҫ�ߣ���߷�Ϊ���ѧ��
			if (p1->course[j].course_score > class_num[j].course_max) {
				class_num[j].course_max = p1->course[j].course_score;
				strcpy_s(class_num[j].max_name, p1->name);
			}
			strcpy_s(p1->course[j].course_name, class_num[j].course_name);
			p1->sum += p1->course[j].course_score;//��ѧ����ǰ�ּܷ��ϴ��ſγ̷���
			class_num[j].course_ave += p1->course[j].course_score;//����ƽ���ּ��ϴ�ѧ�����ųɼ�
		}
		p1->ave = p1->sum / course_num;//�������ѧ����ƽ����
		p2 = p1;
	}
	for (j = 0; j < course_num; j++) {
		class_num[j].course_ave /= stu_num;//�������пγ̵�ƽ���֣�
	}
	p1->next = NULL;
	fclose(fp);
	return head;


}
void print1(STU* head) {//��ʾѧ����Ϣ����Ļ�ĺ���
	STU* p;
	int i,j;
	int n = 9;
	p = head->next;
	printf("ȫ��ѧ����Ϣ��\n");
	printf("---ѧ��--------����-");
	for (j = 0; j < course_num; j++) {
		for (i = 0; i < n; i++)//���������ʽ
			printf("-");
		printf("%s", class_num[j].course_name);
	}
	printf("-----------�ܷ�--------------ƽ����");
	printf("\n");
	while (p != NULL) {//���ѧ����Ϣ
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
	printf("����ƽ����");//�������ƽ����
	n = 17;//���Ƹ�ʽ
	for (j = 0; j < course_num; j++) {
		if (j > 0)//���Ƹ�ʽǰ����
			n = 7;
		for (i = 0; i < n; i++)
			printf(" ");
		printf("%.2lf", class_num[j].course_ave);
	}
	printf("\n");
	printf("������߷֣�  ");//���������߷�
	for (j = 0; j < course_num; j++) {
		printf("%s:%s(%.21f)   ", class_num[j].course_name, class_num[j].max_name, class_num[j].course_max);

	}
	printf("\n");
	printf("���Ƹ��ֶ����������    \n");
	for (j = 0; j < course_num; j++) {
		int stu_pass = 0;//��¼��������
		for (int l = 0; l < 4; l++) {
			stu_pass += class_num[j].rank[l];
		}
		printf("%s:      ", class_num[j].course_name);
		printf("��(%2d��)     ����%2d�ˣ�  ", class_num[j].rank[0], class_num[j].rank[1]);
		printf("��(%2d��)     ����%2d�ˣ� ������%2d�ˣ�  ", class_num[j].rank[2], class_num[j].rank[3],class_num[j].rank[4]);
		printf("�ܼ��������� %2d    �����ʣ�%4.2lf%%��\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
	}
}
void print2(STU* head)//��ʾѧ����Ϣ���ļ��ĺ���
{
	STU* p;
	FILE* fb;
	errno_t Err = fopen_s(&fb, "D:\\��Ϣ.txt", "w");
	if (Err != 0) {
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);//��ʾ�������г����˳�����
	}
	int i,j;
	int n = 9;
	p = head->next;
	fprintf(fb, "ȫ��ѧ����Ϣ��\n");
	fprintf(fb, "---ѧ��--------����-");
	for (j = 0; j < course_num; j++) {
		for (i = 0; i < n; i++)
			fprintf(fb, "-");
		if (n < 9)
			n++;
		fprintf(fb, "%s", class_num[j].course_name);
	}

	fprintf(fb, "-----------�ܷ�--------------ƽ����");
	fprintf(fb, "\n");
	while (p) {//���ѧ����Ϣ
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
	fprintf(fb, "����ƽ���֣�  ");
	for (j = 0; j < course_num; j++) {
		fprintf(fb, "%s(%.2lf)  ", class_num[j].course_name, class_num[j].course_ave);
	}
	fprintf(fb, "\n");
	fprintf(fb, "������߷֣�  ");
	for (j = 0; j < course_num; j++) {
		fprintf(fb, "%s:%s(%.2lf)  ", class_num[j].course_name,class_num[j].max_name, class_num[j].course_max);
	}
	fprintf(fb, "\n");
	fprintf(fb, "���Ƹ��ֶ����������  \n");
	for (j = 0; j < course_num; j++) {
		int stu_pass = 2;
		for (int l = 0; l < 4; l++) {
			stu_pass += class_num[j].rank[l];
		}
		fprintf(fb, "%s:    ", class_num[j].course_name);
		fprintf(fb,"��(%2d��)     ����%2d�ˣ�  ", class_num[j].rank[0], class_num[j].rank[1]);
		fprintf(fb,"��(%2d��)     ����%2d�ˣ� ������%2d�ˣ�  ", class_num[j].rank[2], class_num[j].rank[3], class_num[j].rank[4]);
		fprintf(fb,"�ܼ��������� %2d    �����ʣ�%4.2lf%%��\n", stu_pass, stu_pass * 1.0 / stu_num * 100);
	}
	fclose(fb);
}
STU* Del_student1(STU* head) {//��ѧ��ɾ��ѧ����Ϣ�ĺ���
	struct student* p1;//p1���浱ǰ��Ҫ���Ľ���ַ
	struct student* p2=NULL;//p2���浱ǰ�����Ľ���ַ
	int ID;
	int j, op1 = 1;
	if (head == NULL) {
		printf("ѧ����Ϣ������!\n");
		return head;
	}
	while (op1) {
		printf("������Ҫɾ����ѧ��ѧ�ţ�");
		scanf_s("%d", &ID);
		p1 = head;
		while (p1->ID != ID && p1->next != NULL)//p1ָ��Ľ�㲻����ҪѰ�ҵģ��������������һ����㣬�ͼ���������
		{
			p2 = p1;//���浱ǰ���ĵ�ַ
			p1 = p1->next;//����һ�����
		}
		if (p1->ID == ID) {//�ҵ���
			if (p1 == head)//���Ҫɾ���Ľ����ͷ���
			{
				head = p1->next;//ͷָ��ָ���һ���������һ����㣬Ҳ���ǵڶ�����㣬������һ�����Ͳ�ס�����У���ɾ��
			}
			else {//�����������㣬����ԭ��ָ��ǰ����ָ�룬ָ��������һ����㣬���ɾ��
				p2->next = p1->next;
			}
			stu_num--;//ѧ��������һ
			for (j = 0; j < course_num; j++) {//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
				if (strcmp(p1->name, class_num[j].max_name) == 0)//���ɾ����ѧ��Ϊ�ÿγ̵���߷�
				{
					class_num[j].course_max = 0;
					STU* p2 = head;
					while (p2->next != NULL) {//���²�����߷ֵ�ѧ��
						if (p2->course[j].course_score > class_num[j].course_max) {
							class_num[j].course_max = p2->course[j].course_score;
							strcpy_s(class_num[j].max_name, p2->name);
						}
						p2 = p2->next;
					}


				}
				if (p1->course[j].course_score >= 90)//���ѧ�����ųɼ����ڵ���90�����ŵ�������һ
					class_num[j].rank[0]--;
				else if (p1->course[j].course_score >= 80)//���ѧ�����ųɼ����ڵ���90��������������һ
					class_num[j].rank[1]--;
				else if (p1->course[j].course_score >= 70)//���ѧ�����ųɼ����ڵ���90�����е�������һ
					class_num[j].rank[2]--;
				else if (p1->course[j].course_score >= 60)//���ѧ�����ųɼ����ڵ���90���򼰸��������һ
					class_num[j].rank[3]--;
				else //���ѧ�����ųɼ����ڵ���90���򲻼����������һ
					class_num[j].rank[4]--;
				class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
				class_num[j].course_ave /= stu_num;
			}
			printf("ѧ����%s(ѧ��Ϊ%d)�Ѿ��Ӹ�ϵͳɾ��\n", p1->name, p1->ID);
			free(p1);
			p1 = NULL;

		}
		else //û���ҵ��������ѧ�Ų�����
		{
			printf("ѧ��%d������", ID);
		}
		printf("�Ƿ������ɾ�������������ɾ��������1����������0��");
		scanf_s("%d", &op1);
		system("CLS");//��������
	}
	return head;
}
STU* Del_student2(STU* head) {//������ɾ��ѧ����Ϣ�ĺ���
	struct student* p1;//p1���浱ǰ��Ҫ���Ľ���ַ
	struct student* p2=NULL;//p2���浱ǰ�����Ľ���ַ
	char name[20];
	int j, op1 = 1;
	if (head == NULL) {
		printf("ѧ����Ϣ����ʧ�ܣ�\n");
		return head;
	}
	while (op1) {
		printf("������Ҫɾ����ѧ��������");
		getchar();//ȡǰ��Ļس���
		gets_s(name);
		p1 = head;
		while (strcmp(p1->name, name) != 0 && p1->next != NULL)//p1ָ��Ľ�㲻����Ҫ���ҵģ��������������һ����㣬�ͼ�������ȥ
		{
			p2 = p1;
			p1 = p1->next;

		}
		if (strcmp(p1->name, name) == 0)//�ҵ���
		{
			if (p1 == head) {
				head = p1->next;//ͷָ��ָ���һ�����ĺ�һ����㣬Ҳ���ǵڶ�����㣬������һ�����Ͳ��ڱ��У���ɾ��

			}
			else {//�����������㣬����ԭ��ָ��ǰ����ָ�룬ָ��������һ����㣬���ɾ��
				p2->next = p1->next;

			}
			stu_num--;//ѧ��������֮��һ
			for (j = 0; j < course_num; j++) {//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
				if (strcmp(p1->name, class_num[j].max_name) == 0) {
					class_num[j].course_max = 0;
					STU* p2 = head;
					while (p2->next != NULL) {//���²�����߷ֵ�ѧ��
						if (p2->course[j].course_score > class_num[j].course_max) {
							class_num[j].course_max = p2->course[j].course_score;
							strcpy_s(class_num[j].max_name, p2->name);
						}
						p2 = p2->next;
					}

				}
				if (p1->course[j].course_score >= 90)//���ѧ�����ųɼ����ڵ���90�����ŵ�������һ
					class_num[j].rank[0]--;
				else if (p1->course[j].course_score >= 80)//���ѧ�����ųɼ����ڵ���90��������������һ
					class_num[j].rank[1]--;
				else if (p1->course[j].course_score >= 70)//���ѧ�����ųɼ����ڵ���90�����е�������һ
					class_num[j].rank[2]--;
				else if (p1->course[j].course_score >= 60)//���ѧ�����ųɼ����ڵ���90���򼰸��������һ
					class_num[j].rank[3]--;
				else //���ѧ�����ųɼ����ڵ���90���򲻼����������һ
					class_num[j].rank[4]--;
				class_num[j].course_ave = class_num[j].course_ave * (stu_num + 1) - p1->course[j].course_score;
				class_num[j].course_ave /= stu_num;
			}
			printf("ѧ����%s(ѧ��Ϊ%d)�Ѿ��Ӹ�ϵͳɾ��\n", p1->name, p1->ID);
			free(p1);//�ͷŵ�ǰ���
			p1 = NULL;

		}
		else {//û���ҵ������ѧ��������
			printf("����%s������", name);

		}
		printf("�Ƿ������ɾ��?(�������ɾ��������1,��������0)");
		scanf_s("%d", &op1);
		system("CLS");//��������
	}
	return head;
}
STU* Insert_student1(STU* head) {//��ѧ�Ų���ѧ����Ϣ�ĺ���
	int ID, op, j, op1 = 1;
	while (op1) {
		STU* p1 = NULL, * p2 = NULL;//p1���浱ǰ��Ҫ���Ľ���ַ
		STU *stud;
		stud = (STU*)malloc(sizeof(STU));
		printf("������Ҫ����λ�õ�ѧ�ţ�");
		scanf_s("%d", &ID);//���������λ�õ�ѧ��
		printf("������ڸ�ѧ��ǰ����ߺ���");
		printf("1.ǰ�棬2.����");
		scanf_s("%d", &op);
		printf("��������������ѧ����Ϣ��\n");
		printf("ѧ�ţ�");
		scanf_s("%d", &stud->ID);
		getchar();
		printf("������");
		gets_s(stud->name);
		stud->sum = 0;
		for (j = 0; j < course_num; j++)//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
		{
			printf("������%s������", class_num[j].course_name);
			scanf_s("%lf", &stud->course[j].course_score);
			strcpy_s(stud->course[j].course_name, class_num[j].course_name);
			stud->sum += stud->course[j].course_score;
			class_num[j].course_ave = class_num[j].course_ave * stu_num + stud->course[j].course_score;
			if (stud->course[j].course_score > class_num[j].course_max)//��������ѧ�����ųɼ���֮ǰ��߳ɼ�Ҫ�ߣ����ѧ��Ϊ���ſγ���߷�
			{
				class_num[j].course_max = stud->course[j].course_score;
				strcpy_s(class_num[j].max_name, stud->name);
			}
			if (stud->course[j].course_score >= 90)//�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
				class_num[j].rank[0]++;
			else if (stud->course[j].course_score >= 80)//�����ѧ�����ųɼ����ڵ���80��,������������1
				class_num[j].rank[1]++;
			else if (stud->course[j].course_score >= 70)//�����ѧ�����ųɼ����ڵ���70��,���е�������1
				class_num[j].rank[2]++;
			else if (stud->course[j].course_score >= 60)//�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
				class_num[j].rank[3]++;
			else//�����ѧ�����ųɼ�С�ڵ���60��,�򲻼����������1
				class_num[j].rank[4]++;
		}
		stud->ave = stud->sum / course_num;
		stu_num++;//ѧ��������1
		for (j = 0; j < course_num; j++) {
			class_num[j].course_ave /= stu_num;
		}
		if (head == NULL)//�������Ϊ�գ���ֱ�Ӳ���
		{
			head = stud;
			stud->next = NULL;
		}
		else {
			p1 = head;
			while (p1->ID != ID && p1->next != NULL) //p1ָ��Ľ�㲻��Ҫ���ҵģ��������������һ����㣬�����������
				{
					p2 = p1;
					p1 = p1->next;//����һ�����
				}
			if (p1->ID == ID)//�ҵ���
				{
					if (op == 2)//�����ں���
					{
						stud->next = p1->next;
						p1->next = stud;
					}
					else {//����ǰ��
						stud->next = p1;
						p2->next = stud;
					}
				}
			else {//���û�ҵ���λ�õ�ѧ�ţ���ѯ���Ƿ�������һ��
					printf("û�ҵ���λ�õ�ѧ�ţ�\n");
					printf("�Ƿ���Ҫ����ѧ�����뵽���һ��������������1����������0��\n");
					int op1;
					scanf_s("%d", &op1);
					if (op1) {
						p1->next = stud;
						stud->next = NULL;
					}
				}
			}
			
		
		printf("�Ƿ���������룿����������1����������0��\n");
		scanf_s("%d", &op1);
		system("CLS");
		
	}
	return head;
}
STU* Insert_student2(STU* head) {//����������ѧ����Ϣ�ĺ���
	int op, j, op1 = 1;
	while (op1) {
		STU* p1 = NULL, * p2 = NULL;//p1���浱ǰ��Ҫ���Ľ���ַ
		STU* stu1;
		stu1 = (STU*)malloc(sizeof(STU));
		printf("������Ҫ�����λ�õ�������");
		char name[20];
		getchar();
		gets_s(name);
		printf("���ڸ�����ǰ����ߺ��棿");
		printf("1.ǰ�棬2.����");
		scanf_s("%d", &op);
		printf("��������������ѧ����Ϣ��\n");
		printf("ѧ�ţ�");
		scanf_s("%d", &stu1->ID);
		getchar();
		printf("������");
		gets_s(stu1->name);
		stu1->sum = 0;
		for (j = 0; j < course_num; j++) {//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
			printf("������%s������", class_num[j].course_name);
			scanf_s("%lf", &stu1->course[j].course_score);
			strcpy_s(stu1->course[j].course_name, class_num[j].course_name);
			stu1->sum += stu1->course[j].course_score;
			class_num[j].course_ave = class_num[j].course_ave * stu_num + stu1->course[j].course_score;
			if (stu1->course[j].course_score > class_num[j].course_max)//����¼����ѧ�����ųɼ���֮ǰ��߳ɼ����ߣ����ѧ���ɼ�Ϊ���ſγ���߷�
			{
				class_num[j].course_max = stu1->course[j].course_score;
				strcpy_s(class_num[j].max_name,stu1->name);
			}
			
			if (stu1->course[j].course_score >= 90)//�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
				class_num[j].rank[0]++;
			else if (stu1->course[j].course_score >= 80)//�����ѧ�����ųɼ����ڵ���80��,������������1
				class_num[j].rank[1]++;
			else if (stu1->course[j].course_score >= 70)//�����ѧ�����ųɼ����ڵ���70��,���е�������1
				class_num[j].rank[2]++;
			else if (stu1->course[j].course_score >= 60)//�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
				class_num[j].rank[3]++;
			else//�����ѧ�����ųɼ�С�ڵ���60��,�򲻼����������1
				class_num[j].rank[4]++;

		}
		stu1->ave = stu1->sum / course_num;
		stu_num++;//ѧ��������1
		for (j = 0; j < course_num; j++) {
			class_num[j].course_ave /= stu_num;
		}
		if (head == NULL)//�������Ϊ�գ���ֱ�Ӳ���
		{
			head = stu1;
			stu1->next = NULL;

		}
		else {
			p1 = head;
			while (strcmp(p1->name, name) != 0 && p1->next != NULL)//p1��ָ��㲻����Ҫ�ҵģ��������������һ����㣬����������
			{
				p2 = p1;
				p1 = p1->next;
			}
			if (strcmp(p1->name, name) == 0)//�ҵ���
			{
				if (op == 2) {
					stu1->next = p1->next;
					p1->next = stu1;//������p1����¸����
				}
				else {
					stu1->next = p1;
					p2->next = stu1;//����p1����ǰһ�����
				}
			}
			else {
				printf("û�ҵ���λ�õ�����\n");
				printf("�Ƿ���Ҫ����ѧ�����뵽���һ��������������1����������0��\n");
				int op1;
				scanf_s("%d", &op1);
				if (op1) {
					p1->next = stu1;
					stu1->next = NULL;

				}
			}
		}
		printf("�Ƿ�������������ݣ�����������1����������0��");
		scanf_s("%d", &op1);
		system("CLS");//��������
	}
	return head;
}
STU* Search_student1(STU* head)//��ѧ�Ų���ѧ����Ϣ�ĺ���
{
	int ID, j = 0, op1 = 1;
	while (op1) {
		STU* p;
		p = head;
		printf("������Ҫ���ҵ�ѧ��:");
		scanf_s("%d", &ID);
		while (p->ID != ID && p->next != NULL)//pָ��Ľ�㲻����Ҫ�ҵģ��������������һ����㣬�ͼ���������
		{
			p = p->next;
		}
		if (p->ID == ID)//�ҵ���
		{
			printf("�����Ǹ�ѧ���Ļ�����Ϣ��\n");
			printf("ѧ�ţ�%d\n", p->ID);
			printf("������%s\n", p->name);
			printf("�����Ǳ��ο��������\n");
			for (j = 0; j < course_num; j++) {
				printf("%s�ɼ���%.2lf\n", class_num[j].course_name, p->course[j].course_score);
			}
			printf("ƽ���֣�%.2lf\n", p->ave);
			printf("�ܷ֣�%.2lf\n", p->sum);
			printf("�Ƿ�Ҫ�޸ĸÿ����ĳɼ��������޸�����1����������0��");
			int op1;
			scanf_s("%d", &op1);
			while (op1) {//ʵ��ѧ���޸���Ϣ�Ĺ���
				getchar();
				char cou_name[20];
				double score=0.0;
				printf("������Ҫ�޸ĵĿγ�����\n");
				gets_s(cou_name);
				printf("�޸ĵķ�����\n");
				scanf_s("%lf", score);
				for (j = 0; j < course_num; j++) {//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
					if (strcmp(class_num[j].course_name, cou_name) == 0) {
						class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score+score;
						class_num[j].course_ave /= stu_num;
						break;
					}
				}
				if (p->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
					class_num[j].rank[0]--;
				else if (p->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
					class_num[j].rank[1]--;
				else if (p->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
					class_num[j].rank[2]--;
				else if (p->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
					class_num[j].rank[3]--;
				else
					class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
				if (score >= 90)                                //������ųɼ��޸ĺ���ڵ���90��,���ŵ�������1
					class_num[j].rank[0]++;
				else if (score >= 80)                            //������ųɼ��޸ĺ���ڵ���80��,������������1
					class_num[j].rank[1]++;
				else if (score >= 70)                            //������ųɼ��޸ĺ���ڵ���70��,���е�������1
					class_num[j].rank[2]++;
				else if (score >= 60)                            //������ųɼ��޸ĺ���ڵ���60��,�򼰸��������1
					class_num[j].rank[3]++;
				else
					class_num[j].rank[4]++;                    //������ųɼ��޸ĺ�С��60��,�򲻼����������1
				if (score > class_num[j].course_max) {//������ųɼ��޸ĺ��֮ǰ��߳ɼ����ߣ�����ųɼ�Ϊ�ÿγ���߷�
					class_num[j].course_max = score;
					strcpy_s(class_num[j].max_name, p->name);
				}
				p->course[j].course_score = score;
				printf("�Ƿ���Ҫ�޸ĸÿ����������ɼ�����Ҫ������1����������0��");
				scanf_s("%d", &op1);
			}
		}
		else {
			printf("��ѧ������ϵͳ��\n");//û�ҵ�
		}
		printf("�Ƿ���������ң����������������1����������0��");
		scanf_s("%d", &op1);
		system("CLS");//��������
	}
	return head;
}
STU* Search_student2(STU* head) {//����������ѧ����Ϣ�ĺ���
	int j = 0, op1 = 1;
	char name[20];
	while (op1) {
		STU* p;
		p = head;
		printf("������Ҫ���ҵ�������");
		getchar();
		gets_s(name);//����Ҫ���ҵ�����
		while (strcmp(p->name, name) != 0 && p->next != NULL)//pָ��Ľ�㲻��Ҫ�ҵģ��������������һ����㣬�ͼ���������
		{
			p = p->next;//����ָ��

		}
		if (strcmp(p->name, name) == 0)//�ҵ��ˣ���ʾѧ����Ϣ
		{
			printf("�����Ǹ�ѧ���Ļ�����Ϣ��\n");
			printf("ѧ�ţ�%d\n", p->ID);
			printf("������%s\n", p->name);
			printf("�����Ǳ��ο������:\n");
			for (j = 0; j < course_num; j++) {
				printf("%s�ɼ���%.2lf\n", class_num[j].course_name, p->course[j].course_score);
			}
			printf("ƽ���֣�%.2lf\n", p->ave);
			printf("�ܷ֣�%.2lf\n", p->sum);
			printf("�Ƿ�Ҫ�޸ĸÿ����ĳɼ��������޸�����1����������0��");
			int op1;
			scanf_s("%d", &op1);
			while (op1) {//ʵ��ѧ���޸���Ϣ�Ĺ���
				getchar();
				char cou_name[20];
				double score=0.0;
				printf("������Ҫ�޸ĵĿγ�����\n");
				gets_s(cou_name);
				printf("�޸ĵķ�����\n");
				scanf_s("%lf", score);
				for (j = 0; j < course_num; j++) {//���¼�����ſγ̵�ƽ���֣���߷֣����ȼ�����
					if (strcmp(class_num[j].course_name, cou_name) == 0) {
						class_num[j].course_ave = class_num[j].course_ave * stu_num - p->course[j].course_score + score;
						class_num[j].course_ave /= stu_num;
						break;
					}
				}
				if (p->course[j].course_score >= 90)            //�����ѧ�����ųɼ����ڵ���90��,���ŵ�������1
					class_num[j].rank[0]--;
				else if (p->course[j].course_score >= 80)        //�����ѧ�����ųɼ����ڵ���80��,������������1
					class_num[j].rank[1]--;
				else if (p->course[j].course_score >= 70)        //�����ѧ�����ųɼ����ڵ���70��,���е�������1
					class_num[j].rank[2]--;
				else if (p->course[j].course_score >= 60)        //�����ѧ�����ųɼ����ڵ���60��,�򼰸��������1
					class_num[j].rank[3]--;
				else
					class_num[j].rank[4]--;                    //�����ѧ�����ųɼ�С��60��,�򲻼����������1
				if (score >= 90)                                //������ųɼ��޸ĺ���ڵ���90��,���ŵ�������1
					class_num[j].rank[0]++;
				else if (score >= 80)                            //������ųɼ��޸ĺ���ڵ���80��,������������1
					class_num[j].rank[1]++;
				else if (score >= 70)                            //������ųɼ��޸ĺ���ڵ���70��,���е�������1
					class_num[j].rank[2]++;
				else if (score >= 60)                            //������ųɼ��޸ĺ���ڵ���60��,�򼰸��������1
					class_num[j].rank[3]++;
				else
					class_num[j].rank[4]++;                    //������ųɼ��޸ĺ�С��60��,�򲻼����������1
				if (score > class_num[j].course_max) {//������ųɼ��޸ĺ��֮ǰ��߳ɼ����ߣ�����ųɼ�Ϊ�ÿγ���߷�
					class_num[j].course_max = score;
					strcpy_s(class_num[j].max_name, p->name);
				}
				p->course[j].course_score = score;
				printf("�Ƿ���Ҫ�޸ĸÿ����������ɼ�����Ҫ������1����������0��");
				scanf_s("%d", &op1);
			}
		}
		else
			printf("��ѧ������ϵͳ��\n");//û�ҵ�
		printf("�Ƿ���������ң���������������1����������0��");
		scanf_s("%d", &op1);
		system("CLS");
	}
	return head;
}
void* Rank_student(STU* head)//�ɼ�������
{
	char cou_name[50];
	int j, op1;
	printf("��������Ҫ��������ʽ��\n");//ѡ������ʽ
	printf("1.���Ƴɼ�������2.�ܳɼ�����");
	scanf_s("%d", &op1);
	getchar();
	if (op1 == 1) {
		printf("������Ҫ�����Ŀγ�����");
		gets_s(cou_name);
		for (j = 0; j < course_num; j++)//Ѱ�ҿγ����ڵ��±�
			if (strcmp(cou_name, class_num[j].course_name) == 0)
				break;
		BubbleSort1(head, j);
	}
	else
		BubbleSort2(head);
	return head;
}
void BubbleSort1(STU* head, int score_num) {//��ĳ�ųɼ�����ĺ���
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