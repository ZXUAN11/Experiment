#include <stdlib.h>
#include "Status.h"
//˳������ͼ���������������Ķ���
#define ListSpaceIncr 20 
typedef int LElemType;   
typedef struct
{
   LElemType *base;  
   int length;   
   int listSize;  
}SqList; 	//SqListΪ˳�������

Status InitSqList(SqList &L, int InitSize)
{
	//������ʼ�ռ��СΪInitSize�Ŀ�˳���
	L.base = (LElemType * )malloc(InitSize * sizeof(LElemType));
	if(!L.base)
		return(OVERFLOW);
	L.length = 0;
	L.listSize = InitSize;
	return OK;
}

int listLength(SqList L)
{
	//��˳���L�ĳ���
	return L.length;
}

Status listIsEmpty(SqList L) 
{
	//�ж�˳���L�Ƿ�Ϊ�գ��շ���TRUE
	//���򷵻�FALSE 
	if(!L.length)
		return TRUE;
	else return FALSE;                                  
}

void clearList(SqList &L)
{
	//��˳���L���
	L.length = 0;
                                             
}
Status getElem(SqList L,int i,LElemType &e)
{ 
	//ȡ˳���L�ĵ�i��Ԫ��
	if(!L.length)	return ERROR;
	e = L.base[i-1];
	return OK;                       
}

Status equal(LElemType, LElemType);//Ԫ����ȹ�ϵ�ıȽϺ�������

int locateElem(SqList L, LElemType e)
{ 
	//��˳���L�в�����e��ȵĵ�һ��Ԫ��,��������λ�򣬲���ʧ��ʱ����0
	int i = 0;
	while (i<L.length && !equal(L.base[i],e))	
			i++;
	if(i<L.length)	return i+1;
	else return 0;                                                
}   
Status listInsert(SqList &L, int i, LElemType e)
{
	//��˳���L�ĵ�i��λ�ò���Ԫ��e
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
  	//ɾ��˳���ĵ�i��Ԫ�ز���e������ֵ
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
	//��������
   int i;
   for(i=0;i<L.length;i++) 
       visit(L.base[i]);
}

