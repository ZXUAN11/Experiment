#include <stdlib.h>
#include "Status.h"
#define StackSpaceIncr 20
typedef char SElemType;
typedef struct 
{ 
	SElemType *Elem; 
	int top; 
	int stackSize; 
}SqStack; //顺序栈类型 
Status InitSqStack(SqStack &S,int InitSize) 
{ //初始化操作
	S.Elem=(SElemType *)malloc(InitSize*sizeof(SElemType));
	if(!S.Elem) return OVERFLOW;//栈存储空间分配失败
	S.stackSize=InitSize;
	S.top=0;  //置为空栈 
	return OK; 
}
Status stackIsEmpty(SqStack S) 
{ //判断栈 S 是否为空
	if(!S.top) return TRUE;
	 else return FALSE;
}
void clearStack(SqStack &S)
{ //将顺序栈 S 清空
	S.top=0;
}
int stackLength(SqStack S)
{ //求顺序栈 S 的长度
	return S.top;
}
Status Push(SqStack &S, SElemType e)
{ //对于顺序栈 S，将元素 e 入栈
	SElemType *newBase;
	if(S.top==S.stackSize){//若当前栈的空间已满，则重新获取更大空间
	newBase=(SElemType *)realloc (S.Elem,(S.stackSize+StackSpaceIncr)*sizeof(SElemType));
	if(!newBase) return OVERFLOW;//扩充失败 
	S.Elem=newBase;
	S.stackSize+=StackSpaceIncr; //扩充成功 
	}
	S.Elem[S.top]=e; //插入元素e
	S.top++; //栈顶指针top上移一个位置
	return OK; 
}
Status Pop(SqStack &S, SElemType &e)
{ //将顺序栈 S 的栈顶元素出栈
	if(!S.top) return ERROR;//栈空 操作失败
	S.top--; //栈顶指针top下移一个位置
	e=S.Elem[S.top];
	return OK; 
}
Status getTop(SqStack S,SElemType &e)
{ //取顺序栈 S 的栈顶元素
	if(!S.top) return ERROR; //栈空 操作失败
	e=S.Elem[S.top-1]; //由参数e返回栈顶元素的值
	return OK; 
}

