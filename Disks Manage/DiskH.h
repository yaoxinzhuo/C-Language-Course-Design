#define	ROAD "C:\\Users\\Zhuo\\Desktop\\11_28_验收\\disks.txt"
#define LEN 20
#define NUM 100
//main
void list(void);//list显示选项界面信息 
int choice(int i);//对输入进行判断 
int read(int i);//打开文件,将里面的内容写到结构体数组disk中 
void write(int i);//将最后所有结果写回到文件中 
//查找和显示
void chazhao(int n);//寻找影碟 
void show(int n);
//help等其他文件
int cmpname( const void *a ,const void *b);//按名次排序比较 
int cmpheat( const void *a ,const void *b);//按热度排序比较 
int cmpmark( const void *a ,const void *b);//按分数排序比较 
int checklegal(int n);//判断输入是否合法 
int checkj(int n);//检查是否为1-3中排序方式一种 
int checkchar(char ch);
void makestd(char s[]);//自定义makestd函数名称标准化 
//借阅和归还
int jie(int n,int k);//借碟片的函数 
void guihuan(int n,int k);//还碟片 
int countday(int i);//计算天数 
int leap(int year);//计算闰年 
int dayth(int y,int m,int d);//计算第几天 
//添加删除 
void add(int n);//添加新的碟片 
int delet(int n);//删除碟片 

struct a //结构体a是影碟所有信息 
{
    char name[LEN];//影片的名字
    char nation[LEN];//制片的国家
    char type[LEN];//影片的种类
    
    int flag;//是否可借借阅的标志，1为可借，0为不可借
    int heat;//影片的热度，即借阅次数
    
	double mark;//用户对这部影片的评分
};
struct b 
{
    char memname[LEN];//影片的名字
    char disname[LEN];//会员的名字
    
	int botime[3];//借出的时间
    int retime[3];//归还的时间
    int money;//此次的租金
};
