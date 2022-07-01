#pragma once
//此头文件用于存储外部变量

#define MAX_LEN 1028
typedef struct statistics
{
	char filename1[MAX_LEN];  //需处理的英文文档的地址
	char filename2[MAX_LEN];//储存需处理的英文文档处理结果txt的地址
	char filename3[MAX_LEN];  //储存需处理的英文文档html结果的地址
	char dirname[MAX_LEN]; //待读取的含有一堆txt文件的目录名字
}STAC;
extern STAC stac;

extern FILE* fp;//储存汇总html的文件指针
extern int option;

