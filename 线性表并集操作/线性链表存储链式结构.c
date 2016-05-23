/*线性列表存储结构*/
typedef int Elemtype;

typedef struct Node
{
	Elemtype data;		//数据域
	struct Node *next;	//指针域
}Node;

typedef struct Node *LinkList;//定义linklist 组成数据域  和  存放后继节点地址的指针域组成

typedef int Status;

#define OK 1
#define ERROR 0	
#define TRUE 1
#define FALSE 0
/*
p->data = a[i-1];//数据域
p->next -> data=a[i];//指针域
*/
/*单链表的读取*/

/*核心从头遍历*/

//初始条件：顺序线性表L已存在，且i>=1&&i<=ListLength(L);

Status GetElem(LinkList L,int i,Elemtype *e)
{
	int j;
	LinkList p;//申明一节点
	p = L->next;//指向第一节点
	j=1;		//计数器
	
	while(p && j<i)//头指针为空或计数器还没到头 循环继续
	{
		p = p->next;//p指向下一节点
		++j;
	}
	
	if(!p||j>i)
		reture ERROR;//指针非空，第i个元素不存在
	*e = p->data;
	return OK;
}

/*单链表插入与删除*/
//初始条件：顺序线性表L已存在，且i>=1&&i<=ListLength(L)
//操作结果单链表长度+1；

Status ListInsert(LinkList L,int i,Elemtype e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	
	while(p&&j < i)//遍历
	{
		p = p->next;
		++j;
	}
	
	if(!p||j>i)
		return ERROR;
	
	s = (LinkList)malloc(sizeof(Node));//生成新节点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
	
}

//初始条件：顺序线性表L已存在，且i>=1&&i<=ListLength(L)
//操作结果单链表长度-1，返回删除元素e

Status ListDelete(LinkList L;int i;Elemtype e)
{
	int j;
	LinkList q,p;
	p = *L;
	j = 1;
	
	while(p->next && j<i)//遍历
	{
		p = p->next;
		++j;
	}
	
	if(!(p->next)||j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);	//回收节点释放内存
	return OK;
}

//单链表的整表创建
/*随机产生n个元素的值，建立带表头结点的单链表L(头插法)*/
void CreateListHead(LinkList *L,int n)//头插法
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;//先建立一个带头结点的单链表
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));//生成新的节点
		p->data = rand()%100+1;
		p->next = (*L)->next;
		(*L)->next = p;//插入表头
	}
}
/*尾插法*/
void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));//初始化随机种子
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;//r为指向尾部的节点
	for(i=0;i<n;i++)
	{
		p = (Node*)malloc(sizeof(Node));//生成新的节点
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	
}






