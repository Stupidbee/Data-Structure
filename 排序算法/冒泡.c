#define MAXSIZE 10
#define OK 1
#define ERROR 0	
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct
{
	int r[MAXSIZE+1];//存储要排序的数组 其中r[0]用作哨兵或临时变量
	int length;
}Sqlist;

void swap(Sqlist *L,int i,int j)
{
	int temp = L->r[i];
	L->r[i]=L->r[j];
	L->r[j]=temp;
}

/**************/
/*冒泡排序*/
//冒泡排序初级版
void BubbleSort_Fisrt_edition(Sqlist *L)
{
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i;j<L-length;j++)
		{
			if(L->[i]>L->[j])
			{
				swap(L,i,j);
			}
		}
	}
}
/************************************************/
//正宗冒泡排序 二版
void BubbleSort_Sencond_edition(Sqlist *L)
{
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i;j<L->length;j++)
		{
			if(L->[j]>L[j+1])
				swap(L,j,j+1);//这里是核心正宗的冒泡
		}
	}
}
/************************************************/
//冒泡排序优化 三版
/*立个Flag*/
void BubbleSort_Third_edition(Sqlist *L)
{
	int i,j;
	Status flag = TRUE;
	for(i=1;i<L->length && flag;i++)
	{
		flag = FALSE;
		for(j=L->length-1;j>=i;j--)//从屁股后面来
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1)；
				flag = TRUE;
			}
		}
	}
}
/************************************************/
//快速排序Final_Edition
void QuickSort(Sqlist *L)
{
	QSort(L,1,L->length);
}

void QSort(Sqlist *L,int low,int high)
{
	int pivot;
	if(low<high)
	{
		pivot=Paratition(L,low,high);//分块,算出枢纽pivot
		
		QSort(L,low,pivot-1);//低子表递归排序
		QSort(L,pivot+1,high);//高子表递归排序
	}
}

//递归优化实施
void Qsort_1(Sqlist *L,int low,int high)
{
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Paratition_1(L,low,high)
			
			Qsort_1(L,low,pivot-1);
			low=pivot+1;
		}
	}
	else
		InsertSort(L);
}
//枢纽计算
int Paratition(Sqlist *L,int low,int high)
{
	int pivotkey;
	pivotkey = L->r[low];//初始化
	while(low<high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		swap(L,low,high);
		while(low<high && L->r[low]<=pivotkey)
			low++;
		swap(L,low,high);
	}
	return low;	
}
//对于枢纽计算的优化优化不必要的交换
int Paratition_1(Sqlist *L,int low,int high)
{
	int pivotkey;
	pivotkey = L->r[low];
	L->r[0] = pivotkey;//枢纽关键字的备份
	while(low<high)
	{
		while(low<high && L->r[high]>=pivotkey)
			high--;
		L->r[low] = L->r[high];//采用替换而非交换的方式进行操作
		while(low<high && L->r[low]<=pivotkey)
			low++;
		L->r[high] = L->r[low];//采用替换而非交换的方式进行操作
	}
	L->r[low]=L->r[0];//将枢纽值替回
	return low;
}
/********************************************************/
/***************简单选择排序*****************************/
void SelectSort(Sqlist *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{
		min = i;
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[min]>L->r[j])
				min = j;
		}
		if(i!=min)
			swap(L,i,min);
	}
}
/****************插入排序*******************************/
void InsertSort(Sqlist *L)
{
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if(L->r[i]<L->r[i-1])//判断插入条件
		{
			L->r[0]=L->r[i];//设置哨兵
			for(j=i-1;L->r[j]>L->r[0];j--)//记录后移
			{
				L->r[j+1]=L->r[j];
			}
			L->r[j+1] = L->r[0];//插入到正确位置
		}
	}
}
/*****************希尔排序********************************/
void ShellSort(Sqlist *L)
{
	int i,j;
	int increment = L->length;
	do
	{
		increment = increment/3+1;//增量序列
		for(i=increment+1;i<=L->length;i++)
		{
			if(L->r[i]<L->r[i-increment])
			{
				L->r[0] = L->r[i];//暂存
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)//记录后移查找插入位置
					L->r[j+increment] = L->r[0];//插入
			}
		}
	}
	while(increment>1);
}
/****************堆排序、归并排序*************************/

