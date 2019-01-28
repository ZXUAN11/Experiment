#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
typedef int LElemType;	 //定义元素类型为int类型
#include "SqList.h"
typedef SqList mySetType;	 //定义集合类型
Status equal(LElemType e1,LElemType e2)
{
   	//元素相等关系的比较函数
   	if(e1==e2) return TRUE;
   	else return FALSE;
}
void visitElem(LElemType e)
{
	//元素访问操作
   	printf("%d ",e);
}
void creatSet(mySetType &A, int n)
{
	//通过输入的n个元素创建集合A
   	int i,e;
   	InitSqList(A, n+10);   
   	printf("\t输入%d个整数：",n); 
   	for (i=0; i<n; i++)
   	{
      	scanf("%d", &e);
        listInsert(A,i+1,e);	//尾端插入元素
  	}
}
void setUnion(mySetType A,mySetType B,mySetType &C)
{
	//集合的并集运算，实现C=A∪B
   	int i,k,len,e;
   	clearList(C);
	k=0; 	// C清空；用k保存C的长度 
   	len=listLength(A); 
   	for(i=1; i<=len; i++)
   	{ 
   		//将集合A中所有元素在集合C的尾端插入
      	getElem(A,i,e); 
      	listInsert(C,++k,e);
   	}
   	len = listLength(B);//求集合B的长度
   	for(i=1;i<=len;i++)
   	{
      	//将B中不属于A的元素在C尾端插入
      	getElem(B,i,e); //取B的第i个元素，赋给e
      	if(!locateElem(A,e)) 	//若元素e不在A中
        	listInsert(C, ++k, e); 	//在C的尾端插入e
   }
}
void setIntersection(mySetType &A,mySetType B) 
{
	//集合交集运算，实现A=A∩B
   	int i,e,len;
   	len=listLength(A);
	i=1; 
  	while(i<=len)
	{   
    	getElem(A, i, e);    //取A的第i个元素给e
      	if(!locateElem(B,e)) 
		{ 
			//若e不属于B
          	listDelete(A,i,e);//删除A的第i个元素
         	len--; 	//当前A的长度已减1
                	//下一元素位序仍为i
      }
      else i++;//下一要处理元素的位序为i+1
   }
}

void outputSet(mySetType A)
{
	//集合的输出操作
   	printf("{ ");
   	listTraverse(A,visitElem); 
   	printf("}\n");
}
int main()
{
	mySetType A,B,C;
	int n;
	printf("创建 种类1 :\n");
	printf("\t数量: ");
	scanf("%d", &n);
	creatSet(A,n);
	printf(" 种类1=");
	outputSet(A);
	printf("创建 种类2 :\n");
	printf("\t数量: ");
	scanf("%d", &n);
	creatSet(B,n);
	printf(" 种类2=");
	outputSet(B);
	InitSqList(C,listLength(A)+listLength(B)+10);
	setUnion(A,B,C); 
	printf("\n全部种类 = 种类1 ∪种类2 =");
	outputSet(C);
	setIntersection(A,B);
	printf("共有种类 = 种类1 ∩种类2=");
	outputSet(A);
	return 0;
}
