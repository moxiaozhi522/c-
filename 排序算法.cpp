#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int a[N], b[N];
int com, mov;   //�Ƚϴ���,�ƶ�����
int n = 1000;

//ѡ������:ÿ�δ�������ѡ��һ���������ŵ������,�ظ�ִ��
int findmaxpos(int arr[], int n)     // �ҵ����ֵ
{
    int pos = 1;
    for (int i = 2; i <= n; i++) {
        com++;
        if (arr[i] > arr[pos]) {
            pos = i;
        }
    }
    return pos;
}
void selection_sort(int arr[], int n) {
    while (n > 1)    //����n����
    {
        int pos = findmaxpos(arr, n);
        if (pos != n)mov++;
        int temp = arr[pos];
        arr[pos] = arr[n];
        arr[n] = temp;
        n--;
    }
}

//��������:����ǰk���Ѿ��ź���,���ǾͿ����ҵ��µ������ȥ
void insert(int arr[], int i)    //����
{
    int key = arr[i];
    int j = i;
    while (j > 1 && arr[j - 1] > key) {
        com++;
        arr[j] = arr[j - 1];
        j--;
    }
    if (j != i)mov++;
    arr[j] = key;
}
void insert_sort(int arr[], int n)   //��������
{
    for (int i = 1; i <= n; i++)
        insert(arr, i);
}

//ð������
void bubble(int arr[], int n)  //ð��
{
    for (int i = 1; i < n; i++) {
        com++;
        if (arr[i] > arr[i + 1]) {
            mov++;
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}
void bubble_sort(int arr[], int n) //ð������
{
    for (int i = 1; i < n; i++)
        bubble(arr, n);
}

//ϣ������
void shell_sort(int arr[], int n) {
    for (int ins = n >> 1; ins; ins >>= 1) {
        for (int i = ins; i < n; i++) {
            for (int j = i - ins + 1; ++com, j >= 1 && arr[j] > arr[j + ins]; j -= ins, mov++)
                swap(arr[j], arr[j + ins]);
        }
    }
}

//��������
void quick_sort(int arr[], int L, int R) {
    int pivot = arr[(L + R) >> 1];
    int i = L, j = R;
    while (i <= j) {
        while (arr[i] < pivot)i++, com++;
        while (arr[j] > pivot)j--, com++;
        if (i <= j)swap(arr[i++], arr[j--]), mov++;
    }
    if (L < j)quick_sort(arr, L, j);
    if (i < R)quick_sort(arr, i, R);
}

//������
void heap_sort(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        int len = i;
        while (len != 1) {
            com++;
            if (arr[len] > arr[len >> 1])swap(arr[len], arr[len >> 1]), mov++;
            else break;
            len >>= 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        mov++;
        swap(arr[i], arr[1]);
        int len = 1;
        while ((len << 1) < i) {
            int nex = len << 1;
            com++;
            if ((nex + 1 < i) && (arr[nex] < arr[nex + 1]))nex++;
            com++;
            if (arr[len] >= arr[nex])break;
            mov++;
            swap(arr[len], arr[nex]);
            len = nex;
        }
    }
}

int menu()    //�˵�����
{
    int choice;
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
    printf("~*-----------�����㷨--------------*~\n");
    printf("~*          1.ѡ������             *~\n");
    printf("~*          2.��������             *~\n");
    printf("~*          3.ð������             *~\n");
    printf("~*          4.ϣ������             *~\n");
    printf("~*          5.��������             *~\n");
    printf("~*          6.������               *~\n");
    printf("~*          0.�˳�                 *~\n");
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
    printf("������ѡ��:");
    scanf("%d", &choice);
    getchar();
    return choice;
}

void print() {
    printf("����������Ϊ:\n");
    for (int i = 1; i <= n; i++) {
        printf("%5d ", b[i]);
        if (i % 10 == 0)
            printf("\n");
    }
    printf("�Ƚϴ���Ϊ:%d��,�ƶ�����Ϊ:%d��\n", com, mov);
}

int main() {
    ifstream infile;
    infile.open("C://Users//A//Desktop//data.txt");
    for (int i = 1; i <= n; i++)infile >> a[i];
    infile.close();
    int select, op;     //select����˵���ѡ�op�������ڲ���ĳЩѡ��
    while (true) {
        com = 0;
        mov = 0;
        memcpy(b, a, sizeof(a));
        system("CLS");    //��������
        select = menu();        //���ò˵�����
        if (select == 0)break;
        switch (select) {
        case 1:
            system("CLS");    //��������
            selection_sort(b, n);    //ѡ������
            print();
            break;
        case 2:
            system("CLS");    //��������
            insert_sort(b, n);    //��������
            print();
            break;
        case 3:
            system("CLS");    //��������
            bubble_sort(b, n);    //ð������
            print();
            break;
        case 4:
            system("CLS");    //��������
            shell_sort(b, n);    //ϣ������
            print();
            break;
        case 5:
            system("CLS");    //��������
            quick_sort(b, 1, n);  //��������
            print();
            break;
        case 6:
            system("CLS");    //��������
            heap_sort(b, n);   //������
            print();
            break;
        }
        printf("�밴Enter������\n");
        getchar();
    }
    return 0;
}

�������������

#include<bits/stdc++.h>

#define ll long long
#define random(a, b) ((a)+rand()%((b)-(a)+1))
using namespace std;

int main() {
    freopen("C://Users//A//Desktop//data.txt", "w", stdout);
    srand((unsigned)time(0));
    int n = 100;
    for (int i = 0; i < n; i++)
        printf("%d ", random(1, 1000000));
    printf("\n");
}