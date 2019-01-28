#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"  
typedef char VertexType[20]; //��������Ϊ�ַ���������
#include "MGraph.h"
Status equalVex(VertexType v1,VertexType v2)
{   //����Ԫ�صıȽϺ�������
    if(strcmp(v1,v2)==0) return TRUE;
    else return FALSE;
}
void inputVex (VertexType &v) //������Ϣ���뺯������
{   
	scanf("%s",v);
}
void visitVex(VertexType v)  //������ʺ�������
{   
	printf("%s  ",v);
}
void outputGraph(MGraph &G) 
{  //���ͼ���ڽӾ����ʾ�������Ϣ
   	int i,j;
   	switch(G.kind)
	{
    case  DG: printf("\nG.kind:DG\n"); break;
	case  DN: printf("\nG.kind:DN\n"); break;
    case  UDG: printf("\nG.kind:UDG\n"); break;
    case  UDN: printf("\nG.kind:UDN\n"); 
   	}
   	printf("\t");
   	for(i=0;i<G.vexNum;++i)  printf("%6s",G.vexs[i]);
   	printf("\n");
   	for(i=0;i<G.vexNum;++i)
   	{  
	   	printf("%s\t",G.vexs[i]);
      	for(j=0;j<G.vexNum;++j) 
         	printf("%6d",G.arcs[i][j]);
      	printf("\n");
   	}
}

int main()
{  //����������
	MGraph G;
	createUDG(G);
	outputGraph(G);
	printf("\nDFS G:"); 
	//���������ȱ�������
	DFSTraverse(G,visitVex);
	printf("\nBFS G:"); 
	//���������ȱ�������
	BFSTraverse(G,visitVex);
	printf("\n"); 
	system("pause"); 
	return 0;
}

