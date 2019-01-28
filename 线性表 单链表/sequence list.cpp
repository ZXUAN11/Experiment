#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
typedef int LElemType;	 //����Ԫ������Ϊint����
#include "SqList.h"
typedef SqList mySetType;	 //���弯������
Status equal(LElemType e1,LElemType e2)
{
   	//Ԫ����ȹ�ϵ�ıȽϺ���
   	if(e1==e2) return TRUE;
   	else return FALSE;
}
void visitElem(LElemType e)
{
	//Ԫ�ط��ʲ���
   	printf("%d ",e);
}
void creatSet(mySetType &A, int n)
{
	//ͨ�������n��Ԫ�ش�������A
   	int i,e;
   	InitSqList(A, n+10);   
   	printf("\t����%d��������",n); 
   	for (i=0; i<n; i++)
   	{
      	scanf("%d", &e);
        listInsert(A,i+1,e);	//β�˲���Ԫ��
  	}
}
void setUnion(mySetType A,mySetType B,mySetType &C)
{
	//���ϵĲ������㣬ʵ��C=A��B
   	int i,k,len,e;
   	clearList(C);
	k=0; 	// C��գ���k����C�ĳ��� 
   	len=listLength(A); 
   	for(i=1; i<=len; i++)
   	{ 
   		//������A������Ԫ���ڼ���C��β�˲���
      	getElem(A,i,e); 
      	listInsert(C,++k,e);
   	}
   	len = listLength(B);//�󼯺�B�ĳ���
   	for(i=1;i<=len;i++)
   	{
      	//��B�в�����A��Ԫ����Cβ�˲���
      	getElem(B,i,e); //ȡB�ĵ�i��Ԫ�أ�����e
      	if(!locateElem(A,e)) 	//��Ԫ��e����A��
        	listInsert(C, ++k, e); 	//��C��β�˲���e
   }
}
void setIntersection(mySetType &A,mySetType B) 
{
	//���Ͻ������㣬ʵ��A=A��B
   	int i,e,len;
   	len=listLength(A);
	i=1; 
  	while(i<=len)
	{   
    	getElem(A, i, e);    //ȡA�ĵ�i��Ԫ�ظ�e
      	if(!locateElem(B,e)) 
		{ 
			//��e������B
          	listDelete(A,i,e);//ɾ��A�ĵ�i��Ԫ��
         	len--; 	//��ǰA�ĳ����Ѽ�1
                	//��һԪ��λ����Ϊi
      }
      else i++;//��һҪ����Ԫ�ص�λ��Ϊi+1
   }
}

void outputSet(mySetType A)
{
	//���ϵ��������
   	printf("{ ");
   	listTraverse(A,visitElem); 
   	printf("}\n");
}
int main()
{
	mySetType A,B,C;
	int n;
	printf("���� ����1 :\n");
	printf("\t����: ");
	scanf("%d", &n);
	creatSet(A,n);
	printf(" ����1=");
	outputSet(A);
	printf("���� ����2 :\n");
	printf("\t����: ");
	scanf("%d", &n);
	creatSet(B,n);
	printf(" ����2=");
	outputSet(B);
	InitSqList(C,listLength(A)+listLength(B)+10);
	setUnion(A,B,C); 
	printf("\nȫ������ = ����1 ������2 =");
	outputSet(C);
	setIntersection(A,B);
	printf("�������� = ����1 ������2=");
	outputSet(A);
	return 0;
}
