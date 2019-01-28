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
{ //构造一个空间大小为 QSize 的初始空队列 Q
	Q.base=(QElemType*) malloc(QSize *sizeof(QElemType));
	if(!Q.base) return OVERFLOW; //分配存储空间失败
	Q.queueSize=QSize;
	Q.front=Q.rear=0; //置为空队
	return OK; 
}
Status queueIsEmpty(CirQueue Q) 
{ //判断循环队列 Q 是否为空
	if(Q.front==Q.rear) return TRUE; //队列为空
	else return FALSE; //队列非空 
}
void clearQueue(CirQueue &Q)
{ //将循环队列 Q 清空
	Q.front=Q.rear=0;
}  
int queueLength(CirQueue Q)
{ //求循环队列 Q 的长度
	return (Q.rear-Q.front+Q.queueSize)%Q.queueSize;
}
Status getFront(CirQueue Q,QElemType &e)
{ //取队列 Q 的队头元素值
	if(Q.front==Q.rear) return ERROR;//队空，操作出错
	e=Q.base[Q.front];
	return OK; 
}
Status insertQueue(CirQueue &Q,QElemType e)
{ //在循环队列 Q 的队尾端插入元素 e
	if((Q.rear+1)%Q.queueSize==Q.front) return OVERFLOW;//队满，空间溢出，入队失败
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%Q.queueSize; //队尾指针后移一个位置
	return OK; 
}
Status deleteQueue(CirQueue &Q,QElemType &e)
{ //将队列 Q 的队头元素出队并由 e 返回其值
	if(Q.front==Q.rear) return ERROR; //队空，操作失败
	e=Q.base[Q.front]; //由参数e返回出队元素的值
	Q.front=(Q.front+1)%Q.queueSize; //队头指针后移一个位置
	return OK; 
}
void queueTraverse(CirQueue Q, void(*visit)(QElemType e)) 
{ //遍历操作 
	int i=Q.front; 
	while(i!=Q.rear)
	{ 	visit(Q.base[i]); 
		i=(i+1)%Q.queueSize; 
	} 
} 
