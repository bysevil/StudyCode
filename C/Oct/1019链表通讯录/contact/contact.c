#define _CRT_SECURE_NO_WARNINGS  
#include"LinkList.h"
#include"contact.h"

contact* FindByContact(contact* con, char* name) {
	contact* cur = con;
	if (cur) {
		while (cur) {
			if (strcmp(cur->val.name, name) == 0) {
				return cur;
			}
			cur = cur->next;
		}
		printf("用户不存在\n");
		return NULL;
	}
	else {
		printf("通讯录为空\n");
	}
}

//初始化通讯录
void InitContact(contact** con) {
	FILE* fprb = fopen("data.txt", "rb");
	if (fprb == NULL) {
		printf("无历史数据\n");
	}
	else {
		PeoInfo info;
		while (fread(&info, sizeof(info), 1, fprb)) {
			SLTPushBack(con,info);
		}
		printf("历史数据导入成功\n");
	}
}
//添加通讯录数据
void AddContact(contact** con) {
	PeoInfo info;
	printf("请输入：\n姓名 性别 年龄 电话 住址\n");
	scanf("%s %s %d %s %s", &info.name, &info.sex, &info.age, &info.tel, &info.addr);
	SLTPushBack(con, info);
	printf("添加完成\n");
}
//删除通讯录数据
void DelContact(contact** con) {
	if (*con) {
		char name[NAME_MAX];
		printf("请输入你要删除的用户姓名：");
		scanf("%s", name);
		contact* del = FindByContact(*con, name);
		SLTErase(con, del);
		printf("删除成功\n");
	}
	else {
		printf("通讯录为空\n");
	}
}
//展示通讯录数据
void ShowContact(contact* con) {
	if(con){
		contact* cur = con;
		while (cur) {
			printf("%s %s %d %s %s\n", cur->val.name, cur->val.sex, cur->val.age, cur->val.tel, cur->val.addr);
			cur = cur->next;
		}
	}
	else {
		printf("通讯录为空\n");
	}
}
//查找通讯录数据
void FindContact(contact* con) {
	char name[NAME_MAX];
	printf("请输入你要查找的用户姓名：");
	scanf("%s", name);
	contact* find = FindByContact(con, name);
	printf("%s %s %d %s %s\n", 
		find->val.name, 
		find->val.sex, 
		find->val.age, 
		find->val.tel, 
		find->val.addr
	);
	printf("查找完成\n");
}
//修改通讯录数据
void ModifyContact(contact** con) {
	char name[NAME_MAX];
	printf("请输入你要修改的用户姓名：");
	scanf("%s", name);
	contact* pos = FindByContact(*con, name);
	printf("请输入修改后的数据:");
	scanf("%s %s %d %s %s", 
		pos->val.name,
		pos->val.sex,
		&pos->val.age,
		pos->val.tel,
		pos->val.addr
	);
	printf("修改完成\n");
}
//销毁通讯录数据
void DestroyContact(contact** con) {
	if (*con) {
		FILE* fpwb = fopen("data.txt", "wb");
		contact* wcon = *con;
		while (wcon) {
			fwrite(&(wcon->val), sizeof(wcon->val), 1, fpwb);
			wcon = wcon->next;
		}
		SListDesTroy(con);
	}
	else {
		printf("通讯录为空\n");
	}
}