typedef char VertexType[20];
typedef int QElemType;  //�������Ԫ������
#include<stdio.h>
#include "CirQueue.h"
#define MAX 20
typedef enum{DG,DN,UDG,UDN} GraphKind;   
typedef struct ArcNode{  //���������
   	int adjvex;                 
   	int weight;  //���е�Ȩֵ����
   	struct ArcNode *nextarc;  
}ArcNode;    
typedef struct VNode{  //ͷ��������
   	VertexType data;
   	ArcNode *firstarc; 
}VNode;   
typedef struct{
   	VNode vertices[MAX]; 
   	int vexNum,arcNum; 
   	GraphKind kind;  
}ALGraph;
Status equalVex(VertexType v1,VertexType v2); //����Ԫ�صıȽϺ�������
int locateVex(ALGraph &G, VertexType v)
{ 	//�����ڽӱ�洢�ṹʵ�ֶ���Ĳ��Ҳ��� 
	int i;
	for(i=0;i<G.vexNum; i++)
		if(equalVex(G.vertices[i].data,v))	return i;
	return -1; 
}
void inputVex(VertexType &v); //������Ϣ���뺯������
void createDG(ALGraph &G)
{	//�����ڽӱ�洢�ṹ�ϵ�����ͼ��������
	VertexType v1,v2;
	int i,j,k; 
	ArcNode *p;  
	G.kind=DG;
	printf("Input vertex number and arc number:");
	scanf("%d%d",&G.vexNum,&G.arcNum); 
	printf("Input vertexs:\n");
	for(i=0; i<G.vexNum; ++i)
	{	//����ͼ�Ķ��㣬����ʼ���ڽӱ�  
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
		//���ɱ��㣬������ͷ�巨���뵽��Ӧ���� 
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p; 
	}
}
void findIndegree(ALGraph &G, int indegree[])
{	//������ͼG���ж������Ȳ���������indegree��
   	int i;
   	ArcNode *p;
   	for(i=0; i<G.vexNum; i++) //indegree�����ʼ��Ϊ0
      	indegree[i]=0;     
   	for(i=0; i<G.vexNum; i++)
	{
    	//�����ڽӱ������ж�������ֵ 
      	p=G.vertices[i].firstarc;
      	while(p)
		{   
         	indegree[p->adjvex]++;
         	p=p->nextarc;
      	}
   	}
}
void outputVex(VertexType v);  //���������������
void topologicalsort(ALGraph &G)
{	//����ͼG����������
   	int v, count=0, *indegree; //indegreeΪ��̬����
   	ArcNode *p;
   	CirQueue Q;  //����Q�б������Ϊ0�Ķ���
   	InitCirQueue(Q, G.vexNum); 
   	indegree=(int *)malloc(G.vexNum*sizeof(int));
    findIndegree(G,indegree);//�����ж������Ȳ�����indegree����
   	for(v=0; v<G.vexNum; v++) //���Ϊ0�Ķ������
      	if(indegree[v]==0)	insertQueue(Q,v);
   	while(!queueIsEmpty(Q))
	{ 
      	deleteQueue(Q, v);  //����v����
      	outputVex(G.vertices[v].data); 
      	count++;   //������Ķ�������1
      	p=G.vertices[v].firstarc;
		while(p)
		{	//������v�������ڽӶ�������ֵ��1,����1��Ϊ0�������
			indegree[p->adjvex]--;
			if(indegree[p->adjvex]==0)	insertQueue(Q,p->adjvex);
			p=p->nextarc;
    	}
	}
   	if(count<G.vexNum) 
      	printf("\n������ͼ�д��ڻ�·\n");
   	else printf("\n����������ȷ\n");
}

