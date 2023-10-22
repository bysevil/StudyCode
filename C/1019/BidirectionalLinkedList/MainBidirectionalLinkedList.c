#include"BidirectionalLinkedList.h"

int main() {
	LTNode* phead = LTInit();

	void LTPrint(LTNode * phead);

	printf("链表尾插1\n");
	LTPushBack(phead, 1);
	LTPrint(phead);

	printf("链表尾插2\n");
	LTPushBack(phead, 2);
	LTPrint(phead);

	printf("链表尾插3\n");
	LTPushBack(phead, 3);
	LTPrint(phead);

	printf("链表尾插4\n");
	LTPushBack(phead, 4);
	LTPrint(phead);

	printf("链表尾删\n");
	LTPopBack(phead);
	LTPrint(phead);

	printf("链表头插5\n");
	LTPushFront(phead, 5);
	LTPrint(phead);

	printf("链表头删\n");
	LTPopFront(phead);
	LTPrint(phead);

	printf("在链表中查找3\n");
	printf("%p\n",LTFind(phead, 3));
	LTPrint(phead);

	printf("在链表中查找11\n");
	printf("%p\n",LTFind(phead, 11));
	LTPrint(phead);

	printf("开始销毁链表\n");
	LTDestroy(phead);
	LTPrint(phead);

	return 0;
}