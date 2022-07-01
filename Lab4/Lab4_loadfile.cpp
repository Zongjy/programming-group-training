/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_loadfile.cpp
��������:
	���ݼ���ģ�飬������ݶ�ȡ�����ݼ�����ع�������ĺ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_data.h"
#include "Lab4_loadfile.h"

/*
* �������ƣ�loadfileInit
* �������ܣ���������ģʽ��ʼ����ȡ�ļ��������жϸ������ļ��Ƿ�����������
* �����������
* ����ֵ����
*/
void loadfileInit()
{
	switch (mconf.mode)
	{
	case automatic:
		break;
	case interactive:
		printf("���������ȡ�ļ���·����\n");
		scanf_s("%s", mconf.dataFilePath, MAX_STR_LEN);
		printf("���������ȡ�ļ����ļ���������׺������\n");
		scanf_s("%s", mconf.dataFileName, MAX_STR_LEN);
		break;
	default:
		printf("ģʽ����\n");
		exit(EXIT_FAILURE);
	}
	strcpy(dataFile, mconf.dataFilePath);
	strcat(dataFile, mconf.dataFileName);
	if (_access(dataFile, 0) != 0)
	{
		printf("�����ļ�����");
		exit(EXIT_FAILURE);
	}
}

/*
* �������ƣ�loadfile1
* �������ܣ���ȡ�����ļ������Զ�ά������ʽ�洢����
* �����������
* ����ֵ��int**����ά�����׵�ַ
*/
int** loadfile1()
{
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("�����ļ���ȡʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		int** data = (int**)malloc(dataGroup * sizeof(int*));
		if (data == NULL)
			perror("�ڴ�������");
		else
		{
			for (int i = 0; i < dataGroup; i++)
			{
				data[i] = (int*)malloc(3 * sizeof(int));
				if (data[i] == NULL)
					perror("�ڴ�������");
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
* �������ƣ�loadfile2
* �������ܣ���ȡ�����ļ������Խṹ��������ʽ�洢����
* �����������
* ����ֵ��dataItem*���ṹ�������׵�ַ
*/
dataItem* loadfile2()
{
	/*�ṹ������*/
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("�����ļ���ȡʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		dataItem* data = (dataItem*)malloc(dataGroup * sizeof(dataItem));
		if (data == NULL)
			perror("�ڴ�������");
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
* �������ƣ�loadfile3
* �������ܣ���ȡ�����ļ������Խṹ��ָ��������ʽ�洢����
* �����������
* ����ֵ��dataItem**���ṹ��ָ�������׵�ַ
*/
dataItem** loadfile3()
{
	/*ָ������*/
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("�����ļ���ȡʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		dataItem** data = (dataItem**)malloc(dataGroup * sizeof(dataItem*));
		if (data == NULL)
			perror("�ڴ�������");
		else
		{
			for (int i = 0; i < dataGroup; i++)
			{
				data[i] = (dataItem*)malloc(sizeof(dataItem));
				if (data[i] == NULL)
					perror("�ڴ�������");
				res = fscanf(fp_data, "%d,%d,%d", &data[i]->item1, &data[i]->item2, &data[i]->item3);
			}
		}
		fclose(fp_data);
		return data;
	}
}

/*
* �������ƣ�loadfile4
* �������ܣ���ȡ�����ļ�������������ʽ�洢����
* �����������
* ����ֵ��node*������ͷָ���ַ
*/
node* loadfile4()
{
	FILE* fp_data = fopen(dataFile, "r");
	if (fp_data == NULL)
	{
		printf("�����ļ���ȡʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int res = fscanf(fp_data, "%d", &dataGroup);
		node* head = (node*)malloc(sizeof(node));
		if (head == NULL)
		{
			perror("�ڴ�������");
			exit(EXIT_FAILURE);
		}
		node* rear = head;
		for (int i = 0; i < dataGroup; i++)
		{
			node* temp = (node*)malloc(sizeof(node));
			if (temp == NULL)
			{
				perror("�ڴ�������");
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
