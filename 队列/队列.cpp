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
{ //用于队列测试的主函数 
	CirQueue Q; 
	QElemType e; 
	int i; 
	InitCirQueue(Q,11); 
	for(i=1;i<=7;i++) 
	insertQueue(Q,2*i+1); 
	printf("队列 Q:"); 
	queueTraverse(Q, visitElem); 
	printf("\n"); 
	for(i=1;i<=5;i++)
	{ 	deleteQueue(Q,e); //出队, 用e保存出队元素 
		printf("%d 已出队\n",e); 
	} 
	printf("队列 Q:"); 
	queueTraverse(Q, visitElem); 
	printf("\n"); 
	for(i=1;i<=6; i++)
		insertQueue(Q,2*i);//将 2*i 入队 
	printf("队列 Q:"); 
	queueTraverse(Q, visitElem);//利用遍历输出队列 
	printf("\n"); 
	getFront(Q,e);//取队头元素给 e 
	printf("当前队长为:%d, 当前队头元素为:%d\n", queueLength(Q),e); 
	clearQueue(Q);//队列清空 
	printf("队列已清空，队长为:%d\n", queueLength(Q)); 
	return 0; 
}

