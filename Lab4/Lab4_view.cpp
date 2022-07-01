/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_view.cpp
功能描述:
	数据显示模块，存放将存储在内存容器中的数据记录显示输出到屏幕上功能的相关函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_view.h"

/*
* 函数名称：view1
* 函数功能：打印二维数组的数据
* 输入参数：int** data：二维数组首地址
* 返回值：无
*/
void view1(int** data)
{
	printf("二维数组:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i][0], data[i][1], data[i][2]);
	}
}

/*
* 函数名称：view2
* 函数功能：打印结构体数组的数据
* 输入参数：dataItem* data：结构体数组首地址
* 返回值：无
*/
void view2(dataItem* data)
{
	printf("结构体数组:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i].item1, data[i].item2, data[i].item3);
	}
}

/*
* 函数名称：view3
* 函数功能：打印结构体指针数组的数据
* 输入参数：dataItem** data：结构体指针数组首地址
* 返回值：无
*/
void view3(dataItem** data)
{
	printf("结构体指针数组:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i]->item1, data[i]->item2, data[i]->item3);
	}
}

/*
* 函数名称：view4
* 函数功能：打印链表的数据域
* 输入参数：node* data：链表头指针
* 返回值：无
*/
void view4(node* head)
{
	printf("链表:\n");
	for (node* i = head->next; i != NULL; i = i->next)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", i->value.item1, i->value.item2, i->value.item3);
	}
}