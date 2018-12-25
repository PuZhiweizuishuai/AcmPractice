#include <stdio.h>
#include <stdlib.h>
/**
 * 栈结构体声明
*/
// typedef int DataType;

typedef struct Stack
{
    int number;
    struct Stack *next;
} SeqStack;

/**
 * 初始化栈
*/
SeqStack *Init();

/**
 * 入栈
*/
SeqStack *Push(SeqStack *stack, int x);

/**
 * 出栈
*/
SeqStack *Pop(SeqStack *stack);

/**
 * 返回栈顶数字
*/
int GetPop(SeqStack *stack);

/**
 * 判空
*/
int IsEmpty(SeqStack *stack);

int main(void)
{
    SeqStack *first = Init();

    first = Push(first, 1);
    first = Push(first, 2);
    first = Push(first, 3);
    printf("%d\n", GetPop(first));
    first = Pop(first);
    printf("%d\n", GetPop(first));
    printf("%d\n", IsEmpty(first));
    printf("OK\n");
    return 0;
}

SeqStack *Init()
{
    return NULL;
}

SeqStack *Push(SeqStack *stack, int x)
{
    SeqStack *new = stack;
    stack = (SeqStack *)malloc(sizeof(SeqStack));
    if (stack == NULL)
    {
        printf("Error\n");
        return NULL;
    }
    stack->number = x;
    stack->next = new;
    return stack;
}

int GetPop(SeqStack *stack)
{
    return stack->number;
}

SeqStack *Pop(SeqStack *stack)
{
    int x;
    SeqStack *temp = stack;
    if (IsEmpty(stack))
    {
        printf("Underflow\n");
        exit(1);
    }
    x = temp->number;
    stack = temp->next;
    free(temp);
    return stack;
}

int IsEmpty(SeqStack *stack)
{
    if (stack == NULL)
        return 1;
    return 0;
}