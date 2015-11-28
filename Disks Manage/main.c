/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DiskH.h"

struct a disk[NUM];
struct b rent[NUM];

int main()
{
    int i=0;
    char ch;

    printf("           C语言程序设计课程设计——影碟信息管理系统\n");
    printf("           卓遥信 卢陈侃 任梦媛 庄颖 赵云鹤 联合创作\n");
	printf("                   输入回车后开始运行程序:\n");
	getchar();
	 
	i = read(i);
	if(i==-2)
	{
		return 0;
	}
	
	i = choice(i);
    
	printf("程序结束!\n");
    
    write(i);//程序结束前将所有东西再按顺序写回文件 
    return 0;
}

void list(void)
{
	system("cls");
    printf("**********************************************************\n");
    printf("                  请选择您要使用的功能(输入1~6)\n");
    printf("                  (1)查询现有影碟\n");
	printf("                  (2)插入新的影碟\n");
	printf("                  (3)  借阅影碟  \n");
	printf("                  (4)  归还影碟  \n");
	printf("                  (5)输出所有影碟\n");
	printf("                  (6)删除一个影碟\n");
	printf("                  (7)  退出程序\n"); 
    printf("**********************************************************\n");
}

int choice(int i)
{
	int m,k=0;
	char ch;

	do//当用户没有输入q退出的时候 
    {
    	
        do
        {
            list();
            scanf("%d",&m);
        }
        while(checklegal(m));			//输入检查
        
        switch(m)				//功能选择
        {
        case 1:
        	chazhao(i);
            break;
        case 2:
            add(i++);
            break;
        case 3:
            k=jie(i,k);
            break;
        case 4:
            guihuan(i,k);
            break;
		case 5:
			show(i);
			break;
		case 6:
			i-=delet(i);
		case 7:
			return 0;
        }
        
        printf("若想继续使用本程序，请输入c，否则输入q退出:\n");
        do
        {
            scanf(" %c",&ch);
        }
        while(checkchar(ch));		//输入检查
    }
    while(ch != 'q');
    return i;
}

int read(int i)
{
	int n;
	FILE *fp;
	fp =fopen(ROAD,"r");
	
	if(fp==NULL)
	{
		puts("文件打开失败，请确认文件路径。");
		return -2;//如果打不开就返回个-2吧，让它结束掉 
	}
	
	while(!feof(fp))
	{
			n = fscanf(fp,"%s %s %s %d %d %lf",disk[i].name,disk[i].nation,disk[i].type,&disk[i].flag,&disk[i].heat,&disk[i].mark);
			if(n<0)//如果读完失败了则返回-1，条件成立就break
			{ 
				break;
			}
			i++;
	}
	qsort(disk,i,sizeof(disk[0]),cmpname);		//按影片名字排序
	fclose(fp);
	return i;
}

void write(int i)
{
    int k=0;
    FILE *fp;

    fp =fopen(ROAD,"w");
    qsort(disk,i,sizeof(disk[0]),cmpname);			//按影片名字排序
	while(k<i)
	{
			fprintf(fp,"%-20s%-8s",disk[k].name,disk[k].nation);
			fprintf(fp,"%-10s%-2d",disk[k].type,disk[k].flag);
			fprintf(fp,"%-4d%.1lf\n",disk[k].heat,disk[k].mark);
			k++;
	}
	fclose(fp);
}

