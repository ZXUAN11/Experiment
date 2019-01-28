#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"
typedef char VertexType[20]; //顶点类型为字符数组类型
#include "ALGraph.h"
Status equalVex(VertexType v1,VertexType v2)
{  //顶点元素的比较函数定义
   if(strcmp(v1,v2)==0) return TRUE;
   else return FALSE;
}
void inputVex (VertexType &v) 
{  //顶点信息输入函数定义
   scanf("%s",v);
}
void outputVex(VertexType v)  
{   //顶点输出函数定义
    printf("%s  ",v);
}

void outputALGraph(ALGraph &G){ //邻接表的输出
   int i;
   ArcNode *p;
   switch(G.kind){
      case  DG: printf("\nG.kind:DG\n"); break;
      case  DN: printf("\nG.kind:DN\n"); break;
      case  UDG: printf("\nG.kind:UDG\n"); break;
      case  UDN: printf("\nG.kind:UDN\n"); 
   }
   for(i=0;i<G.vexNum;i++)
    {   printf("(%d)%s: ",i,G.vertices[i].data);
        p=G.vertices[i].firstarc;
        while(p) { 
           printf("--->%3d",p->adjvex);
           p=p->nextarc; 
        }
        printf("\n");
    }
}
int main(){  //测试主函数
   ALGraph G;
   createDG(G);  //创建有向图G
   outputALGraph(G);
   printf("拓扑序列：");
   topologicalsort(G); //对G进行拓扑排序
   return 0;
}

