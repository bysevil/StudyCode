#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

//测试用，打印mine数组
void test(int x, int y, int mine[101][101]) {
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            printf("%d ", mine[i][j]);
        }
        printf("\n");
    }
    printf("***********************\n");
}
//失败时，打印mine数组
void print(int x, int y, int mine[101][101]) {
    printf("*********扫雷失败**********\n");
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i == 0) printf("%d ", j);
            else if (j == 0) printf("%d ", i);
            else printf("%d ", mine[i][j]);
        }
        printf("\n");
    }
}

//打印菜单界面
void menu(int x, int y, int nummine) {
    printf("-----------扫雷------------\n");
    printf(" 棋盘大小:%dx%d 地雷数:%d \n", x, y, nummine);
    printf("---------------------------\n");
    printf("********1. 开始游戏********\n");
    printf("********2. 游戏设置********\n");
    printf("********0. 退出游戏********\n");
    printf("***************************\n");
    printf("请选择:>");
}

//设置棋盘大小
void setxy(int* x, int* y) {
    system("CLS");
    while (1) {
        printf("请设置棋盘的大小(行列分别设置，以空格分隔。值在1到99之间):>");
        scanf("%d %d", x, y);
        if (*x < 100 && *x>0 && *y < 100 && *y>0) break;
        else {
            system("CLS");
            printf("输入有误，重新输入;\n");
        }
    }
}

//设置地雷数
void setnummine(int* nummine, int* x, int* y) {
    system("CLS");
    while (1) {
        printf("请设置地雷数:>");
        scanf("%d", nummine);
        if (*nummine > *x * *y) {
            system("CLS");
            printf("地雷数太多了，棋盘放不下啦,请重新输入;\n");
        }
        else if (*nummine < 1) {
            system("CLS");
            printf("不能没有地雷哦，请重新输入;\n");
        }
        else {
            break;
        }
    }
}

//游戏设置
void set(int* x, int* y, int* nummine) {
    setxy(x, y);
    setnummine(nummine, x, y);
    system("CLS");
}

//初始化flag数组
void Layflag(int x, int y, char flag[100][100]) {
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            flag[i][j] = 42;
        }
    }
}

//初始化地雷的位置
void Laymines(int x, int y, int nummine, int mine[101][101]) {
    for (int i = 0; i <= x + 1; i++) {//使地雷标记全为0
        for (int j = 0; j <= y + 1; j++) {
            mine[i][j] = 0;
        }
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < nummine;) {
        int a = rand() % x + 1;
        int b = rand() % x + 1;
        printf("%d %d\n", a, b);
        if (mine[a][b]) continue;//当已经被标记过地雷时退出
        else {
            mine[a][b] = 1;//未被标记过未地雷时，标记为地雷
            i++;//地雷数加1;
        }
    }
}

//初始化游戏数据
void Lay(int x, int y, int nummine, char flag[100][100], int mine[101][101]) {
    Laymines(x, y, nummine, mine);//初始化10个地雷的位置
    Layflag(x, y, flag);//初始化flag数组
}

//即时打印游戏界面
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

//周围炸弹数
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

//进行探测
int detect(int x, int y, int* num, int bl, int mine[101][101], char flag[100][100],int timeDifference) {
    int a, b;
    if (bl == 2) printf("这个位置已经探测过了，请输入一个未探测过的位置(%ds):>", timeDifference);
    else if (bl == 3) printf("这个位置不在棋盘上,请重新输入(%ds):>", timeDifference);
    else printf("请输入你要探测的位置(%ds):>", timeDifference);
    if (_kbhit()){
        scanf("%d %d", &a, &b);
        if (a <= x && b <= y && a > 0 && b > 0) {
            if (mine[a][b]) return 0;//如果有雷则退出
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

//开始游戏
void game(int x, int y, int nummine) {
    time_t timeStart = time(NULL);
    int num = x * y - nummine; //统计无雷且未被探测的格子数，当为0时退出退出，此时所有未探测的地方都有雷
    char flag[100][100]; //标记已经探测过的位置，当已经探测过，显示周围地雷数，否则显示*
    int mine[101][101]; // 统计地雷位置，有雷时为1，无雷时为0；
    int bl = 0;
    Lay(x, y, nummine, flag, mine); //初始化游戏数据
    system("CLS");
    do {
        //test(x,y,mine);
        time_t timeCurrent = time(NULL);
        int timeDifference = difftime(timeCurrent,timeStart);
        if(bl != 4) interfaceone(x, y, flag); //打印游戏界面
        printf("(还有%d个无雷格子待探测)", num);
        bl = detect(x, y, &num, bl, mine, flag, timeDifference); //进行扫雷行为
        Sleep(10);
        if (bl == 4) printf("\r"); 
        else system("CLS");//清空屏幕
        if (num == 0) break;
    } while (bl);
    if (bl) printf("*********扫雷完成**********\n");
    else print(x, y, mine);
}


int main() {
    int x = 9;//棋盘列数
    int y = 9;//棋盘行数
    int nummine = 10;//地雷数
    int input;//输入选择
    do {
        menu(x, y, nummine); //打印菜单
        scanf("%d", &input); // 输入选择判断继续游戏还是结束游戏
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
            printf("游戏退出");
            break;
        default:
            system("CLS");
            printf("输入有误，重新输入;");
            break;
        }
    } while (input);
    return 0;
}