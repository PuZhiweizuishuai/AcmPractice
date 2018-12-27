#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct node
{
    // 队列占用的数组空间
	int data[MAXSIZE];
     // 队头指针指向队头元素在数组中的前一个位置             
	int front;
    // 队尾指针指向队尾元素在数组中的位置                    
	int rear;                      
}SeqQueue;

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

/**
 * 获取队列大小
*/
int GetSize(SeqQueue *Q);

int main(void)
{
	SeqQueue *Q = (SeqQueue *)malloc(sizeof(SeqQueue));
	InitQueue(Q);
	
	InQuene(Q, 10);
	InQuene(Q, 20);
	InQuene(Q, 30);
	printf("%d\n", GetSize(Q));
	OutQuene(Q);
	//OutQuene(Q);

	printf("%d",GetHead(Q));
	return 0;
}

void InitQueue(SeqQueue *Q)
{
	Q->front = -1;
	Q->rear = -1;
}

int EmptyQueue(SeqQueue *Q)
{
    // 队列判空的条件
	if (Q->front == Q->rear)              
		return 1;
	else
		return 0;
}

int InQuene(SeqQueue *Q, int x)
{
    // 队列判满的条件 
	if ((Q->rear + 1) % MAXSIZE == Q->front)         
	{
		printf("Overflow!\n");
		return 0;
	}
	Q->rear = (Q->rear + 1) % MAXSIZE;
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
	Q->front = (Q->front + 1) % MAXSIZE;          
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
	return Q->data[(Q->front + 1) % MAXSIZE];
}


int GetSize(SeqQueue *Q)
{
	// 队列大小公式
	return (MAXSIZE + Q->rear - Q->front) % MAXSIZE;
}
