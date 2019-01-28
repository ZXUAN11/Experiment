#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{  int num;
   char name[20];
   int score;
} stuType;  //学生类型
void CreatTable(stuType stus[], int n, FILE *fp) {
//创建n个学生信息的表stus
   int i;
   for(i=1; i<=n; i++)
      fscanf(fp, "%d%s%d", &stus[i].num,stus[i].name, 
            &stus[i].score);
}
int SearchByName(stuType stus[], int n, char name[]){  
//按姓名进行顺序查找
      int i;
	  for(i=1;i<=n;i++)
	  {
	  	if(!strcmp(stus[i].name,name))
	  	return i;
	  }
	  return 0;
	  	                                                                                    
}
int SearchByNum(stuType stus[], int n, int num) { 
//按学号进行顺序查找
		int i;
		for(i=1;i<=n;i++)
		{
			if(stus[i].num==num)
				return i;
		}
		return 0;
			                                                                                  
}
void menuPrint(){  //显示菜单
   printf("\t*****查找*****\n");
   printf("\t1----按学号查找\n");
   printf("\t2----按姓名查找\n");
   printf("\t0----退出\n");
   printf("\t请选择：");
}
int main()
{  stuType stus[40];
   int num;
   char name[20];
   int n, select, loc; 
   FILE *fp;
   if(!(fp=fopen("C:\\Users\\vonze\\Desktop\\studata.txt","r")) ) //打开文件
   {    printf("文件打开失败! \n");
        system("pause");  return 0;  
   }
   fscanf(fp, "%d", &n);  //从文件读取学生人数
   CreatTable(stus,n,fp);
   fclose(fp); //关闭文件
   while(1)
   {  system("cls");
      menuPrint();
      scanf("%d",&select);
      {  if(select==1)
      {  printf("\t输入学号："); 
         scanf("%d",&num);
         loc=SearchByNum(stus,n,num); 
             //按学号num查找
         if(loc) printf("\t(%d,%s,%d)\n",stus[loc].num,
                    stus[loc].name,stus[loc].score);
         else printf("\t查找失败!该信息不存在!\n");
         system("pause");
      }
      else if(select==2)
      {  printf("输入姓名：");
         scanf("%s", name);
         loc=SearchByName(stus,n,name);
             //按姓名name查找
         if(loc) printf("\t(%d,%s,%d)\n",stus[loc].num,
                    stus[loc].name,stus[loc].score);
         else printf("\t查找失败!该信息不存在!\n");
         system("pause");
      }
      else if(select==0) break;
      else
      {   printf("\t选择有误，重新输入\n");
          system("pause");
      }
   }
   return 0;
   }
}
/*int SearchByNum(stuType stus[], int n, int num) { 
//按学号进行折半查找
	int low=1,high=n,mid;
	  while(low<=high)
	  {
	  	mid=(low+high)/2;
	  	if(num==stus[mid].num) return mid;
	  	if(num<stus[mid].num) high=mid-1;
	  	else low=mid+1;
	  }  

}*/

