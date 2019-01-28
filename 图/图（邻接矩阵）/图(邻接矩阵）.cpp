#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"  
typedef char VertexType[20]; //顶点类型为字符数组类型
#include "MGraph.h"
Status equalVex(VertexType v1,VertexType v2)
{   //顶点元素的比较函数定义
    if(strcmp(v1,v2)==0) return TRUE;
    else return FALSE;
}
void inputVex (VertexType &v) //顶点信息输入函数定义
{   
	scanf("%s",v);
}
void visitVex(VertexType v)  //顶点访问函数定义
{   
	printf("%s  ",v);
}
void outputGraph(MGraph &G) 
{  //输出图的邻接矩阵表示的相关信息
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
{  //测试主函数
	MGraph G;
	createUDG(G);
	outputGraph(G);
	printf("\nDFS G:"); 
	//输出深度优先遍历序列
	DFSTraverse(G,visitVex);
	printf("\nBFS G:"); 
	//输出广度优先遍历序列
	BFSTraverse(G,visitVex);
	printf("\n"); 
	system("pause"); 
	return 0;
}

