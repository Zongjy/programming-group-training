/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_call.cpp
��������:
	�ⲿ�������ģ�飬��ŵ���ʵ��4�����������ݼ�¼�ļ��ĺ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_call.h"

/*
* �������ƣ�call
* �������ܣ������ⲿ����Lab3.exe��������ʵ��������ģʽ�ж������в���ֵ
* �����������
* ����ֵ����
*/
void call()
{
	char command[777], makeFile[777];
	//�ж�����ģʽ
	switch (mconf.mode)
	{
	//�Զ�ģʽʱ��dos�����ַ���Ϊ�ⲿ�����ļ���
	case automatic:
		sprintf(command, "Lab3.exe");
		break;
	//����ģʽʱ��dos�����ַ���Ϊ�ⲿ�����ļ����������в�����ͨ����׼�����ȡ
	case interactive:
		printf("�������¼������\n");
		scanf("%d", &dconf.num);
		printf("�����������ļ��洢·��(���ļ���)��\n");
		scanf("%s", makeFile);
		sprintf(command, "Lab3.exe %d %s", dconf.num, makeFile);
		break;
	//���������ӡ������ʾ��Ϣ���˳�
	default:
		printf("ģʽ����\n");
		exit(EXIT_FAILURE);
	}
	//ʹ��system����ʹ��dos����
	if (system(command) != 0)
	{
		printf("����Lab3.exeʧ�ܣ�\n");
	}
}
