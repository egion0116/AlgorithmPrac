#include "stdfx.h"
#include "CQ_Queue.h"

int main(void)
{
    int i = 100;
    CircularQueue* Queue;

    CQ_CreateQueue(&Queue, 10);

    CQ_EnQueue(Queue, 1);
    CQ_EnQueue(Queue, 2);
    CQ_EnQueue(Queue, 3);
    CQ_EnQueue(Queue, 4);

    printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_DeQueue(Queue), Queue->Front, Queue->Rear);
    printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_DeQueue(Queue), Queue->Front, Queue->Rear);
    printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_DeQueue(Queue), Queue->Front, Queue->Rear);

    while(!CQ_IsFull(Queue))
    {
        CQ_EnQueue(Queue, i++);
    }

    printf("Capacity : %d, Size : %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

    while (!CQ_IsEmpty(Queue))
    {
        printf("Dequeue : %d, Front : %d, Rear : %d\n", CQ_DeQueue(Queue), Queue->Front, Queue->Rear);
    }

    CQ_DestroyQueue(Queue);

    return 0;
}