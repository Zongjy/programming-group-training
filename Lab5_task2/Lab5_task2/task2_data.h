#pragma once
#define MAX_LEN 1000
typedef struct statistics
{
	char filename[MAX_LEN];		//存储文件名
	char htmlname[MAX_LEN];		//html文件名
	int mode;					//此时的模式
	int word;					//英文单词
	int character;				//字符
	int num;					//数字
	int blank;					//空白字符
	int letter;					//英文字母
	int others;					//其他字符的个数
	int paras;					//段落个数
}STAC;
extern STAC stac;