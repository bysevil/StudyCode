#include"LinkList.h"

void SLTPrint(SLTNode* phead) {
    
    while (phead) {
        printf("%d -> ", phead->val);
        phead = phead->next;
    }
    printf("NULL\n");
}

SLTNode* SLTPush(SLTDataType x,SLTNode* next) {
    SLTNode* tmp = (SLTNode*)malloc(sizeof(SLTNode));
    assert(tmp);
    tmp->val = x;
    tmp->next = next;
    return tmp;
}

//头部插入删除/尾部插入删除
void SLTPushBack(SLTNode** pphead, SLTDataType x) {
    assert(pphead);
    SLTNode* tmp = *pphead;
    if (tmp) {
        while (tmp->next) tmp = tmp -> next;
        tmp->next = SLTPush(x,NULL);
    }
    else {
        *pphead = SLTPush(x,NULL);
    }
}

void SLTPushFront(SLTNode** pphead, SLTDataType x) {
    assert(pphead);
    if (*pphead) {
        *pphead = SLTPush(x, *pphead);
    }
    else {
        *pphead = SLTPush(x,NULL);
    }
}

SLTNode* SLTDel(SLTNode* pNode){
    assert(pNode);
    SLTNode* tmp = pNode->next;
    free(pNode);
    return tmp;
}

void SLTPopBack(SLTNode** pphead) {
    if (*pphead == NULL) {
        printf("链表已空\n");
        return;

    }
    if ((*pphead)->next == NULL) {
        *pphead = SLTDel(*pphead);
        return;
    }
    SLTNode* new = *pphead;
    SLTNode* old = *pphead;
    while (new->next) {
        old = new;
        new = new->next;
    }
    old->next = SLTDel(new);
}

void SLTPopFront(SLTNode** pphead) {
    if (*pphead == NULL) {
        printf("链表已空\n");
        return;
    }
    *pphead = SLTDel(*pphead);
}

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x) {
    for(int i = 0; phead; i++) {
        if (phead->val == x) {
            printf("%d是链表的第%d个节点\n",x,i);
            return;
        }
        phead = phead->next;
    }
    printf("%d在链表中未找到\n", x);
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x) {
    if (*pphead == pos) {
        SLTPushFront(pphead, x);
    }
    else {
        SLTNode* tmp = *pphead;
        while (tmp) {
            if (tmp->next == pos) {
                tmp->next = SLTPush(x, pos);
                return;
            }
            tmp = tmp->next;
        }
        printf("插入失败，pos未找到");
    }
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos) {
    if (*pphead == pos) {
        SLTPopFront(pphead);
    }
    else {
        SLTNode* tmp = *pphead;
        while (tmp) {
            if (tmp->next == pos) {
                tmp->next = SLTDel(pos);
                return;
            }
            tmp = tmp->next;
            
        }
        printf("删除失败，未找到pos\n");
    }
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x) {
    pos->next = SLTPush(x, pos->next);
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
    while (pos->next) {
        pos->next = SLTDel(pos->next);
    }
}

//销毁链表
void SListDesTroy(SLTNode** pphead) {
    while (*pphead) {
        *pphead = SLTDel(*pphead);
    }
}