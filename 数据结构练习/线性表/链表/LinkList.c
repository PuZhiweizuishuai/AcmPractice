#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int num;
    struct Node *next;
} LinkList;

/**
 * 创建链表
 * 使用尾插法
*/
LinkList *CreateList();

/**
 * 遍历显示链表
 * 参数 list 为链表头节点
*/
void TraverseLIst(LinkList *list);

/**
 * 返回链表长度
*/
int ListLength(LinkList *list);

/**
 * 取节点
 * n 为第几个节点
*/
LinkList *GetNumber(LinkList *list, int n);

/**
 * 查找链表中有无该数
*/
LinkList *LookUp(LinkList *list, int n);

/**
 * 修改节点中的数
*/
void Change(LinkList *list);

/**
 * 向链表的第 n个数后插入数据 x
*/
int Insert(LinkList *list, int n, int x);

/**
 * 删除链表中的数据
*/
int Delete(LinkList *list, int n);

int main(void)
{
    LinkList *listOne = CreateList();
    TraverseLIst(listOne);
    printf("\n链表的长度为 %d\n", ListLength(listOne));
    printf("链表第 2 个节点是：%d\n",GetNumber(listOne,2)->num);
	printf("数字 3 在链表中存在，位置在 %p，值为 %d\n",LookUp(listOne,3), LookUp(listOne, 3)->num);

	Change(listOne);
	printf("修改后的链表为：\n");
	TraverseLIst(listOne);

	printf("在链表第3个位置插入一个数结果为：\n");
	Insert(listOne, 3, 100);
	
	TraverseLIst(listOne);
	
	
	printf("在链表第3个位置删除刚才的数结果为：\n");
	Delete(listOne,3);
	
	TraverseLIst(listOne);
    return 0;
}

LinkList *CreateList()
{
    // 声明头节点并创建空间
    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    int val;
    // 如果空间声请失败返回NULL
    if (head == NULL)
    {
        printf("NULL\n");
        return NULL;
    }
    // 声明链表尾节点
    LinkList *end = head;
    end->next = NULL;
    while (1)
    {
        // 申请新的链表空间
        LinkList *new = (LinkList *)malloc(sizeof(LinkList));
        scanf("%d", &val);
        if (val == -1)
            break;
        new->num = val;
        // 将新的节点放在头节点之后
        end->next = new;
        new->next = NULL;
        end = new;
    }
    printf("OK\n");
    return head;
}

void TraverseLIst(LinkList *list)
{
    LinkList *p = list;
    p = p->next;
    if (p == NULL)
        printf("NULL\n");

    while (p)
    {
        printf("%d\n", p->num);
        p = p->next;
    }
}

int ListLength(LinkList *list)
{
    int length = 0;
    LinkList *p = list;
    p = p->next;
    if (p == NULL)
        return 0;

    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

LinkList *GetNumber(LinkList *list, int n)
{
    int i = 0;
    LinkList *p = list;
    while (p->next != NULL && i < n)
    {
        p = p->next;
        i++;
    }
    if (i == n)
        return p;
    else
        return NULL;
}

LinkList *LookUp(LinkList *list, int n)
{
    LinkList *p = list;
    p = p->next;
    while (p != NULL)
    {
        if (p->num == n)
        {
            return p;
        }
        p = p->next;
    }
    return p;
}

void Change(LinkList *list)
{
    int k, n;
    LinkList *p = list;
    printf("按节点数据修改请按 1 ，按节点修改请按 2 : ");
    scanf("%d", &k);
    while (k != 1 && k != 2)
    {
        printf("输入错误，请重新输入！");
        scanf("%d", &k);
    }
    if (k == 1)
    {
        printf("请输入你要修改的数：");
        scanf("%d", &n);
        p = LookUp(list, n);
        if (p == NULL)
        {
            printf("没有发现该数！无法修改。");
        }
        else
        {
            printf("发现该数，请输入要修改的值：");
            scanf("%d", &n);
            p->num = n;
            printf("修改成功！");
        }
    }
    else
    {
        printf("请输入你要修改的节点：");
        scanf("%d", &n);
        p = GetNumber(list, n);
        if (p == NULL)
        {
            printf("没有发现节点！无法修改。");
        }
        else
        {
            printf("发现该节点值为 %d 请输入要修改的值：", p->num);
            scanf("%d", &n);
            p->num = n;
            printf("修改成功！");
        }
    }
}

int Insert(LinkList *list, int n, int x)
{
    LinkList *p, *s;
    p = GetNumber(list, n - 1); //查找第n-1个节点
    if (p == NULL)
    {
        printf("error\n");
        return 0;
    }
    s = (LinkList *)malloc(sizeof(LinkList));
    s->num = x;
    s->next = p->next;
    p->next = s;
    return 1;
}

int Delete(LinkList *list, int n)
{
    LinkList *p, *r;
    p = GetNumber(list, n - 1);
    if (p->next == NULL || p == NULL)
    {
        printf("error!\n");
        return 0;
    }

    r = p->next;       //保存节点
    p->next = r->next; //删除节点
    free(r);
    return 1;
}