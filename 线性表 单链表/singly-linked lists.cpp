#include<stdio.h>
#include<stdlib.h> 
#include"Status.h" 
typedef int LElemType; //定义元素类型为 int 类型 
#include"LinkList.h" 
typedef LinkList mySetType; //定义集合类型 
Status equal(LElemType e1,LElemType e2)
{ //元素相等关系的比较函数 
	if(e1==e2)
		return TRUE; 
	else return FALSE; 
} 
void visitElem(LElemType e)
{ //元素的访问函数 
	printf(" %d ",e); 
} 
void creatSet(mySetType &A,int n)
{ //通过输入的 n 个元素创建集合 A 
	int i,e; 
	InitLinkList(A); 
	printf("\t 输入%d 个整数：",n); 
	for(i=0;i<n; i++)
	{ 	
		scanf("%d",&e);
		listInsert(A,i+1,e);//头端插入元素
	}
} 
void setUnion(mySetType A,mySetType B, mySetType &C)
{ //集合的并集运算，实现 C=A∪B 
	int i,k,len,e; 
	InitLinkList(C); 
	k=0; //初始化空集合 C；k 为 C 长度 
	len=listLength(A); 
	for(i=1;i<=len; i++)
	{ //将集合 A 中所有元素在集合 C 的头端插入 
		getElem(A,i,e); 
		listInsert(C,1,e); 
	} 
	len=listLength(B); //求集合 B 的长度 
	for(i=1;i<=len;i++)
	{ //将 B 中不属于 A 的元素，在 C 头端插入 
		getElem(B,i,e); 
		if(!locateElem(A,e)) //若元素 e 不在 A 中 
		listInsert(C,1,e);//在 C 的头端插入 e 
	} 
} 
void setIntersection(mySetType &A,mySetType B) 
{ //集合交集运算，实现 A=A∩B 
	int i,e,len; 
	len=listLength(A); 
	i=1;
	while(i<=len)
	{ 	getElem(A, i,e); //取 A 的第 i 个元素给 e 
		if(!locateElem(B,e)){//若 e 不属于 B 
			listDelete(A,i,e); //删除 A 的第 i 个元素 
			len--; //当前 A 的长度已减 1；下一位序仍为 i 
		} 
		else i++; //下一元素的位序为 
	}
} 
void outputSet(mySetType A)
{ //集合的输出操作 
	printf("{"); 
	listTraverse(A,visitElem); 
	printf("}\n"); 
} 
int main()
{
	mySetType A,B,C;
	int n;
	printf("创建  种类1 :\n");
	printf("\t数量: ");
	scanf("%d", &n);
	creatSet(A,n);
	printf(" 种类1=");
	outputSet(A);
	printf("创建  种类2 :\n");
	printf("\t数量: ");
	scanf("%d", &n);
	creatSet(B,n);
	printf(" 种类2=");
	outputSet(B);
	InitLinkList(C);
	setUnion(A,B,C); 
	printf("\n 全部种类 = 种类1 ∪种类2 =");
	outputSet(C);
	setIntersection(A,B);
	printf(" 共有种类 = 种类1 ∩种类2=");
	outputSet(A);
	return 0;
}
