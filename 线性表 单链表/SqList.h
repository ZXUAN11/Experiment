#include <stdlib.h>
#include "Status.h"
//顺序表类型及其基本操作函数的定义
#define ListSpaceIncr 20 
typedef int LElemType;   
typedef struct
{
   LElemType *base;  
   int length;   
   int listSize;  
}SqList; 	//SqList为顺序表类型

Status InitSqList(SqList &L, int InitSize)
{
	//创建初始空间大小为InitSize的空顺序表
	L.base = (LElemType * )malloc(InitSize * sizeof(LElemType));
	if(!L.base)
		return(OVERFLOW);
	L.length = 0;
	L.listSize = InitSize;
	return OK;
}

int listLength(SqList L)
{
	//求顺序表L的长度
	return L.length;
}

Status listIsEmpty(SqList L) 
{
	//判断顺序表L是否为空；空返回TRUE
	//否则返回FALSE 
	if(!L.length)
		return TRUE;
	else return FALSE;                                  
}

void clearList(SqList &L)
{
	//将顺序表L清空
	L.length = 0;
                                             
}
Status getElem(SqList L,int i,LElemType &e)
{ 
	//取顺序表L的第i个元素
	if(!L.length)	return ERROR;
	e = L.base[i-1];
	return OK;                       
}

Status equal(LElemType, LElemType);//元素相等关系的比较函数声明

int locateElem(SqList L, LElemType e)
{ 
	//在顺序表L中查找与e相等的第一个元素,并返回其位序，查找失败时返回0
	int i = 0;
	while (i<L.length && !equal(L.base[i],e))	
			i++;
	if(i<L.length)	return i+1;
	else return 0;                                                
}   
Status listInsert(SqList &L, int i, LElemType e)
{
	//在顺序表L的第i个位置插入元素e
	LElemType *newBase;
	int j;
	if(i<1 || i>L.length+1)	return ERROR;
	if(L.length==L.listSize)
	{
		newBase = (LElemType*)realloc(L.base,(L.listSize+ListSpaceIncr)*sizeof(LElemType));
		if(!newBase)	return OVERFLOW;
		L.base = newBase;
		L.listSize+=ListSpaceIncr;
	}                   
	for(j=L.length-1; j>=i-1; j--)
	{
		L.base[j+1] = L.base[j];
	}
	L.base[i-1] = e;
	L.length++;
	return OK;
}
Status listDelete(SqList &L,int i,LElemType &e)
{
  	//删除顺序表的第i个元素并由e返回其值
   	int j;
	if(i<1 || i>L.length)	return ERROR;
	e = L.base[i-1];
	for(j=i; j<L.length; j++)
	{
		L.base[j-1] = L.base[j];
	}
	L.length--;
	return OK;
}
void listTraverse(SqList L,void (*visit)(LElemType e))
{  
	//遍历操作
   int i;
   for(i=0;i<L.length;i++) 
       visit(L.base[i]);
}

