#include<stdio.h>
#include<stdlib.h> 
#include"Status.h" 
typedef int LElemType; //����Ԫ������Ϊ int ���� 
#include"LinkList.h" 
typedef LinkList mySetType; //���弯������ 
Status equal(LElemType e1,LElemType e2)
{ //Ԫ����ȹ�ϵ�ıȽϺ��� 
	if(e1==e2)
		return TRUE; 
	else return FALSE; 
} 
void visitElem(LElemType e)
{ //Ԫ�صķ��ʺ��� 
	printf(" %d ",e); 
} 
void creatSet(mySetType &A,int n)
{ //ͨ������� n ��Ԫ�ش������� A 
	int i,e; 
	InitLinkList(A); 
	printf("\t ����%d ��������",n); 
	for(i=0;i<n; i++)
	{ 	
		scanf("%d",&e);
		listInsert(A,i+1,e);//ͷ�˲���Ԫ��
	}
} 
void setUnion(mySetType A,mySetType B, mySetType &C)
{ //���ϵĲ������㣬ʵ�� C=A��B 
	int i,k,len,e; 
	InitLinkList(C); 
	k=0; //��ʼ���ռ��� C��k Ϊ C ���� 
	len=listLength(A); 
	for(i=1;i<=len; i++)
	{ //������ A ������Ԫ���ڼ��� C ��ͷ�˲��� 
		getElem(A,i,e); 
		listInsert(C,1,e); 
	} 
	len=listLength(B); //�󼯺� B �ĳ��� 
	for(i=1;i<=len;i++)
	{ //�� B �в����� A ��Ԫ�أ��� C ͷ�˲��� 
		getElem(B,i,e); 
		if(!locateElem(A,e)) //��Ԫ�� e ���� A �� 
		listInsert(C,1,e);//�� C ��ͷ�˲��� e 
	} 
} 
void setIntersection(mySetType &A,mySetType B) 
{ //���Ͻ������㣬ʵ�� A=A��B 
	int i,e,len; 
	len=listLength(A); 
	i=1;
	while(i<=len)
	{ 	getElem(A, i,e); //ȡ A �ĵ� i ��Ԫ�ظ� e 
		if(!locateElem(B,e)){//�� e ������ B 
			listDelete(A,i,e); //ɾ�� A �ĵ� i ��Ԫ�� 
			len--; //��ǰ A �ĳ����Ѽ� 1����һλ����Ϊ i 
		} 
		else i++; //��һԪ�ص�λ��Ϊ 
	}
} 
void outputSet(mySetType A)
{ //���ϵ�������� 
	printf("{"); 
	listTraverse(A,visitElem); 
	printf("}\n"); 
} 
int main()
{
	mySetType A,B,C;
	int n;
	printf("����  ����1 :\n");
	printf("\t����: ");
	scanf("%d", &n);
	creatSet(A,n);
	printf(" ����1=");
	outputSet(A);
	printf("����  ����2 :\n");
	printf("\t����: ");
	scanf("%d", &n);
	creatSet(B,n);
	printf(" ����2=");
	outputSet(B);
	InitLinkList(C);
	setUnion(A,B,C); 
	printf("\n ȫ������ = ����1 ������2 =");
	outputSet(C);
	setIntersection(A,B);
	printf(" �������� = ����1 ������2=");
	outputSet(A);
	return 0;
}
