#include "stdfx.h"
#include "NR_Stack.h"

// 실험 1 : 기본 스택사이즈가 미치는 영향을 알아본다. -> 메모리를 재할당하는 사이클이 상당히 길기때문에 지연이 일어나는것임을 확인
// 결과.. -> 전혀 상관이 없다. 사이즈가 커져도 천만단위 데이터를 퀵소팅 하는데 걸리는 시간차는 미미했다.
// 즉, 메모리를 재할당하는데 걸리는 시간은 현실적으로 거의 성능에 영향을 미치지 않는다.
const unsigned int BASIC_STACK_SIZE = 100;

void SetNode(Node* p_Node, int Left, int Right)
{
    p_Node->Left = Left;
    p_Node->Right = Right;
}

void CreateStack(Stack** p_Stack)
{
    (*p_Stack) = (Stack*)malloc(sizeof(Stack));

    (*p_Stack)->Nodes = (Node*)calloc(sizeof(Node), BASIC_STACK_SIZE);
    (*p_Stack)->Capacity = BASIC_STACK_SIZE;
    (*p_Stack)->Top = 0;
}

void DestroyStack(Stack** p_Stack)
{
    free((*p_Stack)->Nodes);
    free(*p_Stack);

    *p_Stack = NULL;
}

void Push(Stack* p_Stack, int Left, int Right)
{
    // 배열의 크기를 넘으면 자동으로 30% 확장시킴
    if (p_Stack->Top == p_Stack->Capacity)
    {
        p_Stack->Capacity += (int)((double)p_Stack->Capacity * 0.3);
        Node* Temp = p_Stack->Nodes;
        p_Stack->Nodes = (Node*)realloc(p_Stack->Nodes, sizeof(Node) * p_Stack->Capacity);

        if (p_Stack->Nodes == NULL)
        {
            perror("memmory realloc error");
            free(Temp);
            exit(1);
        }
    }

    // 성공하면 원소 Push
    SetNode(&p_Stack->Nodes[p_Stack->Top++], Left, Right);
}

Node* Pop(Stack* p_Stack)
{
    // 스택 사용도가 70퍼센트 이하이고, 용량이 BASIC_STACK_SIZE보다 클때는 용량을 30% 줄인다.
    if(BASIC_STACK_SIZE < p_Stack->Capacity && p_Stack->Top < (int)((double)p_Stack->Capacity * 0.7))
    {
        p_Stack->Capacity -= (int)((double)p_Stack->Capacity * 0.3);
        Node* Temp = p_Stack->Nodes;
        p_Stack->Nodes = (Node*)realloc(p_Stack->Nodes, sizeof(Node) * p_Stack->Capacity);

        if (p_Stack->Nodes == NULL)
        {
            perror("memmory realloc error");
            free(Temp);
            exit(1);
        }
    }

    return &p_Stack->Nodes[--p_Stack->Top];
}

Node* GetTop(Stack* p_Stack)
{
    return &p_Stack->Nodes[p_Stack->Top - 1];
}

int IsEmptyStack(Stack* p_Stack)
{
    return (p_Stack->Top == 0);
}

int GetSize(Stack* p_Stack)
{
    return p_Stack->Top;
}