#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
typedef char TElemType;
#include "BiTree.h"
void visit(TElemType &e){//元素访问函数
   printf("%c", e);
}
void inputTElem(TElemType &e){
   //该函数用于元素输入
    scanf("%c", &e);
}
Status isEmptyElem(TElemType e){
   //用于判断e是否为"空树"的特殊值
   if(e=='#') return TRUE;
   else return FALSE;
}
int main(){//测试主函数
   //先创建一棵二叉树并对基本操作进行验证
   BiTree T;
   printf("输入字符序列创建二叉树T:\n");
   createBiTree(T);   //创建二叉树
   printf("二叉树T的先序序列为："); 
   PreOrderTraverse(T,visit); //先序遍历
   printf("\n");  
   printf("二叉树T的中序序列为："); 
   InOrderTraverse(T,visit); //中序遍历
   printf("\n");
   printf("二叉树T的后序序列为："); 
   PostOrderTraverse(T,visit); //后序遍历
   printf("\n");
   int count=countLeaf(T);  //求叶子结点数
   printf("叶子结点数=%d\n",count);
   int d=depthBitree(T);  //求深度
   printf("深度=%d\n",d);
   system("pause");
   return 0;
}
