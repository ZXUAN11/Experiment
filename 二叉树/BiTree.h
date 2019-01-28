#include<stdlib.h>
#include"Status.h" 
typedef char TElemType;
typedef struct BiTNode { 
   TElemType data;                 
   struct BiTNode *LChild, *RChild;   
}BiTNode, *BiTree; 
void inputTElem(TElemType &e); 
 //�����������ú�������Ԫ������
Status isEmptyElem(TElemType e); 
//���������������ж�e�Ƿ�Ϊ"����"������ֵ
void createBiTree(BiTree &T) {
//�������������������н���ֵ����������T
	TElemType e;
	inputTElem(e);//����Ԫ��e ����inputTElemΪ����Ԫ�ص����뺯��
	if(isEmptyElem(e))//�����ж�e�Ƿ�Ϊ"�������"������ֵ
		T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiTNode));//����һ���ռ�
		T->data=e;//���ɸ���� 
		createBiTree(T->LChild);//���򴴽������� 
		createBiTree(T->RChild);//���򴴽������� 
	} 
}
void PreOrderTraverse( BiTree T, void (*visit)(TElemType &e) ) {
   //�������������T�ĵݹ��㷨
	if(T)
	{
		visit(T->data); //���ʽ�� 
		PreOrderTraverse(T->LChild,visit); //���������� 
		PreOrderTraverse(T->RChild,visit);//���������� 
	}
}
void InOrderTraverse ( BiTree T, void (*visit)(TElemType &e) ) {
   //�������������T�ĵݹ��㷨
   if(T)
   {
   	InOrderTraverse(T->LChild,visit);
	visit(T->data);
	InOrderTraverse(T->RChild,visit);
   }
}
void PostOrderTraverse (BiTree T, void (*visit)(TElemType &e)) {
   //�������������T�ĵݹ��㷨
   if(T)
   {
   	PostOrderTraverse(T->LChild,visit);
	PostOrderTraverse(T->RChild,visit);
	visit(T->data);
   }	
}
int countLeaf(BiTree T){
   //ͳ�ƶ�����T��Ҷ�ӽ����Ŀ
	int countLeft,countRight;
	if(!T) return 0;
	if(T->LChild==NULL && T->RChild==NULL) return 1;//����ΪҶ�ӽ��
	countLeft=countLeaf(T->LChild);//����������Ҷ�ӽ������
	countRight=countLeaf(T->RChild);//����������Ҷ�ӽ������
	return countLeft+countRight;//�������е�Ҷ�ӽ������ 
	 
}
int depthBitree(BiTree T)
{
	//������������
	 int depthLeft, depthRight;
	 if(!T) return 0;//������
	 else
	 {
	 	depthLeft=depthBitree(T->LChild);//������������� 
	 	depthRight=depthBitree(T->RChild);//�������������
		if(depthLeft>=depthRight) return depthLeft+1;//������������Ƚϴ�
		else return depthRight+1; 
	  } 
}
