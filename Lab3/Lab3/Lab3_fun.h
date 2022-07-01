#pragma once
#include "pch.h"
#include "Lab3_data.h"

/*
* 名称: config_init
* 功能:	初始化配置信息(将conf.ini文件中的信息存储在结构体内)
* 参数: 无
* 返回值: 无
*/
void config_init();


/*
* 名称: menu
* 功能: 无命令行参数时，显示功能菜单
* 参数: 无
* 返回值: int: 参数mode的值(1:二维数组，2:结构体)
*/
int menu();



/*
* 名称: get_num
* 功能: 从标准输入流获取一个规定范围的整数
* 参数: 无
* 返回值: 位于规定范围的整数
*/
int get_num();


/*
* 名称: is_file_legal
* 功能: 判断文件名是否符合命名规则
* 参数: char*: 待判定字符串
* 返回值: bool: 合法返回true,否则返回false
*/
bool is_file_legal(char*);


/*
* 名称: ran_num
* 功能: 生成指定范围的随机数
* 参数:
		int: 数据最大值
		int: 数据最小值
* 返回值: int: 随机数据
*/
int ran_num (int, int);


/*
* 名称: write_file
* 功能: 通过配置信息设定的方式(二维数组或结构体)生成随机数据存入文本文件，并打印到屏幕上
* 参数:
		char*: 文件存储目录
		char*: 文件名
		int: 数据存储方式
* 返回值: 无
*/
void write_file(char*, char*,int);