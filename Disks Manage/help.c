#include"DiskH.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern  struct a disk[NUM];//extern可置于函数前，以表示变量或者函数的定义在别的文件中
extern  struct b rent[NUM];
//在下面写你的程序 
#include<ctype.h>
int cmpname( const void *x ,const void *y)//按名称排序用到的, const限定一个变量不允许被改变,产生静态作用
{
	return  strcmp( (*(struct a *)x).name , (*(struct a *)y).name );// strcmp比较两个字符串大于返回正数小于返回负数
}
int cmpheat( const void *x ,const void *y)//按热度排序用到的 
{
	return (*(struct a*)x).heat<(*(struct a*)y).heat?1:-1;
}
int cmpmark( const void *x ,const void *y)//按评分排序用到的 
{
	return (*(struct a*)x).mark<(*(struct a*)y).mark?1:-1;
}
int checklegal(int n)//输入检查是否合法，不合法就一直等着让输入合法为止 
{
    if(n>0&&n<8)
	{
		return 0;
    }  
    else
    {
    	system("cls");//不合法就清空屏幕然后返回主菜单 
        printf("请重新输入一个1~6的数字：\n");
    	return 1;
	}
}
int checkj(int n)
{
    if(n>0&&n<4)
        return 0;
    else
        printf("请输入一个1~3的数字：\n");
    return 1;
}
int checkchar(char ch)//检查用户还想不想用 
{
    if(ch == 'q'||ch == 'c')
        return 0;
    else
	{
		system("cls"); 
        printf("请输入c继续或者q退出\n");
    }
    return 1;
}
void makestd(char s[])//自定义makestd函数名称标准化 
{
	int i,flag=1;
	
	for(i=0;s[i]!='\0';i++)
	{
		if(flag&&s[i]!='_')
		{
			s[i]=toupper(s[i]);//toupper函数将字符转换为大写英文字母 
			flag=0;
		}
		else s[i]=tolower(s[i]);//tolower 函数把字符转换成小写字母,非字母字符不做出处理
		if(s[i]=='_')
		flag=1;
	}
}
