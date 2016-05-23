//两个线性表集合A，B的并集操作
/*线性表的获取，插入、删除操作*/
void union(List *La,List Lb)
{
	int La_len,lb_len,i;
	Elemtype e;//A,B相同元素
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	for(i=1; i<=Lb_len;i++)
	{
		GetElem(Lb,i,e)；
		if(!LocateElem(La,e))  //锁定La与Lb相同元素
			ListInsert(La,++La_len);	
	}
} 

//一般操作
/**********************************/
/*线性表顺序存储结构*/
#define MAXSIZE 20 /*初始化分配量*/

typedef int Elemtype;

typedef struct
{
	Elemtype data[MAXSIZE];
	int Length;
}Sqlist;

/******顺序存储结构插入与删除******/
/*GetElem获取元素函数*/
#define OK 1
#define ERROR 0	
#define TRUE 1
#define FALSE 0

typedef int Status;

Status GetElem(Sqlist L,int i,Elemtype *e)
{
		if(L.length ==0||i<1||i>L.length)
		{
			return FALSE;//越界输出
		}
		*e=L.data[i-1];
		return OK;
}

Status ListInsert(Sqlist *L,int i,Elemtype e)
{
	int k;
	if(L->length == MAXSIZE)
		return ERROR;//满界判断
	if(i<1||i>L->length+1)//越界判断
		return ERROR;
	if(i<=L->length)
	{
		for(k=L->length-1;k>i-1;k--)//移屁股
		{
			L->data[k+1]=L->data[k];
		}
	}
	L->data[i-1]=e;//插入元素e
	L->length++;//字段长度+1；
	return OK;
}

Status LisDelete(Sqlist *L,int i,Elemtype e)
{
	int k;
	if(L->length == 0)
		return ERROR;
	if(i>L->length+1||i<1)
		return ERROR;
	
	*e=L-data[i-1];//删除元素
	if(i<L->length)
	{
		for(k=i;k<L-length;k++)
		{
			L->data[k-1] = L->data[k];
		}
	}
	L->length--;//字段长度-1;
	return OK;
}