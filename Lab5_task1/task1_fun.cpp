/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	task1_fun.cpp
功能描述:
	功能函数模块，存放检查文件名、运行模式，统计文档，显示结果等相关功能所需的函数
模块历史:
	李怡于2022年5月27日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "task1_data.h"
#include "task1_fun.h"

/*
* 函数名称：isalpha
* 函数功能：判断字符是否为英文字母(大小写均算)
* 输入参数：char: 待判定字符
* 返回值：bool: 如果是英文字母则返回true，否则返回false
*/
bool isalpha(char c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
		return true;
	else
		return false;
}

/*
* 函数名称：check_filename
* 函数功能：判断命令行参数中的文件名是否正确,并存储正确的文件名
* 输入参数：char*: 待判定字符串（文件名）
* 返回值：无
*/
void check_filename(char* path) {
	int flag = 1;
	if (_access(path, 0) != 0) flag = 0;
	if (flag == 0) {
		printf("输入路径不存在文件或文件错误，程序退出\n");
		exit(EXIT_FAILURE);
	}
	//存取文件名
	strcpy(stac.filename, path);
}

/*
* 函数名称：check_mode
* 函数功能：判断命令行参数中的运行模式是否正确,并存储正确的运行模式（0: 细节模式，1: 概要模式）
* 输入参数：char*: 待判定字符串（运行模式）
* 返回值：无
*/
void check_mode(char* p) {
	int sz = strlen(p);
	if (sz != 1 || (p[0] != '0' && p[0] != '1')) {
		printf("输入的模式参数有误，程序退出\n");
		exit(EXIT_FAILURE);
	}
	//存取文件模式
	stac.mode = p[0] - '0';
}

/*
* 函数名称：read_file
* 函数功能：读取英文文档的相关内容，并进行统计，将结果记入全局变量stac中
* 输入参数：无
* 返回值：无
*/
void read_file() {
	//所有记录数据初始化为0
	stac.character = 0, stac.blank = 0; stac.letter = 0; stac.num = 0; stac.others = 0; stac.word = 0, stac.paras = 0;
	FILE* fp = fopen(stac.filename, "r");
	if (fp == NULL) {
		printf("文件打开失败，程序退出\n");
		exit(EXIT_FAILURE);
	}
	//统计个数
	char ch = 'a', prech = 'b';
	while ((ch = fgetc(fp)) != EOF) 
	{
		if (ch!='\n')
			stac.character++;							//字符个数
		if (ch >= '0' && ch <= '9') stac.num++;			//数字个数
		else if (isalpha(ch)) stac.letter++;			//英文字母个数
		else if (ch == ' ' || ch == '\t') stac.blank++;	//空格个数
		else if (ch == '\n') stac.paras++;				//段落个数
		else stac.others++;								//其他字符个数(不含空格)
		//如果此时的字符不是英文字母，但是它的上一个是英文字母的情况即是一个英文单词(考虑所有格和连字符的情况)
		if (isalpha(ch) == false && isalpha(prech) == true && ch != '\'' && ch != '-') stac.word++;
		prech = ch;
		stac.paras++;
	}
	//如果最后的一个字母是英文字母，最后单词数需要加一
	if (isalpha(prech)) stac.word++;
	fclose(fp);
}

/*
* 函数名称：write_file
* 函数功能：将统计结果按照格式存放在同目录下result文件夹中的同名文本文件中
* 输入参数：无
* 返回值：无
*/
void write_file() {
	char temp[MAX_LEN] = { 0 };
	//检查当前目录下没有result这个目录，如果没有就创建一个
	strcpy(temp, "./result/");
	if (_access(temp, 0)) {
		int r = _mkdir(temp);
	}
	//加上统计结果文件标记前缀
	if (strrchr(stac.filename, '/')) {
		strcat(temp, strrchr(stac.filename, '/') + 1);
	}
	FILE* fp = fopen(temp, "w");
	if (fp == NULL) {
		printf("文件打开失败，程序退出\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	int t = fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", stac.word, stac.character, stac.num, stac.blank, stac.letter, stac.others, stac.paras);
	fclose(fp);
}

/*
* 函数名称：show
* 函数功能：根据运行模式在控制台终端打印相应的输出
* 输入参数：无
* 返回值：无
*/
void show() {
	 //细节模式
	if (stac.mode == 0)
	{
		printf("文章中的英文单词数量为：\033[1;36m%d\033[0m\n\
文章中的段落数量为：\033[1;36m%d\033[0m\n\
文章中的字符数量为：\033[1;36m%d\033[0m\n\
文章中的数字数量为：\033[1;36m%d\033[0m\n\
文章中的空白字符数量为：\033[1;36m%d\033[0m\n\
文章中的英文字母数量为：\033[1;36m%d\033[0m\n\
文章中的其他字符数量为：\033[1;36m%d\033[0m\n", stac.word, stac.paras, stac.character, stac.num, stac.blank, stac.letter, stac.others);
	}
	 //概要模式
	else 
	{
		//resource表示读取的文件名,target表示最终的文件路径
		char resource[MAX_LEN], target[MAX_LEN];
		//把读取的文件名存下来
		char* temp;
		if (strrchr(stac.filename, '/')) {
			temp = strrchr(stac.filename, '/');
		}
		else {
			temp = strrchr(stac.filename, '\\');
		}
		strcpy(resource, temp + 1);
		//把最终存放的位置的路径加文件名存下来
		char * a = _getcwd(target, MAX_LEN);
		strcat(target, "\\result\\");
		strcat(target, resource);
		printf("已完成%s文件的统计\n统计结果文件路径：\033[1;32m%s\033[0m\n", resource, target);
	}
}