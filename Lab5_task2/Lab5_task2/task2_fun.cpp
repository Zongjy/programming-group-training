/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	task2_fun.cpp
功能描述:
	功能函数模块，存放检查文件名、运行模式，生成html文件，显示结果等相关功能所需的函数
模块历史:
	李怡于2022年5月31日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "task2_data.h"
#include "task2_fun.h"

/*
* 函数名称：isalpha
* 函数功能：判断字符是否为英文字母(大小写均算)
* 输入参数：char: 待判定字符
* 返回值：bool: 如果是英文字母则返回true，否则返回false
*/
bool isalpha(char sum) {
	if ((sum <= 'z' && sum >= 'a') || (sum <= 'Z' && sum >= 'A')) return true;
	else return false;
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
* 函数功能：判断命令行参数中的运行模式是否正确,并存储正确的运行模式（0: 自动结果展示模式，1: 静默结果展示模式）
* 输入参数：char*: 待判定字符串（运行模式）
* 返回值：无
*/
void check_mode(char* mode) {
	int len = strlen(mode);
	if (len != 1 || (mode[0] != '0' && mode[0] != '1')) {
		printf("您输入的模式参数有误，程序退出\n");
		exit(EXIT_FAILURE);
	}
	//存取文件模式
	stac.mode = mode[0] - '0';
}

/*
* 函数名称：read_file
* 函数功能：读取统计结果文档的相关内容，将结果记入全局变量stac中
* 输入参数：无
* 返回值：无
*/
void read_file() {
	//先进行所有记录条数的初始化
	stac.blank = 0; stac.character = 0; stac.letter = 0; stac.num = 0; stac.others = 0; stac.word = 0;
	FILE* fp = fopen(stac.filename, "r");
	if (fp == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}
	//开始统计个数
	else {
		//按照英文文档中的英文单词、字符、数字、空白字符、英文字母和其他字符的个数
		fscanf_s(fp, "%d", &stac.word);
		fscanf_s(fp, "%d", &stac.character);
		fscanf_s(fp, "%d", &stac.num);
		fscanf_s(fp, "%d", &stac.blank);
		fscanf_s(fp, "%d", &stac.letter);
		fscanf_s(fp, "%d", &stac.others);
		fscanf_s(fp, "%d", &stac.paras);
	}
	fclose(fp);
}

/*
* 函数名称：write_file
* 函数功能：将统计结果按照html格式写入同目录下html文件夹中的同名html文件中
* 输入参数：无
* 返回值：无
*/
void write_file() {
	char* temp = strrchr(stac.filename, '/');
	char name[MAX_LEN] = { 0 };
	if (temp == NULL)
	{
		printf("统计文件路径错误，程序退出\n");
		exit(EXIT_FAILURE);
	}
	strcpy(name, temp + 1);
	strncpy(stac.htmlname, temp + 1, MAX_LEN - 4);
	//把txt文件的后缀变成html的文件
	int len = strlen(stac.htmlname);
	stac.htmlname[len - 3] = 'h', stac.htmlname[len - 2] = 't', stac.htmlname[len - 1] = 'm', stac.htmlname[len] = 'l', stac.htmlname[len + 1] = '\0';
	char path[MAX_LEN] = { 0 };
	//如果当前目录下没有html这个目录，就创建一个
	strcpy(path, "./html/");
	if (_access(path, 0)) {
		_mkdir(path);
	}
	strcat(path, stac.htmlname);
	FILE* fp = fopen(path, "w+");
	if (fp == NULL) {
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	//以html语法写入统计结果，并采用一定设计格式排版
	fprintf(fp, "<!DOCTYPE html>\n");
	fprintf(fp, "<html>\n<head>\n");
	fprintf(fp, "<title>第二组的统计结果</title>");
	fprintf(fp, "<link rel=\"icon\" href=\"https://s1.ax1x.com/2022/06/06/X0cgsg.jpg\">\n");
	fprintf(fp, "</head>\n<body>\n");
	fprintf(fp, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
	fprintf(fp, "<font color = red>您目前统计的文件名为:%s</font>\n", name);
	fprintf(fp, "<br>\n<hr/>\n");
	fprintf(fp, "<ul>");
	fprintf(fp, "<li>这篇文章的英文单词个数为:%d</li>\n", stac.word);
	fprintf(fp, "<br>\n<li><font color = blue>这篇文章的字符个数为:%d</font></li>\n", stac.character);
	fprintf(fp, "<br>\n<li>这篇文章的数字个数为:%d</li>\n", stac.num);
	fprintf(fp, "<br>\n<li><font color = blue>这篇文章的空白字符个数为:%d</font></li>\n", stac.blank);
	fprintf(fp, "<br>\n<li>这篇文章的英文字母个数为:%d</li>\n", stac.letter);
	fprintf(fp, "<br>\n<li><font color = blue>这篇文章的其他字符个数为:%d</font></li>\n", stac.others);
	fprintf(fp, "<br>\n<li>这篇文章的段落个数为:%d</li>\n", stac.paras);
	fprintf(fp, "</ul>");
	fprintf(fp, "</body>\n</html>\n");
	fclose(fp);
}

/*
* 函数名称：show
* 函数功能：根据运行模式在控制台终端打印相应的输出
* 输入参数：无
* 返回值：无
*/
void show() {
	//path表示绝对路径
	char path[MAX_LEN];
	_getcwd(path, MAX_LEN);
	strcat(path, "\\html\\");
	strcat(path, stac.htmlname);
	//将char*字符串转换为LPWSTR宽字节字符串，以便于作为后续windows.h库函数的参数调用
	int dwlen = strlen(path) + 1;
	//先计算对应转换后的宽字节字符串长度，并动态分配内存
	int nwlen = MultiByteToWideChar(CP_ACP, 0, path, dwlen, NULL, 0);
	LPWSTR lpszPath = (LPWSTR)malloc(nwlen * sizeof(WCHAR));
	MultiByteToWideChar(CP_ACP, 0, path, dwlen,lpszPath, nwlen);
	//未能成功转换时，程序退出
	if (lpszPath == 0)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	//如果是自动结果展示模式
	if (stac.mode==0) {
		//调用默认浏览器打开html文件
		HINSTANCE r = ShellExecute(NULL, TEXT("open"), lpszPath, NULL, NULL, SW_SHOWNORMAL);
		if ((DWORD)r <= 32)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	//如果是静默结果展示模式
	else {
		printf("已生成html文件\nhtml文件路径为：\033[1;32m%s\033[0m\n", path);
	}
}