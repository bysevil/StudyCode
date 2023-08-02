#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

//�����ã���ӡmine����
void test(int x, int y, int mine[101][101]) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            printf("%d ", mine[i][j]);
        }
        printf("\n");
    }
    printf("***********************\n");
}
//ʧ��ʱ����ӡmine����
void print(int x, int y, int mine[101][101]) {
    printf("*********ɨ��ʧ��**********\n");
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0) printf("%d ", j);
            else if (j == 0) printf("%d ", i);
            else printf("%d ", mine[i][j]);
        }
        printf("\n");
    }
}

//��ӡ�˵�����
void menu(int x, int y, int nummine) {
    printf("-----------ɨ��------------\n");
    printf(" ���̴�С:%dx%d ������:%d \n", x, y, nummine);
    printf("---------------------------\n");
    printf("********1. ��ʼ��Ϸ********\n");
    printf("********2. ��Ϸ����********\n");
    printf("********0. �˳���Ϸ********\n");
    printf("***************************\n");
    printf("��ѡ��:>");
}

//�������̴�С
void setxy(int* x, int* y) {
    system("CLS");
    while (1) {
        printf("���������̵Ĵ�С(���зֱ����ã��Կո�ָ���ֵ��1��99֮��):>");
        scanf("%d %d", x, y);
        if (*x < 100 && *x>0 && *y < 100 && *y>0) break;
        else {
            system("CLS");
            printf("����������������;\n");
        }
    }
}

//���õ�����
void setnummine(int* nummine, int* x, int* y) {
    system("CLS");
    while (1) {
        printf("�����õ�����:>");
        scanf("%d", nummine);
        if (*nummine > *x * *y) {
            system("CLS");
            printf("������̫���ˣ����̷Ų�����,����������;\n");
        }
        else if (*nummine < 1) {
            system("CLS");
            printf("����û�е���Ŷ������������;\n");
        }
        else {
            break;
        }
    }
}

//��Ϸ����
void set(int* x, int* y, int* nummine) {
    setxy(x, y);
    setnummine(nummine, x, y);
    system("CLS");
}

//��ʼ��flag����
void Layflag(int x, int y, char flag[100][100]) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            flag[i][j] = 42;
        }
    }
}

//��ʼ�����׵�λ��
void Laymines(int x, int y, int nummine, int mine[101][101]) {
    for (int i = 0; i <= x + 1; i++) {//ʹ���ױ��ȫΪ0
        for (int j = 0; j <= y + 1; j++) {
            mine[i][j] = 0;
        }
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < nummine;) {
        int a = rand() % x + 1;
        int b = rand() % x + 1;
        printf("%d %d\n", a, b);
        if (mine[a][b]) continue;//���Ѿ�����ǹ�����ʱ�˳�
        else {
            mine[a][b] = 1;//δ����ǹ�δ����ʱ�����Ϊ����
            i++;//��������1;
        }
    }
}

//��ʼ����Ϸ����
void Lay(int x, int y, int nummine, char flag[100][100], int mine[101][101]) {
    Laymines(x, y, nummine, mine);//��ʼ��10�����׵�λ��
    Layflag(x, y, flag);//��ʼ��flag����
}

//��ʱ��ӡ��Ϸ����
void interfaceone(int x, int y, char flag[100][100]) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0) {
                printf("%d ", j);
                if (j < 10) printf(" ");
            }
            else if (j == 0) {
                printf("%d ", i);
                if (i < 10)printf(" ");
            }
            else printf("%c  ", flag[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//��Χը����
int numminearound(int a, int b, int mine[101][101]) {
    return mine[a - 1][b - 1] +
        mine[a - 1][b] +
        mine[a - 1][b + 1] +
        mine[a][b - 1] +
        mine[a][b + 1] +
        mine[a + 1][b - 1] +
        mine[a + 1][b] +
        mine[a + 1][b + 1] +
        48;
}

//����̽��
int detect(int x, int y, int* num, int bl, int mine[101][101], char flag[100][100],int timeDifference) {
    int a, b;
    if (bl == 2) printf("���λ���Ѿ�̽����ˣ�������һ��δ̽�����λ��(%ds):>", timeDifference);
    else if (bl == 3) printf("���λ�ò���������,����������(%ds):>", timeDifference);
    else printf("��������Ҫ̽���λ��(%ds):>", timeDifference);
    if (_kbhit()){
        scanf("%d %d", &a, &b);
        if (a <= x && b <= y && a > 0 && b > 0) {
            if (mine[a][b]) return 0;//����������˳�
            else if (flag[a][b] != 42) return 2;
            else {
                flag[a][b] = numminearound(a, b, mine);
                (*num)--;
                return 1;
            }
        }
        else return 3;
    }
    else return 4;
}

//��ʼ��Ϸ
void game(int x, int y, int nummine) {
    time_t timeStart = time(NULL);
    int num = x * y - nummine; //ͳ��������δ��̽��ĸ���������Ϊ0ʱ�˳��˳�����ʱ����δ̽��ĵط�������
    char flag[100][100]; //����Ѿ�̽�����λ�ã����Ѿ�̽�������ʾ��Χ��������������ʾ*
    int mine[101][101]; // ͳ�Ƶ���λ�ã�����ʱΪ1������ʱΪ0��
    int bl = 0;
    Lay(x, y, nummine, flag, mine); //��ʼ����Ϸ����
    system("CLS");
    do {
        //test(x,y,mine);
        time_t timeCurrent = time(NULL);
        int timeDifference = difftime(timeCurrent,timeStart);
        if(bl != 4) interfaceone(x, y, flag); //��ӡ��Ϸ����
        printf("(����%d�����׸��Ӵ�̽��)", num);
        bl = detect(x, y, &num, bl, mine, flag, timeDifference); //����ɨ����Ϊ
        Sleep(10);
        if (bl == 4) printf("\r"); 
        else system("CLS");//�����Ļ
        if (num == 0) break;
    } while (bl);
    if (bl) printf("*********ɨ�����**********\n");
    else print(x, y, mine);
}


int main() {
    int x = 9;//��������
    int y = 9;//��������
    int nummine = 10;//������
    int input;//����ѡ��
    do {
        menu(x, y, nummine); //��ӡ�˵�
        scanf("%d", &input); // ����ѡ���жϼ�����Ϸ���ǽ�����Ϸ
        switch (input) {
        case 1:
            system("CLS");
            game(x, y, nummine);
            break;
        case 2:
            set(&x, &y, &nummine);
            break;
        case 0:
            system("CLS");
            printf("��Ϸ�˳�");
            break;
        default:
            system("CLS");
            printf("����������������;");
            break;
        }
    } while (input);
    return 0;
}