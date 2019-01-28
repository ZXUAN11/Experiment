#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"
typedef char VertexType[20]; //��������Ϊ�ַ���������
#include "ALGraph.h"
Status equalVex(VertexType v1,VertexType v2)
{  //����Ԫ�صıȽϺ�������
   if(strcmp(v1,v2)==0) return TRUE;
   else return FALSE;
}
void inputVex (VertexType &v) 
{  //������Ϣ���뺯������
   scanf("%s",v);
}
void outputVex(VertexType v)  
{   //���������������
    printf("%s  ",v);
}

void outputALGraph(ALGraph &G){ //�ڽӱ�����
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
int main(){  //����������
   ALGraph G;
   createDG(G);  //��������ͼG
   outputALGraph(G);
   printf("�������У�");
   topologicalsort(G); //��G������������
   return 0;
}

