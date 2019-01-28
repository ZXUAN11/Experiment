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
      fscanf(fp, "%d%s%d",&stus[i].num,stus[i].name, &stus[i].score);
}
void OutputTable(stuType stus[], int n) {
//输出n个学生信息
   int i;
   printf("******学生信息******\n"); 
   printf("%6s%12s%6s\n", "学号","姓名","成绩"); 
   for(i=1; i<=n; i++)
      printf("%6d%12s%6d\n",stus[i].num,stus[i].name, stus[i].score);
}
void ShellInsert(stuType stus[], int n, int d) {
//按增量d的一趟希尔排序
	int i,j;
    for(i=d+1;i<=n;i++){
    	if(stus[i].score<stus[i-d].score){
        	stus[0]=stus[i];
        	for(j=i-d;j>0&&stus[0].score<stus[j].score;j-=d)
            	stus[j+d]=stus[j];
        	stus[j+d]=stus[0];
    	}    
	}                                           
} 
void ShellSort(stuType stus[], int n) {
//按增量序列dk=n/2, dk-1=dk/2,......,1的希尔排序 
   int d;
   for(d=n/2; d>=1; d/=2)
        ShellInsert(stus,n,d) ;  
}
int partition(stuType stus[],int low, int high){
//以stus[low]为"枢轴"，对子表stus[low]~stus[high]
//进行一趟快速排序,函数返回"枢轴"的最终位置
	stus[0] = stus[low];
	while(low<high){
		while(low<high&&stus[high].score>=stus[0].score)
			high--;
			stus[low] = stus[high];
		while(low<high&&stus[low].score<=stus[0].score)
			low++;
			stus[high] = stus[low];
     }
     stus[low] = stus[0];
     return low;                               
}
void QSort(stuType stus[],int low, int high){
//对stus[low]~stus[high]快速排序,实现low到high范围内有序
	int loc;
     if( low < high ){
           loc= partition( stus, low, high);
           QSort( stus, low, loc-1);
           QSort( stus, loc+1, high);
     }                                            
}
void heapAdjust(stuType stus[], int s, int m){
/*已知stus[s]~stus[m]中除stus[s]的关键字之外，其余均满足大根堆的定义。调整stus[s]，使得s到m范围成为一个大根堆 */
	int j;
     stus[0] = stus[s];
     for( j=2*s; j<=m; j*=2)
     {
           if(j<m && stus[j].score<stus[j+1].score)
              j++;
           if(stus[0].score>=stus[j].score)
              break;
           stus[s] = stus[j];
           s = j;
     }
     stus[s] = stus[0];                                         
}
void heapSort (stuType stus[], int n ){
//对数组stus进行堆排序。
     int i;
     for( i=n/2; i>=1; i--){
           heapAdjust ( stus, i, n);
     }
     for( i = n; i >1; i-- ) {
           stus[0]=stus[1]; stus[1]=stus[i]; stus[i]=stus[0];
           heapAdjust( stus, 1, i-1);
     }              
} 
int main()
{  stuType stus[40]; 
   int n;
   FILE *fp;
   if(!(fp=fopen("C:\\Users\\vonze\\Desktop\\studata.txt","r")) ){
       printf("文件打开失败! \n");
       system("pause");  return 0;  
   }
   fscanf(fp, "%d", &n);
   CreatTable(stus,n,fp); 
   fclose(fp);
   OutputTable(stus,n);
   system("pause");   
   ShellInsert(stus,n,1);  
   OutputTable(stus,n);
   system("pause");   
   return 0;
}
