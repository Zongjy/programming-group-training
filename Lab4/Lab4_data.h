/***********************************************
作者信息：
    姓名：李怡
    学号：21281163
    班级：计算机2106班
模块名称:
    Lab4_data.h
功能描述:
    结构体及常量声明模块，存放实验4程序所需的结构体声明、常量声明及全局变量声明
模块历史:
    李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#pragma once
#define MAX_STR_LEN 256                         //文件名长度限制
enum modes { automatic = 0, interactive = 1 };  //运行模式列表

typedef struct DATAITEM
{
	int item1;
	int item2;
	int item3;
} dataItem;

typedef struct DATACONF{
    char fileSavePath[MAX_STR_LEN];             //用于存放数据记录文件的存储目录
    char fileName[MAX_STR_LEN];                 //用于存储数据记录文件的文件名信息
    int num;
    int maxValue1;      //用于存放实验3中生成的数据记录三元组中第1、2个元素取值的上限
    int minValue1;      //用于存放实验3中生成的数据记录三元组中第1、2个元素取值的下限
    int maxValue2;      //用于存放实验3中生成的数据记录三元组中第3个元素取值的上限
    int minValue2;      //用于存放实验3中生成的数据记录三元组中第3个元素取值的下限
    int recordCount1;   //用于存放数据记录文件需要随机生成记录条数时条数值的上限
    int recordCount2;   //用于存放数据记录文件需要随机生成记录条数时条数值的下限
} dataConf;

typedef struct MODECONF {
    char dataFilePath[MAX_STR_LEN];             //用于存放默认数据加载文件的存储目录
    char dataFileName[MAX_STR_LEN];             //用于存放默认数据加载文件的存储目录
    int mode;                                   //用于存放实验四运行模式
} modeConf;

typedef struct NODE {
    dataItem value;                             //链表数据域
    struct NODE *next;                          //链表指针域
} node;

//全局变量声明
extern dataConf dconf;                          //实验3配置文件结构体
extern modeConf mconf;                          //实验4配置文件结构体
extern char dataFile[];                         //数据文件名（含盘符、路径、文件名和扩展名）
extern int dataGroup;                           //数据文件中数据单元的组数