typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
}Node;

typedef struct tagCircularQueue
{
    int Capacity;
    int Rear;
    int Front;
    Node* Nodes;
}CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);

void CQ_EnQueue(CircularQueue* Queue, ElementType p_Data);
ElementType CQ_DeQueue(CircularQueue* Queue);

int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
int CQ_GetSize(CircularQueue* Queue);