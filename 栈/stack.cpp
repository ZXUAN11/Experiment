#include<stdio.h> 
#include<stdlib.h> 
#include"Status.h"
typedef char SElemType;//定义栈中元素类型
#include"SqStack.h";
int bracketsCheck() 
{ //输入表达式串，检查括号匹配情况
	//返回0表示匹配正确，返回-1表示缺左括号。返回值大于0时，则表示缺少右括号的个数
	char ch;
	SqStack S;
	InitSqStack(S,30);
	ch=getchar();
	while(ch!='\n'){
		if(ch=='(') Push(S,ch); //为左括号为入栈
		else if(ch==')'){//为右括号
			if(!stackIsEmpty(S)) Pop(S,ch);//栈非空则出栈匹配
			else return -1;//栈空说明缺与ch匹配的左括号 
		} 
		ch=getchar();	
	}
	
	return stackLength(S);//栈长为0，则正确匹配，否则栈长为缺少右括号的数量 
}
int main()
{
	int result;
	printf("输入表达式串\n");
	result= bracketsCheck();
	if(result==0) printf("括号匹配正确！\n");
	else if(result>0) printf("错误，缺%d个\')\'!\n",result);
	else printf("错误，缺一个或多个\'(\'!\n");
	return 0;
} 
