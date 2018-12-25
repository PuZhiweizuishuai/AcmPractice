#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/**
 * 栈结构体声明
*/
typedef struct Stack
{
    int number[MAX];
    int top;
} SeqStack;

/**
 * 初始化栈
 * 返回初始化成功的栈
*/
SeqStack *Init(SeqStack *stack);

/**
 * 入栈
*/
void Push(SeqStack *stack, int x);

/**
 * 出栈
*/
int Pop(SeqStack *stack);

/**
 * 判空 
*/
int IsEmpty(SeqStack *stack);

int main(void)
{
    SeqStack *stack = Init(stack);
    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);
    printf("%d\n", Pop(stack));
    printf("%d\n", Pop(stack));
    printf("%d\n", IsEmpty(stack));
    printf("OK\n");
    return 0;
}

SeqStack *Init(SeqStack *stack)
{
    stack = (SeqStack *)malloc(sizeof(SeqStack));
    stack->top = -1;
    return stack;
}

void Push(SeqStack *stack, int x)
{
    if (stack->top > MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    stack->top++;
    stack->number[stack->top] = x;
    return;
}

int Pop(SeqStack *stack)
{
    int x;
    if (stack->top < 0)
    {
        printf("Underflow\n");
        exit(1);
    }
    x = stack->number[stack->top];
    stack->top--;
    return x;
}

int IsEmpty(SeqStack *stack)
{
    if (stack->top < 0)
        return 1;
    return 0;
}