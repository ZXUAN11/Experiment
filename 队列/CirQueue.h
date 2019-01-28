#include <stdlib.h>
#include "Status.h"
typedef int QElemType;
typedef struct
{ 
	QElemType *base; 
	int front,rear; 
	int queueSize; 
}CirQueue; 
Status InitCirQueue(CirQueue &Q,int QSize)
{ //����һ���ռ��СΪ QSize �ĳ�ʼ�ն��� Q
	Q.base=(QElemType*) malloc(QSize *sizeof(QElemType));
	if(!Q.base) return OVERFLOW; //����洢�ռ�ʧ��
	Q.queueSize=QSize;
	Q.front=Q.rear=0; //��Ϊ�ն�
	return OK; 
}
Status queueIsEmpty(CirQueue Q) 
{ //�ж�ѭ������ Q �Ƿ�Ϊ��
	if(Q.front==Q.rear) return TRUE; //����Ϊ��
	else return FALSE; //���зǿ� 
}
void clearQueue(CirQueue &Q)
{ //��ѭ������ Q ���
	Q.front=Q.rear=0;
}  
int queueLength(CirQueue Q)
{ //��ѭ������ Q �ĳ���
	return (Q.rear-Q.front+Q.queueSize)%Q.queueSize;
}
Status getFront(CirQueue Q,QElemType &e)
{ //ȡ���� Q �Ķ�ͷԪ��ֵ
	if(Q.front==Q.rear) return ERROR;//�ӿգ���������
	e=Q.base[Q.front];
	return OK; 
}
Status insertQueue(CirQueue &Q,QElemType e)
{ //��ѭ������ Q �Ķ�β�˲���Ԫ�� e
	if((Q.rear+1)%Q.queueSize==Q.front) return OVERFLOW;//�������ռ���������ʧ��
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.queueSize; //��βָ�����һ��λ��
	return OK; 
}
Status deleteQueue(CirQueue &Q,QElemType &e)
{ //������ Q �Ķ�ͷԪ�س��Ӳ��� e ������ֵ
	if(Q.front==Q.rear) return ERROR; //�ӿգ�����ʧ��
	e=Q.base[Q.front]; //�ɲ���e���س���Ԫ�ص�ֵ
	Q.front=(Q.front+1)%Q.queueSize; //��ͷָ�����һ��λ��
	return OK; 
}
void queueTraverse(CirQueue Q, void(*visit)(QElemType e)) 
{ //�������� 
	int i=Q.front; 
	while(i!=Q.rear)
	{ 	visit(Q.base[i]); 
		i=(i+1)%Q.queueSize; 
	} 
} 
