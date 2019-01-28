#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{  int num;
   char name[20];
   int score;
} stuType;  //ѧ������
void CreatTable(stuType stus[], int n, FILE *fp) {
//����n��ѧ����Ϣ�ı�stus
   int i;
   for(i=1; i<=n; i++)
      fscanf(fp, "%d%s%d", &stus[i].num,stus[i].name, 
            &stus[i].score);
}
int SearchByName(stuType stus[], int n, char name[]){  
//����������˳�����
      int i;
	  for(i=1;i<=n;i++)
	  {
	  	if(!strcmp(stus[i].name,name))
	  	return i;
	  }
	  return 0;
	  	                                                                                    
}
int SearchByNum(stuType stus[], int n, int num) { 
//��ѧ�Ž���˳�����
		int i;
		for(i=1;i<=n;i++)
		{
			if(stus[i].num==num)
				return i;
		}
		return 0;
			                                                                                  
}
void menuPrint(){  //��ʾ�˵�
   printf("\t*****����*****\n");
   printf("\t1----��ѧ�Ų���\n");
   printf("\t2----����������\n");
   printf("\t0----�˳�\n");
   printf("\t��ѡ��");
}
int main()
{  stuType stus[40];
   int num;
   char name[20];
   int n, select, loc; 
   FILE *fp;
   if(!(fp=fopen("C:\\Users\\vonze\\Desktop\\studata.txt","r")) ) //���ļ�
   {    printf("�ļ���ʧ��! \n");
        system("pause");  return 0;  
   }
   fscanf(fp, "%d", &n);  //���ļ���ȡѧ������
   CreatTable(stus,n,fp);
   fclose(fp); //�ر��ļ�
   while(1)
   {  system("cls");
      menuPrint();
      scanf("%d",&select);
      {  if(select==1)
      {  printf("\t����ѧ�ţ�"); 
         scanf("%d",&num);
         loc=SearchByNum(stus,n,num); 
             //��ѧ��num����
         if(loc) printf("\t(%d,%s,%d)\n",stus[loc].num,
                    stus[loc].name,stus[loc].score);
         else printf("\t����ʧ��!����Ϣ������!\n");
         system("pause");
      }
      else if(select==2)
      {  printf("����������");
         scanf("%s", name);
         loc=SearchByName(stus,n,name);
             //������name����
         if(loc) printf("\t(%d,%s,%d)\n",stus[loc].num,
                    stus[loc].name,stus[loc].score);
         else printf("\t����ʧ��!����Ϣ������!\n");
         system("pause");
      }
      else if(select==0) break;
      else
      {   printf("\tѡ��������������\n");
          system("pause");
      }
   }
   return 0;
   }
}
/*int SearchByNum(stuType stus[], int n, int num) { 
//��ѧ�Ž����۰����
	int low=1,high=n,mid;
	  while(low<=high)
	  {
	  	mid=(low+high)/2;
	  	if(num==stus[mid].num) return mid;
	  	if(num<stus[mid].num) high=mid-1;
	  	else low=mid+1;
	  }  

}*/

