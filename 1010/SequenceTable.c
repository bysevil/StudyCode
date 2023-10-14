#include"SequenceTable.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void SLInit(SL* ps) {
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

void SLDestroy(SL* ps) {
    assert(ps);
    if (ps->a) {
        free(ps->a);
        ps->a = NULL;
        ps->size = 0;
        ps->capacity = 0;
    }
}

void SLPrint(SL* ps) {
    assert(ps);
    printf("开始打印：\t");
    for (int i = 0; i < ps->size; i++)
        printf("%d ", ps->a[i]);
    printf("\n");
}

void SLCheckCapacity(SL* ps) {
    int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
    SLDataType* tmp = (SLDataType*)realloc(ps->a, NewCapacity * sizeof(SLDataType));
    if (tmp == NULL) {
        perror("realloc fail!\n");
        return;
    }
    ps->capacity = NewCapacity;
    ps->a = tmp;
}

//头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x) {
    assert(ps);
    if (ps->size == ps->capacity) SLCheckCapacity(ps);
    ps->a[ps->size++] = x;
}

void SLPopBack(SL* ps) {
    assert(ps);
    if(ps->size) ps->size--;
}
void SLPushFront(SL* ps, SLDataType x) {
    assert(ps);
    if (ps->size == ps->capacity) SLCheckCapacity(ps);
    for (int i = ps->size; i > 0; i--) {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[0] = x;
    ps->size++;
}
void SLPopFront(SL* ps) {
    assert(ps);
    if (ps->size) {
        for (int i = 1; i < ps->size; i++) {
            ps->a[i-1] = ps->a[i];
        }
        ps->size--;
    }
}

//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x) {
    assert(ps);
    if (ps->size == ps->capacity) SLCheckCapacity(ps);
    for (int i = ps->size; i > pos; i--) {
        ps->a[i] = ps->a[i - 1];
    }
    ps->a[pos] = x;
    ps->size++;
}
void SLErase(SL* ps, int pos) {
    assert(ps);
    if (ps->size) {
        for (int i = pos+1; i < ps->size; i++) {
            ps->a[i-1] = ps->a[i];
        }
        ps->size--;
    }
}

int SLFind(SL* ps, SLDataType x) {
    assert(ps);
    for (int i = 0; i < ps->size; i++) {
        if (ps->a[i] == x) return i;
    }
    return -1;
}