/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_call.cpp
功能描述:
	外部程序调用模块，存放调用实验4程序生成数据记录文件的函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_call.h"

/*
* 函数名称：call
* 函数功能：调用外部程序Lab3.exe，并根据实验四运行模式判断命令行参数值
* 输入参数：无
* 返回值：无
*/
void call()
{
	char command[777], makeFile[777];
	//判断运行模式
	switch (mconf.mode)
	{
	//自动模式时，dos命令字符串为外部程序文件名
	case automatic:
		sprintf(command, "Lab3.exe");
		break;
	//交互模式时，dos命令字符串为外部程序文件名和命令行参数，通过标准输入获取
	case interactive:
		printf("请输入记录条数：\n");
		scanf("%d", &dconf.num);
		printf("请输入数据文件存储路径(含文件名)：\n");
		scanf("%s", makeFile);
		sprintf(command, "Lab3.exe %d %s", dconf.num, makeFile);
		break;
	//其他情况打印错误提示信息并退出
	default:
		printf("模式错误！\n");
		exit(EXIT_FAILURE);
	}
	//使用system函数使用dos命令
	if (system(command) != 0)
	{
		printf("调用Lab3.exe失败！\n");
	}
}
