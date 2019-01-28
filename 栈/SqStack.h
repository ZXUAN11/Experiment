#include <stdlib.h>
#include "Status.h"
#define StackSpaceIncr 20
typedef char SElemType;
typedef struct 
{ 
	SElemType *Elem; 
	int top; 
	int stackSize; 
}SqStack; //˳��ջ���� 
Status InitSqStack(SqStack &S,int InitSize) 
{ //��ʼ������
	S.Elem=(SElemType *)malloc(InitSize*sizeof(SElemType));
	if(!S.Elem) return OVERFLOW;//ջ�洢�ռ����ʧ��
	S.stackSize=InitSize;
	S.top=0;  //��Ϊ��ջ 
	return OK; 
}
Status stackIsEmpty(SqStack S) 
{ //�ж�ջ S �Ƿ�Ϊ��
	if(!S.top) return TRUE;
	 else return FALSE;
}
void clearStack(SqStack &S)
{ //��˳��ջ S ���
	S.top=0;
}
int stackLength(SqStack S)
{ //��˳��ջ S �ĳ���
	return S.top;
}
Status Push(SqStack &S, SElemType e)
{ //����˳��ջ S����Ԫ�� e ��ջ
	SElemType *newBase;
	if(S.top==S.stackSize){//����ǰջ�Ŀռ������������»�ȡ����ռ�
	newBase=(SElemType *)realloc (S.Elem,(S.stackSize+StackSpaceIncr)*sizeof(SElemType));
	if(!newBase) return OVERFLOW;//����ʧ�� 
	S.Elem=newBase;
	S.stackSize+=StackSpaceIncr; //����ɹ� 
	}
	S.Elem[S.top]=e; //����Ԫ��e
	S.top++; //ջ��ָ��top����һ��λ��
	return OK; 
}
Status Pop(SqStack &S, SElemType &e)
{ //��˳��ջ S ��ջ��Ԫ�س�ջ
	if(!S.top) return ERROR;//ջ�� ����ʧ��
	S.top--; //ջ��ָ��top����һ��λ��
	e=S.Elem[S.top];
	return OK; 
}
Status getTop(SqStack S,SElemType &e)
{ //ȡ˳��ջ S ��ջ��Ԫ��
	if(!S.top) return ERROR; //ջ�� ����ʧ��
	e=S.Elem[S.top-1]; //�ɲ���e����ջ��Ԫ�ص�ֵ
	return OK; 
}

