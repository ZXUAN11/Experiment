typedef char VertexType[20];
typedef int QElemType;  //定义队列元素类型
#include<stdio.h>
#include "CirQueue.h"
#define MAX 20
typedef enum{DG,DN,UDG,UDN} GraphKind;   
typedef struct ArcNode{  //表结点的类型
   	int adjvex;                 
   	int weight;  //网中的权值类型
   	struct ArcNode *nextarc;  
}ArcNode;    
typedef struct VNode{  //头结点的类型
   	VertexType data;
   	ArcNode *firstarc; 
}VNode;   
typedef struct{
   	VNode vertices[MAX]; 
   	int vexNum,arcNum; 
   	GraphKind kind;  
}ALGraph;
Status equalVex(VertexType v1,VertexType v2); //顶点元素的比较函数声明
int locateVex(ALGraph &G, VertexType v)
{ 	//基于邻接表存储结构实现顶点的查找操作 
	int i;
	for(i=0;i<G.vexNum; i++)
		if(equalVex(G.vertices[i].data,v))	return i;
	return -1; 
}
void inputVex(VertexType &v); //顶点信息输入函数声明
void createDG(ALGraph &G)
{	//基于邻接表存储结构上的有向图创建操作
	VertexType v1,v2;
	int i,j,k; 
	ArcNode *p;  
	G.kind=DG;
	printf("Input vertex number and arc number:");
	scanf("%d%d",&G.vexNum,&G.arcNum); 
	printf("Input vertexs:\n");
	for(i=0; i<G.vexNum; ++i)
	{	//输入图的顶点，并初始化邻接表  
		inputVex(G.vertices[i].data); 
		G.vertices[i].firstarc=NULL;  
	}
	for(k=0; k<G.arcNum; ++k)
	{ 
		printf("Input %dth edge:",k+1);  
		printf("start vertexs:"); 
		inputVex(v1);
		printf("end vertexs:"); 
		inputVex(v2);
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
		//生成表结点，并利用头插法插入到相应链表 
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p; 
	}
}
void findIndegree(ALGraph &G, int indegree[])
{	//求有向图G所有顶点的入度并存于数组indegree中
   	int i;
   	ArcNode *p;
   	for(i=0; i<G.vexNum; i++) //indegree数组初始化为0
      	indegree[i]=0;     
   	for(i=0; i<G.vexNum; i++)
	{
    	//遍历邻接表求所有顶点的入度值 
      	p=G.vertices[i].firstarc;
      	while(p)
		{   
         	indegree[p->adjvex]++;
         	p=p->nextarc;
      	}
   	}
}
void outputVex(VertexType v);  //顶点输出函数声明
void topologicalsort(ALGraph &G)
{	//有向图G的拓扑排序
   	int v, count=0, *indegree; //indegree为动态数组
   	ArcNode *p;
   	CirQueue Q;  //队列Q中保存入度为0的顶点
   	InitCirQueue(Q, G.vexNum); 
   	indegree=(int *)malloc(G.vexNum*sizeof(int));
    findIndegree(G,indegree);//求所有顶点的入度并存于indegree数组
   	for(v=0; v<G.vexNum; v++) //入度为0的顶点入队
      	if(indegree[v]==0)	insertQueue(Q,v);
   	while(!queueIsEmpty(Q))
	{ 
      	deleteQueue(Q, v);  //顶点v出队
      	outputVex(G.vertices[v].data); 
      	count++;   //已输出的顶点数增1
      	p=G.vertices[v].firstarc;
		while(p)
		{	//将顶点v的所有邻接顶点的入度值减1,若减1后为0则将其入队
			indegree[p->adjvex]--;
			if(indegree[p->adjvex]==0)	insertQueue(Q,p->adjvex);
			p=p->nextarc;
    	}
	}
   	if(count<G.vexNum) 
      	printf("\n该有向图中存在回路\n");
   	else printf("\n拓扑排序正确\n");
}

