#include<stdlib.h>
#include"Status.h" 
typedef char TElemType;
typedef struct BiTNode { 
   TElemType data;                 
   struct BiTNode *LChild, *RChild;   
}BiTNode, *BiTree; 
void inputTElem(TElemType &e); 
 //函数声明；该函数用于元素输入
Status isEmptyElem(TElemType e); 
//函数声明；用于判断e是否为"空树"的特殊值
void createBiTree(BiTree &T) {
//依先序次序输入二叉树中结点的值创建二叉树T
	TElemType e;
	inputTElem(e);//读入元素e 其中inputTElem为树中元素的输入函数
	if(isEmptyElem(e))//用来判断e是否为"代表空树"的特殊值
		T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiTNode));//申请一结点空间
		T->data=e;//生成根结点 
		createBiTree(T->LChild);//先序创建左子树 
		createBiTree(T->RChild);//先序创建右子树 
	} 
}
void PreOrderTraverse( BiTree T, void (*visit)(TElemType &e) ) {
   //先序遍历二叉树T的递归算法
	if(T)
	{
		visit(T->data); //访问结点 
		PreOrderTraverse(T->LChild,visit); //遍历左子树 
		PreOrderTraverse(T->RChild,visit);//遍历右子树 
	}
}
void InOrderTraverse ( BiTree T, void (*visit)(TElemType &e) ) {
   //中序遍历二叉树T的递归算法
   if(T)
   {
   	InOrderTraverse(T->LChild,visit);
	visit(T->data);
	InOrderTraverse(T->RChild,visit);
   }
}
void PostOrderTraverse (BiTree T, void (*visit)(TElemType &e)) {
   //后序遍历二叉树T的递归算法
   if(T)
   {
   	PostOrderTraverse(T->LChild,visit);
	PostOrderTraverse(T->RChild,visit);
	visit(T->data);
   }	
}
int countLeaf(BiTree T){
   //统计二叉树T中叶子结点数目
	int countLeft,countRight;
	if(!T) return 0;
	if(T->LChild==NULL && T->RChild==NULL) return 1;//若根为叶子结点
	countLeft=countLeaf(T->LChild);//求左子树的叶子结点数量
	countRight=countLeaf(T->RChild);//求右子树的叶子结点数量
	return countLeft+countRight;//返回树中的叶子结点总数 
	 
}
int depthBitree(BiTree T)
{
	//求二叉树的深度
	 int depthLeft, depthRight;
	 if(!T) return 0;//若树空
	 else
	 {
	 	depthLeft=depthBitree(T->LChild);//求左子树的深度 
	 	depthRight=depthBitree(T->RChild);//求右子树的深度
		if(depthLeft>=depthRight) return depthLeft+1;//若左子树的深度较大
		else return depthRight+1; 
	  } 
}
