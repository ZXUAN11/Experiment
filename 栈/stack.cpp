#include<stdio.h> 
#include<stdlib.h> 
#include"Status.h"
typedef char SElemType;//����ջ��Ԫ������
#include"SqStack.h";
int bracketsCheck() 
{ //������ʽ�����������ƥ�����
	//����0��ʾƥ����ȷ������-1��ʾȱ�����š�����ֵ����0ʱ�����ʾȱ�������ŵĸ���
	char ch;
	SqStack S;
	InitSqStack(S,30);
	ch=getchar();
	while(ch!='\n'){
		if(ch=='(') Push(S,ch); //Ϊ������Ϊ��ջ
		else if(ch==')'){//Ϊ������
			if(!stackIsEmpty(S)) Pop(S,ch);//ջ�ǿ����ջƥ��
			else return -1;//ջ��˵��ȱ��chƥ��������� 
		} 
		ch=getchar();	
	}
	
	return stackLength(S);//ջ��Ϊ0������ȷƥ�䣬����ջ��Ϊȱ�������ŵ����� 
}
int main()
{
	int result;
	printf("������ʽ��\n");
	result= bracketsCheck();
	if(result==0) printf("����ƥ����ȷ��\n");
	else if(result>0) printf("����ȱ%d��\')\'!\n",result);
	else printf("����ȱһ������\'(\'!\n");
	return 0;
} 
