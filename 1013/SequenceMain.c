#include"SequenceTable.h"

int main() {
    SL ps;

    SLInit(&ps);
    SLPushBack(&ps,1);
    SLPushBack(&ps,2);
    SLPushBack(&ps,3);
    SLPushBack(&ps,4);
    SLPrint(&ps);

    SLPopBack(&ps);
    SLPopBack(&ps);
    SLPrint(&ps);

    SLPushFront(&ps, 5);
    SLPushFront(&ps, 6);
    SLPushFront(&ps, 7);
    SLPushFront(&ps, 8);
    SLPrint(&ps);

    SLPopFront(&ps);
    SLPopFront(&ps);
    SLPrint(&ps);

    SLInsert(&ps, 2, 9);
    SLInsert(&ps, 3, 0);
    SLPrint(&ps);

    SLErase(&ps, 2);
    SLErase(&ps, 2);
    SLPrint(&ps);

    printf("lookup 5 : %d\n", SLFind(&ps, 5));

    SLDestroy(&ps);
    SLPrint(&ps);
    return 0;
}