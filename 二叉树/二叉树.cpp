#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
typedef char TElemType;
#include "BiTree.h"
void visit(TElemType &e){//Ԫ�ط��ʺ���
   printf("%c", e);
}
void inputTElem(TElemType &e){
   //�ú�������Ԫ������
    scanf("%c", &e);
}
Status isEmptyElem(TElemType e){
   //�����ж�e�Ƿ�Ϊ"����"������ֵ
   if(e=='#') return TRUE;
   else return FALSE;
}
int main(){//����������
   //�ȴ���һ�ö��������Ի�������������֤
   BiTree T;
   printf("�����ַ����д���������T:\n");
   createBiTree(T);   //����������
   printf("������T����������Ϊ��"); 
   PreOrderTraverse(T,visit); //�������
   printf("\n");  
   printf("������T����������Ϊ��"); 
   InOrderTraverse(T,visit); //�������
   printf("\n");
   printf("������T�ĺ�������Ϊ��"); 
   PostOrderTraverse(T,visit); //�������
   printf("\n");
   int count=countLeaf(T);  //��Ҷ�ӽ����
   printf("Ҷ�ӽ����=%d\n",count);
   int d=depthBitree(T);  //�����
   printf("���=%d\n",d);
   system("pause");
   return 0;
}
