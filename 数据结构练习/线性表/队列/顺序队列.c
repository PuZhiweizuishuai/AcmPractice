#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node
{
    // 队列占用的数组空间
    int data[MAXSIZE]; 
    // 队头指针指向队头元素在数组中的前一个位置
    int front;         
    // 队尾指针指向队尾元素在数组中的位置
    int rear;          
} SeqQueue;

/**
 * 置空队列
*/
void InitQueue(SeqQueue *Q);

/**
 * 判队空
*/
int EmptyQueue(SeqQueue *Q);

/**
 * 进队
*/
int InQuene(SeqQueue *Q, int x);

/**
 * 出队
*/
int OutQuene(SeqQueue *Q);

/**
 * 读取队头元素
*/
int GetHead(SeqQueue *Q);        

int main(void)
{
    SeqQueue *Q = (SeqQueue *)malloc(sizeof(SeqQueue));
    InitQueue(Q);

    InQuene(Q, 10);
    InQuene(Q, 20);
    InQuene(Q, 30);
    OutQuene(Q);
    //OutQuene(Q);

    printf("%d", GetHead(Q));
    return 0;
}

void InitQueue(SeqQueue *Q)
{
    Q->front = -1;
    Q->rear = -1;
}

int EmptyQueue(SeqQueue *Q)
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

int InQuene(SeqQueue *Q, int x)
{
    if (Q->rear >= MAXSIZE - 1)
    {
        printf("Overflow!\n");
        return 0;
    }
    Q->rear++;
    Q->data[Q->rear] = x;
    return 1;
}

int OutQuene(SeqQueue *Q)
{
    if (EmptyQueue(Q) == 1)
    {
        printf("Underflow!\n");
        return 0;
    }
     // 移动队头指针，没有队头元素
    Q->front++;              
    // 返回原来的队头元素
    return Q->data[Q->front]; 
}

int GetHead(SeqQueue *Q)
{
    if (EmptyQueue(Q) == 1)
    {
        printf("Underflow!\n");
        return 0;
    }
    return Q->data[Q->front + 1];
}