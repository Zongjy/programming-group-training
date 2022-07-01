/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_loadfile.cpp
功能描述:
	数据加载模块，存放数据读取、数据加载相关功能所需的函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_data.h"
#include "Lab4_loadfile.h"

/*
* 函数名称：loadfileInit
* 函数功能：根据运行模式初始化读取文件名，并判断该数据文件是否能正常访问
* 输入参数：无
* 返回值：无
*/
void loadfileInit()
{
	switch (mconf.mode)
	{
	case automatic:
		break;
	case interactive:
		printf("请输入待读取文件的路径：\n");
		scanf_s("%s", mconf.dataFilePath, MAX_STR_LEN);
		printf("请输入待读取文件的文件名（含后缀名）：\n");
		scanf_s("%s", mconf.dataFileName, MAX_STR_LEN);
		break;
	default:
		printf("模式错误！\n");
		exit(EXIT_FAILURE);
	}
	strcpy(dataFile, mconf.dataFilePath);
	strcat(dataFile, mconf.dataFileName);
	if (_access(dataFile, 0) != 0)
	{
		printf("数据文件错误！");
		exit(EXIT_FAILURE);
	}
}

/*
* 函数名称：loadfile1
* 函数功能：读取数据文件，并以二维数组形式存储数据
* 输入参数：无
* 返回值：int**：二维数组首地址
*/
int** loadfile1()
{
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("数据文件读取失败！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		int** data = (int**)malloc(dataGroup * sizeof(int*));
		if (data == NULL)
			perror("内存分配错误");
		else
		{
			for (int i = 0; i < dataGroup; i++)
			{
				data[i] = (int*)malloc(3 * sizeof(int));
				if (data[i] == NULL)
					perror("内存分配错误");
				else
				{
					res = fscanf(fp_data, "%d,%d,%d", &data[i][0], &data[i][1], &data[i][2]);
				}
			}
		}
		fclose(fp_data);
		return data;
	}
}

/*
* 函数名称：loadfile2
* 函数功能：读取数据文件，并以结构体数组形式存储数据
* 输入参数：无
* 返回值：dataItem*：结构体数组首地址
*/
dataItem* loadfile2()
{
	/*结构体数组*/
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("数据文件读取失败！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		dataItem* data = (dataItem*)malloc(dataGroup * sizeof(dataItem));
		if (data == NULL)
			perror("内存分配错误");
		else
		{
			for (int i = 0; i < dataGroup; i++)
			{
				res = fscanf(fp_data, "%d,%d,%d", &data[i].item1, &data[i].item2, &data[i].item3);
			}
		}
		fclose(fp_data);
		return data;
	}
}

/*
* 函数名称：loadfile3
* 函数功能：读取数据文件，并以结构体指针数组形式存储数据
* 输入参数：无
* 返回值：dataItem**：结构体指针数组首地址
*/
dataItem** loadfile3()
{
	/*指针数组*/
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("数据文件读取失败！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		dataItem** data = (dataItem**)malloc(dataGroup * sizeof(dataItem*));
		if (data == NULL)
			perror("内存分配错误");
		else
		{
			for (int i = 0; i < dataGroup; i++)
			{
				data[i] = (dataItem*)malloc(sizeof(dataItem));
				if (data[i] == NULL)
					perror("内存分配错误");
				res = fscanf(fp_data, "%d,%d,%d", &data[i]->item1, &data[i]->item2, &data[i]->item3);
			}
		}
		fclose(fp_data);
		return data;
	}
}

/*
* 函数名称：loadfile4
* 函数功能：读取数据文件，并以链表形式存储数据
* 输入参数：无
* 返回值：node*：链表头指针地址
*/
node* loadfile4()
{
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("数据文件读取失败！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		node* head = (node*)malloc(sizeof(node));
		if (head == NULL)
		{
			perror("内存分配错误");
			exit(EXIT_FAILURE);
		}
		node* rear = head;
		for (int i = 0; i < dataGroup; i++)
		{
			node* temp = (node*)malloc(sizeof(node));
			if (temp == NULL)
			{
				perror("内存分配错误");
				exit(EXIT_FAILURE);
			}
			res = fscanf(fp_data, "%d,%d,%d", &temp->value.item1, &temp->value.item2, &temp->value.item3);
			temp->next = NULL;
			rear->next = temp;
			rear = rear->next;
		}
		return head;
	}
}
