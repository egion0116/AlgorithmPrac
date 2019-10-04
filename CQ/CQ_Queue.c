#include "stdfx.h"
#include "CQ_Queue.h"

void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

    (*Queue)->Capacity = Capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CircularQueue* Queue)
{
    free(Queue->Nodes);
    free(Queue);
}

/*
    큐를 추가시
        1. Rear가 배열 끝점에 도달했는지 -> Queue->Rear = Position + 1
         -> 그게 아니면 그냥 Position = Queue->Rear++;

        2. 큐가 꽉 찼을경우를 대비한다??... 
*/
void CQ_EnQueue(CircularQueue* Queue, ElementType p_Data)
{
    int Position = 0;

    if (Queue->Rear == (Queue->Capacity + 1))
        Queue->Rear = Position + 1;
    else
        Position = Queue->Rear++;
    
    Queue->Nodes[Position].Data = p_Data;
}

/*  
    전단 관리가 중요하다.
    1. 전단이 배열의 끝에 가 있을경우
        Queue->Front == Capacity;
            Queue->Front = 0;
            Position = Queue->Front++;

    2. 일반적인 경우
        Position = Queue->Front++;

    3. 큐가 비었을 경우는??...
*/
ElementType CQ_DeQueue(CircularQueue* Queue)
{
    int Position = Queue->Front;

    // 전단 위치 관리
    if (Queue->Front == Queue->Capacity)
        Queue->Front = 0;
    else
        Queue->Front++;
    
    return Queue->Nodes[Position].Data;
}

/*
    큐가 비었을 경우 -> 전단과 후단이 일치하는 경우 뿐이다.
*/
int CQ_IsEmpty(CircularQueue* Queue)
{
    return (Queue->Front == Queue->Rear);
}

/*
    큐가 꽉 찼을경우

    1. 전단이 후단 앞에 있을 경우
        Queue->Front < Queue->Reat
            return ((Queue->Rear - Queue->Front) == Queue->Capacity)
    2. 전단이 후단 뒤에 있을 경우
        return ((Queue->Rear + 1) == Queue->Front);
*/
int CQ_IsFull(CircularQueue* Queue)
{
    if (Queue->Front < Queue->Rear)
        return ((Queue->Rear - Queue->Front) == Queue->Capacity);
    else
        return ((Queue->Rear + 1) == Queue->Front);
}

/*
    큐 사이즈
    1. 전단이 후단보다 앞 -> 같을 경우까지 포함
        Queue->Front <= Queue->Rear
            return Queue->Rear - Queue->Front;
    
    2. 전단이 후단보다 뒤
        return (Queue-Capacity - (Queue->Front - Queue->Rear - 1));
*/
int CQ_GetSize(CircularQueue* Queue)
{
    if(Queue->Front <= Queue->Rear)
        return Queue->Rear - Queue->Front;
    else
        return (Queue->Capacity - (Queue->Front - Queue->Rear - 1));
}