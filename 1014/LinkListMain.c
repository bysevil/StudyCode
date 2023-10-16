#include"LinkList.h"

int main() {
    SLTNode* phead = NULL;
    printf("*******************************\n尾插两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTPushBack(&phead, 1);
    SLTPrint(phead);
    SLTPushBack(&phead, 2);
    SLTPrint(phead);

    printf("*******************************\n查找两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTFind(phead, 1);
    SLTFind(phead, 10);

    printf("*******************************\n尾删三次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTPopBack(&phead);
    SLTPrint(phead);
    SLTPopBack(&phead);
    SLTPrint(phead);
    SLTPopBack(&phead);
    SLTPrint(phead);

    printf("*******************************\n头插两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTPushFront(&phead, 3);
    SLTPrint(phead);
    SLTPushFront(&phead, 4);
    SLTPrint(phead);

    printf("*******************************\n头删三次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTPopFront(&phead);
    SLTPrint(phead);
    SLTPopFront(&phead);
    SLTPrint(phead);
    SLTPopFront(&phead);
    SLTPrint(phead);

    printf("*******************************\n指定位置前插入两次\n");

    SLTPushBack(&phead, 1);
    printf("初始:");
    SLTPrint(phead);

    SLTInsert(&phead, phead, 11);
    SLTPrint(phead);
    SLTInsert(&phead, phead->next, 12);
    SLTPrint(phead);

    printf("*******************************\n删除指定节点两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTErase(&phead, phead);
    SLTPrint(phead);
    SLTErase(&phead, phead->next);
    SLTPrint(phead);

    printf("*******************************\n指定位置后插入两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTInsertAfter(phead, 13);
    SLTPrint(phead);
    SLTInsertAfter(phead, 14);
    SLTPrint(phead);

    printf("*******************************\n删除指定位置后所有节点两次\n");

    printf("初始:");
    SLTPrint(phead);

    SLTEraseAfter(phead->next);
    SLTPrint(phead);
    SLTEraseAfter(phead);
    SLTPrint(phead);

    printf("*******************************\n销毁链表两次\n");

    for (int i = 0; i < 10; i++) {
        SLTPushBack(&phead, i);
    }
    printf("初始:");
    SLTPrint(phead);

    SListDesTroy(&phead);
    SLTPrint(phead);
    SListDesTroy(&phead);
    SLTPrint(phead);

    printf("*******************************\n");

    return 0;
}