#include<stdio.h> 
#include<stdlib.h> 
#include"Status.h" 
typedef int QElemType; 
#include"CirQueue.h" 
void visitElem(QElemType e)
{ 
	printf("%d ",e); 
} 
int main() 
{ //���ڶ��в��Ե������� 
	CirQueue Q; 
	QElemType e; 
	int i; 
	InitCirQueue(Q,11); 
	for(i=1;i<=7;i++) 
	insertQueue(Q,2*i+1); 
	printf("���� Q:"); 
	queueTraverse(Q, visitElem); 
	printf("\n"); 
	for(i=1;i<=5;i++)
	{ 	deleteQueue(Q,e); //����, ��e�������Ԫ�� 
		printf("%d �ѳ���\n",e); 
	} 
	printf("���� Q:"); 
	queueTraverse(Q, visitElem); 
	printf("\n"); 
	for(i=1;i<=6; i++)
		insertQueue(Q,2*i);//�� 2*i ��� 
	printf("���� Q:"); 
	queueTraverse(Q, visitElem);//���ñ���������� 
	printf("\n"); 
	getFront(Q,e);//ȡ��ͷԪ�ظ� e 
	printf("��ǰ�ӳ�Ϊ:%d, ��ǰ��ͷԪ��Ϊ:%d\n", queueLength(Q),e); 
	clearQueue(Q);//������� 
	printf("��������գ��ӳ�Ϊ:%d\n", queueLength(Q)); 
	return 0; 
}

