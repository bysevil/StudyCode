#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game()
{
	int r = rand() % 100 + 1;
	int guess = 0;
	int count = 5;
	while (count)
	{
		printf("\n你还有%d次机会\n", count);
		printf("请猜数字>:");
		scanf("%d", &guess);
		if (guess < r)
		{
			printf("猜小了\n");
		}
		else if (guess > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("你失败了，正确值是:%d\n", r);
	}
}
void menu()
{
	printf("***********************\n");
	printf("****** 1. play ******\n");
	printf("****** 0. exit ******\n");
	printf("***********************\n");
}
int guessnumber()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}