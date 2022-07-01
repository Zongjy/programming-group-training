/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_conf.cpp
��������:
	ϵͳ����ģ�飬������޸������ļ���صĹ��ܺ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_conf.h"
extern dataConf dconf;

/*
* �������ƣ�confModify
* �������ܣ��޸�ʵ������ʵ���������ļ�����
* �����������
* ����ֵ����
*/
void confModify()
{
	printf(confMenu);
	int sel = 1, res;
	while (sel!=0)
	{
		printf("��������Ҫ�޸ĵ�������ţ�\n");
		while (scanf("%d", &sel) != 1)
		{
			rewind(stdin);
			printf("����������������빦����ţ�\n");
		}
		switch (sel)
		{
		case 1:
			printf("Ĭ���ļ��洢·��\nԭ���ò�����%s\n�����ò�����", dconf.fileSavePath);
			res = scanf("%s", dconf.fileSavePath);
			break;
		case 2:
			printf("Ĭ���ļ��洢��\nԭ���ò�����%s\n�����ò�����", dconf.fileName);
			res = scanf("%s", dconf.fileName);
			break;
		case 3:
			printf("��һ������Ԫ�����ֵ\nԭ���ò�����%d\n�����ò�����", dconf.maxValue1);
			res = scanf("%d", &dconf.maxValue1);
			break;
		case 4:
			printf("��һ������Ԫ����Сֵ\nԭ���ò�����%d\n�����ò�����", dconf.minValue1);
			res = scanf("%d", &dconf.minValue1);
			break;
		case 5:
			printf("������Ԫ�����ֵ\nԭ���ò�����%d\n�����ò�����", dconf.maxValue2);
			res = scanf("%d", &dconf.maxValue2);
			break;
		case 6:
			printf("������Ԫ����Сֵ\nԭ���ò�����%d\n�����ò�����", dconf.minValue2);
			res = scanf("%d", &dconf.minValue2);
			break;
		case 7:
			printf("��¼�������ֵ\nԭ���ò�����%d\n�����ò�����", dconf.recordCount1);
			res = scanf("%d", &dconf.recordCount1);
			break;
		case 8:
			printf("��¼������Сֵ\nԭ���ò�����%d\n�����ò�����", dconf.recordCount2);
			res = scanf("%d", &dconf.recordCount2);
			break;
		case 9:
			printf("Ĭ�����ݶ�ȡ�ļ�·��\nԭ���ò�����%s\n�����ò�����", mconf.dataFilePath);
			res = scanf("%s", mconf.dataFilePath);
			break;
		case 10:
			printf("Ĭ�����ݶ�ȡ�ļ���\nԭ���ò�����%s\n�����ò�����", mconf.dataFileName);
			res = scanf("%s", mconf.dataFileName);
			break;
		case 11:
			printf("Ĭ������ģʽ��0���Զ�ģʽ�� 1������ģʽ��\nԭ���ò�����%d\n�����ò�����", mconf.mode);
			res = scanf("%d", &mconf.mode);
			break;
		case 0:
			update();
			printf("���ò����޸ĳɹ���\n");
			break;
		default:
			printf("��������ȷ����ţ�\n");
		}
	}
}

/*
* �������ƣ�update
* �������ܣ��޸�ʵ������ʵ���������ļ�����
* �����������
* ����ֵ����
*/
void update()
{
	FILE* fp_conf = fopen("conf.ini", "w");
	if (fp_conf == NULL)
	{
		printf("Lab3���������ļ�����\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(fp_conf, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d", dconf.fileSavePath, dconf.fileName, dconf.maxValue1, \
			dconf.minValue1, dconf.maxValue2, dconf.minValue2, dconf.recordCount1, dconf.recordCount2);
		fclose(fp_conf);
	}
	FILE* fp_mode = fopen("mode.ini", "w");
	if (fp_mode == NULL)
	{
		printf("Lab4ģʽ�����ļ�����\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(fp_mode, "%s\n%s\n%d", mconf.dataFilePath, mconf.dataFileName, mconf.mode);
		fclose(fp_mode);
	}
}