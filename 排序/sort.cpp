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
      fscanf(fp, "%d%s%d",&stus[i].num,stus[i].name, &stus[i].score);
}
void OutputTable(stuType stus[], int n) {
//���n��ѧ����Ϣ
   int i;
   printf("******ѧ����Ϣ******\n"); 
   printf("%6s%12s%6s\n", "ѧ��","����","�ɼ�"); 
   for(i=1; i<=n; i++)
      printf("%6d%12s%6d\n",stus[i].num,stus[i].name, stus[i].score);
}
void ShellInsert(stuType stus[], int n, int d) {
//������d��һ��ϣ������
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
//����������dk=n/2, dk-1=dk/2,......,1��ϣ������ 
   int d;
   for(d=n/2; d>=1; d/=2)
        ShellInsert(stus,n,d) ;  
}
int partition(stuType stus[],int low, int high){
//��stus[low]Ϊ"����"�����ӱ�stus[low]~stus[high]
//����һ�˿�������,��������"����"������λ��
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
//��stus[low]~stus[high]��������,ʵ��low��high��Χ������
	int loc;
     if( low < high ){
           loc= partition( stus, low, high);
           QSort( stus, low, loc-1);
           QSort( stus, loc+1, high);
     }                                            
}
void heapAdjust(stuType stus[], int s, int m){
/*��֪stus[s]~stus[m]�г�stus[s]�Ĺؼ���֮�⣬������������ѵĶ��塣����stus[s]��ʹ��s��m��Χ��Ϊһ������� */
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
//������stus���ж�����
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
       printf("�ļ���ʧ��! \n");
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
