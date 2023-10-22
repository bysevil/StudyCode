#include"LinkList.h"
#include"contact.h"

int main() {
	contact* con = NULL;
	InitContact(&con);
	printf("**************************\n");
	AddContact(&con);
	ShowContact(con);
	AddContact(&con);
	ShowContact(con);
	AddContact(&con);
	ShowContact(con);
	printf("**************************\n");
	DelContact(&con);
	ShowContact(con);
	printf("**************************\n");
	FindContact(con);
	ShowContact(con);
	printf("**************************\n");
	ModifyContact(&con);
	ShowContact(con);
	printf("**************************\n");
	DestroyContact(&con);
	ShowContact(con);
	printf("**************************\n");
	return 0;
}