#include<stdio.h>
#include <stdlib.h>
#include "Status.h"
// ���������ͼ��������������Ķ���
typedef int LElemType;
typedef struct LNode{
	LElemType  data;
	struct LNode *next; 
}LNode,*LinkList; 
Status InitLinkList(LinkList &L)
{ //��ʼ�����յĴ�ͷ���ĵ����� L
	L=(LinkList)malloc(sizeof(LNode));//����һ��ͷ�ڵ㣬ʹͷָ��Lָ��ý��
	if(!L) return OVERFLOW; //ͷ�ڵ�����ʧ��
	L->next=NULL;//ͷ�ڵ�ĺ��ָ����ΪNULL
	return OK; 
}
int listLength(LinkList L)
{//������ L �ĳ���
	LNode *p=L;//pָ��ͷ�ڵ�
	int j=0;//j���ڼ�������ʾP��ָ����λ��
	while(p->next){
		p=p->next;
		j++;
	}
	return j;
}
Status listIsEmpty(LinkList L)
{ //�жϵ����� L �Ƿ�Ϊ�գ�
//�շ��� TRUE�����򷵻� FALSE
	if(!L)
		return TRUE;
	else return FALSE; 	
}
Status getElem(LinkList L,int i,LElemType &e)
{ //ȡ������ L �ĵ�i��Ԫ�������ڵ�i����㣬����e������ֵ
	LNode *p=L;
	int j=0;
	while(j<i && p->next){
		//��p��ָ��j����㲻�ǵ�i�����ֲ������һ��ʱ
		//����������� 
		p=p->next;
		j++; 
	} 
	if(j==i){
		//���ҵ���i����㣬����e������ֵ
		e=p->data;
		return OK; 
	}
	else return ERROR;
}
Status equal(LElemType,LElemType); 
//Ԫ����ȹ�ϵ�ıȽϺ�������
 
LinkList locateElem(LinkList L,LElemType e)
{ 	//�ڵ����� L �в���������ֵΪ e �Ľ�㣻 
	//�ҵ������ؽ��ĵ�ַ���Ҳ������򷵻� NULL
	LNode *p=L->next;//��ʼpָ���1�����
	while(p && !equal(p->data,e))
		p=p->next;
	if(p) return p; //����
	else return NULL; //�Ҳ��� 
}
Status listInsert(LinkList &L,int i, LElemType e)
{ //�ڵ����� L �ĵ� i ��λ�ò���Ԫ�� e
	LNode *p=L,*q;//p���ڲ��ҵ�i-1����㣬��ʼָ��ͷ���
	//q����ָ����������
	int j=0;
	while(j<i-1 && p->next){
		p=p->next;
		j++;
	}
	if(j == i-1){//��pָ���j�����Ϊ��i-1����㣬�����������½��
	q=(LNode *)malloc(sizeof(LNode));//�����½��
	if(!q) return OVERFLOW;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return OK; 
	}
	else return ERROR; // ��i-1����㲻���ڣ�����λ�ò���ȷ 
}
Status listDelete(LinkList &L,int i,LElemType &e)
{ //ɾ��������ĵ� i ��Ԫ�ز��� e ������ֵ
	LNode *p=L,*q;
	int j=0;
	while(j<i-1 && p->next)
	{
		p=p->next;
		j++;
	}
	if(j==i-1 && p->next){//��p��ָ���Ϊ��i-1������ҵ�i��������ʱ����
						//ִ��ɾ��
		q=p->next;
		p->next=q->next;
		e=q->data;
		free(q);	
	}
	else return ERROR; 
} 
void listTraverse(LinkList L,void(*visit)(LElemType e)) 
{ //�������� 
	LinkList p; 
	p=L->next; 
	while(p){ 
		visit(p->data); 
		p=p->next; 
		} 
} 
