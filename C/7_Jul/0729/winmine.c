#include<stdio.h>
#include<stdlib.h>

static int arr[9][9]; //标记每个位置周围的地雷数，探测时显示
static int flag[9][9]; //标记已经探测过的位置，当已经探测过，显示周围地雷数，否则显示*
static int mine[9][9]; // 统计地雷位置，有雷时为1，无雷时为0；
static int num = 0; //统计探测次数，到达71次时退出，此时所有未探测的地方都有雷

//测试用，打印三个数组
void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("***************************\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ",flag[i][j]);
        }
        printf("\n");
    }
    printf("***************************\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ",mine[i][j]);
        }
        printf("\n");
    }
    printf("***************************\n");
}

//打印菜单
void menu() {
    printf("***********扫雷************\n");
    printf("********1. 开始游戏********\n");
    printf("********0. 退出游戏********\n");
    printf("***************************\n");
}

//初始化arr数组
void Layarr() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (mine[i - 1][j - 1] && i >= 0 && j >= 0) arr[i][j]++;
            if (mine[i - 1][j] && i >= 0) arr[i][j]++;
            if (mine[i - 1][j + 1] && i >= 0 && j < 9) arr[i][j]++;
            if (mine[i][j - 1] && j >= 0) arr[i][j]++;
            if (mine[i][j + 1] && j < 9) arr[i][j]++;
            if (mine[i + 1][j - 1] && i < 9 && j >= 0) arr[i][j]++;
            if (mine[i + 1][j] && i < 9 ) arr[i][j]++;
            if (mine[i + 1][j + 1] && i < 9 && j <9) arr[i][j]++;
        }
    }
}

//初始化flag数组
void Layflag() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            flag[i][j] = 0;
        }
    }
}

//初始化10个地雷的位置
void Laymines() {
    int x, y;
    for (int i = 0; i < 9; i++){//使地雷标记全为0
        for (int j = 0; j < 9; j++) {
            mine[i][j] = 0;
        }
    }
    for (int i = 0; i < 11;) {
        srand((unsigned)time(NULL));
        x = rand() % 9;
        y = rand() % 9;
        if (mine[x][y]) continue;//当已经被标记过地雷时退出
        else {
            mine[x][y] = 1;//未被标记过未地雷时，标记为地雷
            i++;//地雷数加1，当为11时退出.
        }
    }
}

//初始化游戏数据
void Lay() {
    num = 0;
    int a;
    Laymines();//初始化10个地雷的位置
    Layarr();//初始化arr数组
    Layflag();//初始化flag数组
}

//进行探测
int detect() {
    int x, y;
    printf("请输入你要探测的位置>");
    scanf("%d %d", &x, &y);
    if (mine[x - 1][y - 1]) return 0;//如果有雷则退出
    else {
        flag[x - 1][y - 1] = 1;//无雷则标记已经探测
        num++;//探测计数
    }
    return 1;
}

//即时打印游戏界面
void interface() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (0 == i) printf("%d ", j); //第一行为列位置标记
            else if (0 == j) printf("%d ", i); //第一列为行位置标记
            else if (flag[i-1][j-1]) printf("%d ", arr[i-1][j-1]); //如果被探测过则显示周围有几颗雷
            else printf("* "); // 没探测过则显示*
        }
        printf("\n");
    }
    return 0;
}

void game() {
    int x;
    Lay(); //初始化游戏数据
    system("CLS");
    do{
        print();
        interface(); //打印界面
        x = detect(); //进行扫雷行为
        system("CLS");//清空屏幕
        if (71 == num) break;
    } while (x);
    if (x) printf("*********扫雷完成**********\n");
    else printf("*********扫雷失败*********\n");
}

int main() {
    int select;
    do{
        menu(); //打印菜单
        scanf("%d", &select); // 输入选择判断继续游戏还是结束游戏
        switch (select){
        case 1:
            system("CLS");
            printf("加载中，请等待游戏开始\n");
            game();
            break;
        case 0:
            system("CLS");
            printf("游戏退出");
            break;
        default:
            printf("输入有误，重新输入");
            break;
        }
    }while(select);
    return 0;
}