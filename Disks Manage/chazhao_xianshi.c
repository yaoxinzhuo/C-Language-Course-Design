#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//在下面开始写你的程序 
void chazhao(int n)
{
    char name[50];		//临时储存输入的影片名
    int i,flag1,flag2;//i用来预备使用， 
    int top,bot;//用于二分法 
    
    char ch;//用于下面的switch判断 
		getchar();
	
    printf("请输入您想查询碟片名称：");
    gets(name);
    
    start:makestd(name);//start是下面goto的到的地方 
    qsort(disk,n,sizeof(disk[0]),cmpname);		//将影片按名字排序,qsort是快速排序 
                                            /*qsort的详细说明：用 法： void qsort(void *base,int nelem,int width,int (*fcmp)(const void *,const void *));
                                            参数： 1 待排序数组首地址
                                                   2 数组中待排序元素数量
                                                   3 各元素的占用空间大小
                                                   4 指向函数的指针，用于确定排序的顺序 
                                            */
    
    top = n;//这两个变量用来下面的二分法查找 
    bot = 0;
    while(top>=bot)			//用二分法搜索影片，考虑到影片数据量可能较大。
    {
    	i = (top+bot)/2;
        if(strcmp(name,disk[i].name)==0)
        {
            if(disk[i].flag)
                printf("您想要的碟片存在\n");
            else
                printf("抱歉，您要的碟片不存在\n");
            return ;
        }
        else if(strcmp(name,disk[i].name)<0)
        top = i-1;
        else bot = i+1;
    }
    printf("抱歉，我们没有找到您想要借阅的碟片\n");
}//一半一半的来查询，是精确查找类型 



void show(int n)
{
	int i,count;
	char ch;

	do{
		system("cls"); 
		printf("请输入您想显示的顺序\n");
		printf("(1)按热度排序\t(2)按评分排序\n");
		printf("(3)按名字排序\n");
		scanf("%d",&i);
	}while(checkj(i));	//checkj函数不在这里。。 //检查是否为1-3中排序方式一种 (总头文件中可以找到 )			
	switch(i)									//按给定的方式排序
	{
		case 1:
			qsort(disk,n,sizeof(disk[0]),cmpheat);
			break;
		case 2:
			qsort(disk,n,sizeof(disk[0]),cmpmark);
			break;
		case 3:
			qsort(disk,n,sizeof(disk[0]),cmpname);
			break;
	}
	i=0;
	do{
		printf("名字\t\t 制片国     类型      借阅情况 热度 评分\n");
		for(count=0;count<5&&i<n;i++,count++)
		{
			printf("%-15s %-8s ",disk[i].name,disk[i].nation);
			printf("  %-10s    ",disk[i].type);
			if(disk[i].flag)printf("可借  ");
			else printf("不可借   ");
			printf("%-3d   %.1f",disk[i].heat,disk[i].mark);
			printf("\n");
		}					//一次打印五部电影
		if(i<n)
		{
			printf("输入c继续显示，输入q返回菜单\n");
			getchar();
			do{
				scanf(" %c",&ch);
			}while(checkchar(ch));
		}
	}while(ch == 'c'&&i<n);
}

