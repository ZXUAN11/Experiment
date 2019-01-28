#include<stdio.h>
#include <stdlib.h>
#include "Status.h"
// 单链表类型及基本操作函数的定义
typedef int LElemType;
typedef struct LNode{
	LElemType  data;
	struct LNode *next; 
}LNode,*LinkList; 
Status InitLinkList(LinkList &L)
{ //初始创建空的带头结点的单链表 L
	L=(LinkList)malloc(sizeof(LNode));//申请一个头节点，使头指针L指向该结点
	if(!L) return OVERFLOW; //头节点申请失败
	L->next=NULL;//头节点的后继指针域为NULL
	return OK; 
}
int listLength(LinkList L)
{//求单链表 L 的长度
	LNode *p=L;//p指向头节点
	int j=0;//j用于计数，表示P所指结点的位序
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
Status listIsEmpty(LinkList L)
{ //判断单链表 L 是否为空；
//空返回 TRUE，否则返回 FALSE
	if(!L)
		return TRUE;
	else return FALSE; 	
}
Status getElem(LinkList L,int i,LElemType &e)
{ //取单链表 L 的第i个元素若存在第i个结点，则由e返回其值
	LNode *p=L;
	int j=0;
	while(j<i && p->next){
		//当p所指第j个结点不是第i个且又不是最后一个时
		//则继续向后查找 
		p=p->next;
		j++; 
	} 
	if(j==i){
		//若找到第i个结点，则由e返回其值
		e=p->data;
		return OK; 
	}
	else return ERROR;
}
Status equal(LElemType,LElemType); 
//元素相等关系的比较函数声明
 
LinkList locateElem(LinkList L,LElemType e)
{ 	//在单链表 L 中查找数据域值为 e 的结点； 
	//找到，返回结点的地址；找不到，则返回 NULL
	LNode *p=L->next;//初始p指向第1个结点
	while(p && !equal(p->data,e))
		p=p->next;
	if(p) return p; //不到
	else return NULL; //找不到 
}
Status listInsert(LinkList &L,int i, LElemType e)
{ //在单链表 L 的第 i 个位置插入元素 e
	LNode *p=L,*q;//p用于查找第i-1个结点，初始指向头结点
	//q用于指向欲插入结点
	int j=0;
	while(j<i-1 && p->next){
		p=p->next;
		j++;
	}
	if(j == i-1){//若p指向第j个结点为第i-1个结点，则在其后插入新结点
	q=(LNode *)malloc(sizeof(LNode));//生成新结点
	if(!q) return OVERFLOW;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK; 
	}
	else return ERROR; // 第i-1个结点不存在，插入位置不正确 
}
Status listDelete(LinkList &L,int i,LElemType &e)
{ //删除单链表的第 i 个元素并由 e 返回其值
	LNode *p=L,*q;
	int j=0;
	while(j<i-1 && p->next)
	{
		p=p->next;
		j++;
	}
	if(j==i-1 && p->next){//当p所指结点为第i-1个结点且第i个结点存在时，则
						//执行删除
		q=p->next;
		p->next=q->next;
		e=q->data;
		free(q);	
	}
	else return ERROR; 
} 
void listTraverse(LinkList L,void(*visit)(LElemType e)) 
{ //遍历操作 
	LinkList p; 
	p=L->next; 
	while(p){ 
		visit(p->data); 
		p=p->next; 
		} 
} 
