#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h" 
extern  struct a disk[NUM];
extern  struct b rent[NUM];
//在下面写你的程序 
void add(int n)			//n为记录中已有的影片数
{
	getchar();
   
    printf("请输入碟片名字（单词之间请用_） (不超过20字符)：");
    gets(disk[n].name);
    
    makestd(disk[n].name);
    printf("请输入碟片产地：");
    gets(disk[n].nation);
    
    printf("请输入碟片类型：");
    gets(disk[n].type);
    
	disk[n].heat = 0;	//初始化借阅次数
    disk[n].flag = 1;	//初始化借阅情况
    disk[n].mark = 0;	//初始化用户评分
    
    printf("新的碟片已经插入成功!\n"); 
    
}
int delet(int n)			////n为记录中已有的影片数
{
    char name[100];
    int k,top,bot,i;

    puts("请输入要删除的影片名字：");
    getchar();
		gets(name);
		makestd(name);
    qsort(disk,n,sizeof(disk[0]),cmpname);		//对影片按名字进行排序
    top = n;
    bot = 0;
	while(top>=bot)	//用二分法搜索影片
	{
        i = (top+bot)/2;
        if(strcmp(name,disk[i].name)==0) 		//找到后，将排在后面的数据向前移一个单位
        {
			for(k=i;k<n-1;k++)
		    {
			    strcpy(disk[k].name,disk[k+1].name);
			    strcpy(disk[k].nation,disk[k+1].nation);
			    strcpy(disk[k].type,disk[k+1].type);
			    disk[k].flag = disk[k+1].flag;
			    disk[k].heat = disk[k+1].heat;
			    disk[k].mark = disk[k+1].mark;
		    }
		    printf("删除成功！\n");
		    return 1;
		}
        else if(strcmp(name,disk[i].name)<0)
        top = i-1;
        else bot = i+1;            
    }
	printf("无此影片\n");
    return 0;
}

