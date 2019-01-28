typedef char VertexType[20];
typedef int QElemType; //定义队列元素类型
#include<stdio.h>
#include "CirQueue.h"
#define INFINITY 999      
#define MAX 20        
typedef enum{DG,DN,UDG,UDN} GraphKind;            
typedef struct{
   VertexType vexs[MAX];   
   int arcs[MAX][MAX];    
   int vexNum,arcNum;     
   GraphKind kind;         
}MGraph;  
Status equalVex(VertexType v1,VertexType v2); //顶点元素的比较函数声明
int locateVex(MGraph &G, VertexType v)
{ 	//基于邻接矩阵上实现顶点的查找操作
    int i;
	for(i=0; i<G.vexNum; i++)
	{
		if(equalVex(G.vexs[i],v))	return i;
	}       
	return -1;
}
void inputVex(VertexType &v); //顶点信息输入函数声明
void createUDG(MGraph &G)
{ 	//基于邻接矩阵存储结构创建无向图
	VertexType v1,v2;
	int i,j,k;   
	G.kind=UDG;
	printf("Input vertex number and edg number:");
	scanf("%d%d", &G.vexNum, &G.arcNum);  
	printf("Input vertexs:\n");
	for(i=0; i<G.vexNum; ++i) inputVex(G.vexs[i]);   
	for(i=0; i<G.vexNum; ++i) //邻接矩阵初始化
	  	for(j=0; j<G.vexNum; ++j)	G.arcs[i][j]=0;
	for(k=0; k<G.arcNum; ++k)
	{    
		printf("Input %dth edge:", k+1);
		printf("start vertexs:"); inputVex(v1);
		printf("end vertexs:"); inputVex(v2);
		if((i=locateVex(G,v1)) ==-1)
		{  
			printf("Error!\n"); 
			return;  
		}
		if((j=locateVex(G,v2))==-1)
	  	{
		    printf("Error!\n"); 
			return;  
		}
		G.arcs[i][j]=G.arcs[j][i]=1;   
	}  
}
int firstAdjVex(MGraph &G, int v)
{	//对于图G，求顶点v的第1个邻接顶点；
    int i;
	for(i=0; i<G.vexNum; i++)
	{
		if(G.arcs[v][i]==1)	return i;
	}
	return -1;
}
int nextAdjVex(MGraph G, int v, int w)
{ 	//求顶点v相对于"邻接顶点w",v的下一邻接顶点
	int i;
	for(i=w+1; i<G.vexNum; i++)
		if(G.arcs[v][i]==1)	return i;
	return -1;
}

int visited[MAX];  //顶点访问辅助数组
void DFS(MGraph &G, int v, void (*visit)(VertexType ))
{  	//从顶点v出发对图进行深度优先遍历
	int w;
	visit(G.vexs[v]);
	visited[v]=1;
	for(w=firstAdjVex(G,v); w>=0; w=nextAdjVex(G,v,w))
		if(!visited[w])	DFS(G,w,visit);
}
void DFSTraverse(MGraph &G, void (*visit)(VertexType)) 
{	//深度优先遍历图G 
	int v;
	for(v=0; v<G.vexNum; v++)	visited[v]=0;
	for(v=0; v<G.vexNum; v++)	if(!visited[v])	DFS(G,v,visit);
} 
void BFS(MGraph &G, int v, void (*visit)(VertexType))
{	//从顶点v出发对图进行广度优先遍历
    int u,w;
	CirQueue Q;
	InitCirQueue(Q,G.vexNum);
	visit(G.vexs[v]);
	visited[v]=1;
	insertQueue(Q,v);
	while(!queueIsEmpty(Q))
	{
		deleteQueue(Q,u);
		for(w=firstAdjVex(G,u);w>=0;w=nextAdjVex(G,u,w))
		{
			if(!visited[w])
			{
				visit(G.vexs[w]);
				visited[w]=1;
				insertQueue(Q,w);
			}
		} 
	}                   
}
void BFSTraverse(MGraph &G, void (*visit)(VertexType))
{   //广度优先遍历图 
	int v;
	for(v=0; v<G.vexNum; v++)	visited[v]=0;
	for(v=0; v<G.vexNum; v++)	if(!visited[v])	BFS(G,v,visit);                         
}

