#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//在下面写你的程序 
int jie(int n,int k)		//n为记录中已有的影片数
//k为记录中借阅信息的数目
{
    int i,j,m;
    int bot,top;

	getchar();
    printf("请输入想要借阅的影片数：\n");
    scanf("%d",&m);
    
    getchar();
    
    for(j=0;j<m;j++)
    {
        printf("请输入会员名：");
        gets(rent[k].memname);
        printf("请输入影片名称（用_分割每个单词）：");
        gets(rent[k].disname);
        makestd(rent[k].disname);
        printf("请输入今天的日期：\n");
        printf("(例如2015-11-28)\n");
        scanf("%d-%d-%d",&rent[k].botime[0],&rent[k].botime[1],&rent[k].botime[2]);
        getchar();
        
        bot = 0;
        top = n;
        qsort(disk,n,sizeof(disk[0]),cmpname);		//将影片按名字排序
        
        while(top>=bot)		//二分查找影片
        {
        	i = (top+bot)/2;
            if(strcmp(rent[k].disname,disk[i].name)==0)		//找到影片后改变标记并计数
            {
                disk[i].flag = 0;
                disk[i].heat++;
                break;
            }
        	else if(strcmp(rent[k].disname,disk[i].name)<0)
	        top = i-1;
	        else bot = i +1;
    	}
    	k++;
    }
    printf("成功借阅!\n");
    return k; 
}

void guihuan(int n,int k)		//n为记录中已有的影片数
//k为记录中借阅信息的数目
{
    int i,j,m,sum=0,day;
    char mname[20],dname[20];		//临时储存输入的会员名和影片名 
    double mark;
    int top,bot;

	getchar();
    printf("请输入会员名:");
    gets(mname);
    printf("请输入您想归还影片的数量:");
    scanf("%d",&m);
    getchar();
    for(j=0;j<m;j++)
    {
        printf("请输入影片名称（用_分割每个单词）:");
        gets(dname);
        top = n;
        bot = 0;
        qsort(disk,n,sizeof(disk[0]),cmpname);		//将影片按名字排序
        while(top>=bot)
        {
        	i = (top+bot)/2;
            if(strcmp(dname,disk[i].name)==0)	//找到影片并改变借阅情况
            {
                disk[i].flag = 1;
                break;
            }
        	else if(strcmp(dname,disk[i].name)<0)
 			top = i-1;
        	else bot = i+1;
        }		
        printf("请输入您的评分(0-10):");
        scanf("%lf",&mark);
		while(mark<0||mark>10)
		{
			printf("请在0-10区间评分！");
			printf("请输入您的评分（0-10）:");
			scanf("%lf",&mark);
		}
        disk[i].mark = (disk[i].mark*disk[i].heat+mark)/(disk[i].heat+1);		//计算平均评分 
        qsort(rent,k,sizeof(rent[0]),cmpname);		//将影片按名字排序
        bot=0;
        top=k;
        while(top>=bot)		//找到该影片在rent中的下标 
        {
        	i = (top+bot)/2;
            if(strcmp(dname,rent[i].disname)==0)
            break;
            else if(strcmp(dname,rent[i].disname)<0)
        	top = i-1;
        	else bot = i+1;
        }			
        printf("请输入今天的日期：\n");
        printf("(例如2015-11-28)\n");
        scanf("%d-%d-%d",&rent[i].retime[0],&rent[i].retime[1],&rent[i].retime[2]);
        day = countday(i);		
        sum=day;//统计应付租金，每天一元
		if(sum>60)
		{
			sum=(sum-60)*3+60;//超过部分两个月以后每天三元
		}
    }
    printf("此次您要支付%d元",sum);
}


int countday(int i)			//i为影片在rent中对应的下标
{
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalday=0;
    int by,bm,bd;		//对应借阅时候的年月日
int ry,rm,rd;		//对应归还时候的年月日

    by = rent[i].botime[0];
    bm = rent[i].botime[1];
    bd = rent[i].botime[2];
    ry = rent[i].retime[0];
    rm = rent[i].retime[1];
    rd = rent[i].retime[2];

    if(by<ry)		//借阅的时间跨过了一年的情况
    {
		totalday+=(365-dayth(by,bm,bd));
	    by++;		//先将借出的那一年的日子全算上
	    while(by<ry)
	    {
	        totalday += 365+leap(by);
 	       by++;
    	}			//算到归还的当年第一天
    	totalday+=dayth(ry,rm,rd);		// 算到归还当天
	}
	else	 totalday = dayth(ry,rm,rd) - dayth(by,bm,bd); 	//借阅时间未跨过一年的情况
    return totalday;
}

int dayth(int y,int m,int d)		//
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,day=0;

    month[1]+=leap(y);
    for(i=0;i<m-1;i++)
    	day+=month[i];
    day+=d;
    return day;
}
int leap(int year)
{
    if((year%4==0&&year%100!=0)||year%400==0)
    {
    	return 1;
	}
	else
	{
		return 0;
	}
}
