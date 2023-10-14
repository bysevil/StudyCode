#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include"SequenceTable.h"
//初始化通讯录
void InitContact(contact* con) {
	SLInit(con);
}

//添加通讯录数据
void AddContact(contact* con) {
	assert(con);
	PeoInfo tmp;
	printf("请输入要添加的信息：\n%s %s %s %s %s\n", "姓名", "性别", "电话", "年龄", "住址");
	scanf("%s %s %s %d %s", tmp.name, tmp.sex, tmp.tel, &tmp.age, tmp.addr);
	SLPushBack(con, tmp);
}

//删除通讯录数据
void DelContact(contact* con) {
	assert(con);
	printf("请输入要删除的联系人的姓名:\n");
	char delname[NAME_MAX];
	scanf("%s", delname);
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->a[i].name,delname) == 0) {
			SLErase(con, i);
			return;
		}
	}
	printf("未查询到指定联系人\n");
}

//展示通讯录数据
void ShowContact(contact* con) {
	assert(con);
	printf("打印通讯录：\n%s %s %s %s %s\n", "姓名", "性别", "电话", "年龄", "住址");
	for (int i = 0; i < con->size; i++)
		printf("%s %s %s %d %s\n", con->a[i].name, con->a[i].sex, con->a[i].tel, con->a[i].age, con->a[i].addr);
}

//查找通讯录数据
void FindContact(contact* con) {
	assert(con);
	printf("请输入要查询的联系人的姓名:\n");
	char Findname[NAME_MAX];
	scanf("%s", Findname);
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->a[i].name, Findname) == 0) {
			printf("你查询的联系人信息：\n"
				"%s %s %s %s %s\n" 
				"%s %s %s %d %s\n", 
				"姓名", "性别", "电话", "年龄", "住址",
				con->a[i].name, con->a[i].sex, con->a[i].tel, con->a[i].age, con->a[i].addr);
			return;
		}
	}
	printf("未查询到指定联系人\n");
}

//修改通讯录数据
void ModifyContact(contact* con) {
	assert(con);
	printf("请输入要修改的联系人的姓名:\n");
	char Modifyname[NAME_MAX];
	scanf("%s", Modifyname);
	for (int i = 0; i < con->size; i++) {
		if (strcmp(con->a[i].name, Modifyname) == 0) {
			printf("请重新输入此联系人的信息：%s %s %s %s %s\n",
				"姓名", "性别", "电话", "年龄", "住址");
			scanf("%s %s %s %d %s", con->a[i].name, con->a[i].sex, con->a[i].tel, &con->a[i].age, con->a[i].addr);
			return;
		}
	}
	printf("未查询到指定联系人\n");
}

//销毁通讯录数据
void DestroyContact(contact* con) {
	SLDestroy(con);
}