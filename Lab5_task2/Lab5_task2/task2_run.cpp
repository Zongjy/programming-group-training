/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	task2_run.cpp
功能描述:
	程序入口，调用run函数实现实验5子任务2全部功能
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "task2_data.h"
#include "task2_fun.h"
#include "task2_run.h"

STAC stac;		//全局变量定义

/*
* 函数名称：run
* 函数功能：检查传入的命令行参数是否规范，如果规范即执行编写html文件工作，否则退出程序
* 输入参数：int argc：命令行参数个数
			char* argv[]：命令行参数
* 返回值：int：无特殊意义
*/
void run(int argc, char* argv[]) {
	//命令行参数应共有三个，第一个是程序名，第二个是待读取统计结果文件名，第三个是运行模式
	if (argc != 3) {
		printf("您输入的参数个数有误，程序退出\n");
		exit(EXIT_FAILURE);
	}
	//参数个数正确时，检查文件名和模式是否合规，并存储于全局变量stac中
	else {
		check_filename(argv[1]);
		check_mode(argv[2]);
	}
	//读取统计结果文件内容
	read_file();
	//将文件读取结果写入html文件
	write_file();
	//在控制台终端显示运行模式对应的输出
	show();
}