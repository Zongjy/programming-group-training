/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_view.cpp
��������:
	������ʾģ�飬��Ž��洢���ڴ������е����ݼ�¼��ʾ�������Ļ�Ϲ��ܵ���غ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_view.h"

/*
* �������ƣ�view1
* �������ܣ���ӡ��ά���������
* ���������int** data����ά�����׵�ַ
* ����ֵ����
*/
void view1(int** data)
{
	printf("��ά����:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i][0], data[i][1], data[i][2]);
	}
}

/*
* �������ƣ�view2
* �������ܣ���ӡ�ṹ�����������
* ���������dataItem* data���ṹ�������׵�ַ
* ����ֵ����
*/
void view2(dataItem* data)
{
	printf("�ṹ������:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i].item1, data[i].item2, data[i].item3);
	}
}

/*
* �������ƣ�view3
* �������ܣ���ӡ�ṹ��ָ�����������
* ���������dataItem** data���ṹ��ָ�������׵�ַ
* ����ֵ����
*/
void view3(dataItem** data)
{
	printf("�ṹ��ָ������:\n");
	for (int i = 0; i < dataGroup; i++)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", data[i]->item1, data[i]->item2, data[i]->item3);
	}
}

/*
* �������ƣ�view4
* �������ܣ���ӡ�����������
* ���������node* data������ͷָ��
* ����ֵ����
*/
void view4(node* head)
{
	printf("����:\n");
	for (node* i = head->next; i != NULL; i = i->next)
	{
		printf("\033[1;32m%d,%d,%d\n\033[0m", i->value.item1, i->value.item2, i->value.item3);
	}
}