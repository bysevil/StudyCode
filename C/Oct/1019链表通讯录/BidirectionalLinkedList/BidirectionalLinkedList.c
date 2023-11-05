#include"BidirectionalLinkedList.h"


LTNode* LTInit() {
	LTNode* head = malloc(sizeof(LTNode));
	if (head) {
		head->val = -1;
		head->prev = head;
		head->next = head;
	}
	else {
		printf("链表创建失败\n");
	}
	return head;
}

void LTDestroy(LTNode* phead) {
	if (phead) {
		LTNode* cur = phead->next->next;
		LTNode* prev = phead->next;
		while (prev != phead) {
			LTErase(prev);
			prev = cur;
			cur = cur->next;
		}
		free(phead);
		printf("链表清空成功\n");
	}
	else {
		printf("链表已经为空\n");
	}
}
void LTPrint(LTNode* phead) {
	if (phead) {
		LTNode* cur = phead->next;
		while (cur != phead) {
			printf(" %d ->", cur->val);
			cur = cur->next;
		}
		printf(" NULL\n");
	}
	else {
		printf("链表不存在，无法打印\n");
	}
}
bool LTEmpty(LTNode* phead) {
}

void LTPushBack(LTNode* phead, LTDataType x) {
	if (phead) {
		LTInsert(phead->prev, x);
	}
	else {
		printf("链表不存在，无法尾插\n");
	}
}
void LTPopBack(LTNode* phead) {
	if (phead) {
		if (phead->prev != phead){
			LTErase(phead->prev);
		}
		else {
			printf("链表无有效节点，无法尾删\n");
		}
	}
	else {
		printf("链表不存在，无法尾删\n");
	}
}

void LTPushFront(LTNode* phead, LTDataType x) {
	if (phead) {
		LTInsert(phead, x);
	}
	else {
		printf("链表不存在，无法头插\n");
	}
}
void LTPopFront(LTNode* phead) {
	if (phead) {
		if (phead->next != phead) {
			LTErase(phead->next);
		}
		else {
			printf("链表无有效节点，无法头删\n");
		}
	}
	else {
		printf("链表不存在，无法头删\n");
	}
}
//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x) {
	if (pos) {
		LTNode* ins = malloc(sizeof(LTNode));
		if (ins) {
			ins->val = x;
			ins->next = pos->next;
			ins->prev = pos;
			pos->next->prev = ins;
			pos->next = ins;
		}
		else {
			printf("空间开辟失败，无法插入\n");
		}
	}
	else {
		printf("位置指针不合法，插入失败\n");
	}
}
void LTErase(LTNode* pos) {
	if (pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		free(pos);
	}
	else {
		printf("参数不合法，删除失败\n");
	}
}

LTNode* LTFind(LTNode* phead, LTDataType x) {
	if (phead) {
		LTNode* find = phead->next;
		while (find != phead) {
			if (find->val == x) {
				return find;
			}
			find = find->next;
		}
		return NULL;
	}
	else {
		printf("链表不存在，查找失败\n");
	}
}