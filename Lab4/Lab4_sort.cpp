/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_sort.cpp
功能描述:
	排序模块，存放数据排序相关功能所需的函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_sort.h"

/*
* 函数名称：cmp1
* 函数功能：作为qsort库函数内部调用的比较函数，实现二维数组第三列升序排列
* 返回值：正数代表升序排列，负数代表降序排列
*/
int cmp1(const void* _a, const void* _b)
{
	int* a = *(int**)_a;
	int* b = *(int**)_b;
	return a[2] - b[2];
}

/*
* 函数名称：cmp2
* 函数功能：作为qsort库函数内部调用的比较函数，实现结构体数组按成员item3升序排列
* 返回值：正数代表升序排列，负数代表降序排列
*/
int cmp2(const void* _a, const void* _b)
{
	dataItem* a = (dataItem*)_a;
	dataItem* b = (dataItem*)_b;
	return a->item3 - b->item3;
}

/*
* 函数名称：cmp3
* 函数功能：作为qsort库函数内部调用的比较函数，实现结构体指针数组按指向的结构体成员item3升序排列
* 返回值：正数代表升序排列，负数代表降序排列
*/
int cmp3(const void* _a, const void* _b)
{
	dataItem* a = *(dataItem**)_a;
	dataItem* b = *(dataItem**)_b;
	return a->item3 - b->item3;
}

/*
* 函数名称：bubbleSort
* 函数功能：实现链表按数据域中的结构体的成员item3升序排列（以冒泡排序为实现算法）
* 函数参数：node**：链表头指针地址
* 返回值：无
*/
void bubbleSort(node** head)
{
	node* p, * q, * rear;
	for (int i = 0; i < dataGroup - 1; i++)
	{
		q = (*head)->next;
		p = q->next;
		rear = *head;
		for (int j = 0; j < dataGroup - i - 1; j++)
		{
			if (q->value.item3 > p->value.item3)
			{
				q->next = p->next;
				p->next = q;
				rear->next = p;
			}
			rear = rear->next;
			q = rear->next;
			p = q->next;
		}
	}
	return;
}

/*
* 函数名称：part
* 函数功能：作为单链表快排的内部调用函数
*/
node* part(node* left, node* right)
{
	dataItem key = left->value;
	node* p = left;
	node* q = p->next;

	while (q != right)
	{
		if (q->value.item3 < key.item3)
		{
			p = p->next;
			dataItem temp = p->value;
			p->value = q->value;
			q->value = temp;
		}
		q = q->next;
	}
	dataItem temp = p->value;
	p->value = left->value;
	left->value = temp;
	return p;
}

/*
* 函数名称：quickSort
* 函数功能：实现链表按数据域中的结构体的成员item3升序排列（以双指针快速排序为实现算法）
* 函数参数：node*：链表头指针
			node*：链表尾指针
* 返回值：无
*/
void quickSort(node* head, node* tail)
{
	if (head != tail)
	{
		node* partion = part(head, tail);
		quickSort(head, partion);
		quickSort(partion->next, tail);
	}
}