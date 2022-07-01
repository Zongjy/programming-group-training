/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_sort.cpp
��������:
	����ģ�飬�������������ع�������ĺ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_sort.h"

/*
* �������ƣ�cmp1
* �������ܣ���Ϊqsort�⺯���ڲ����õıȽϺ�����ʵ�ֶ�ά�����������������
* ����ֵ�����������������У���������������
*/
int cmp1(const void* _a, const void* _b)
{
	int* a = *(int**)_a;
	int* b = *(int**)_b;
	return a[2] - b[2];
}

/*
* �������ƣ�cmp2
* �������ܣ���Ϊqsort�⺯���ڲ����õıȽϺ�����ʵ�ֽṹ�����鰴��Աitem3��������
* ����ֵ�����������������У���������������
*/
int cmp2(const void* _a, const void* _b)
{
	dataItem* a = (dataItem*)_a;
	dataItem* b = (dataItem*)_b;
	return a->item3 - b->item3;
}

/*
* �������ƣ�cmp3
* �������ܣ���Ϊqsort�⺯���ڲ����õıȽϺ�����ʵ�ֽṹ��ָ�����鰴ָ��Ľṹ���Աitem3��������
* ����ֵ�����������������У���������������
*/
int cmp3(const void* _a, const void* _b)
{
	dataItem* a = *(dataItem**)_a;
	dataItem* b = *(dataItem**)_b;
	return a->item3 - b->item3;
}

/*
* �������ƣ�bubbleSort
* �������ܣ�ʵ�������������еĽṹ��ĳ�Աitem3�������У���ð������Ϊʵ���㷨��
* ����������node**������ͷָ���ַ
* ����ֵ����
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
* �������ƣ�part
* �������ܣ���Ϊ��������ŵ��ڲ����ú���
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
* �������ƣ�quickSort
* �������ܣ�ʵ�������������еĽṹ��ĳ�Աitem3�������У���˫ָ���������Ϊʵ���㷨��
* ����������node*������ͷָ��
			node*������βָ��
* ����ֵ����
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