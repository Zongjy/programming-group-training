/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	Lab4_main.cpp
��������:
	���������ļ������run������������Ҫ���׵��Ӻ���
ģ����ʷ:
	������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_main.h"

//ȫ�ֱ�������
dataConf dconf;							//ʵ��3�����ò���
modeConf mconf;							//ʵ��4�����ò���������ʵ��4����ģʽ��
int dataGroup = 0;						//�����ļ������ݵ�Ԫ������
char dataFile[2 * MAX_STR_LEN] = {};	//�����ļ��������̷���·�����ļ�������չ����

/*
* �������ƣ�run
* �������ܣ������Լ졢�Լ�ͨ�����ӡ���ܲ˵�����������ģ��ʵ����Ӧ����
* ���������int argc�������в�������
			char* argv[]�������в���
* ����ֵ��int������������
*/
int run(int argc, char* argv[])
{
	//�Լ���̣�����ӡ��Ӧ����ʾ��Ϣ
	if (sysCheck() == 0)
	{
		printf("�Լ����\n");
		return 0;
	}
	else
	{
		printf("�Լ�ͨ��\n");
		//��ʼ��������
		int select = 0;
		int** array2D;
		dataItem* arrayStruct;
		dataItem** ptrStruct;
		node* listHead;
		clock_t start, end;
		//��ӡ�˵�����ʾ�û�����
		printf(menu);
		//��ʼ��ȫ�ֱ������ṹ����ʽ�洢������Ϣ��
		sysInit();
		//�ж�����ģʽ����ӡ��ʾ��Ϣ
		if (mconf.mode == -1)
		{
			printf("�����ļ����������Զ�ģʽ\n");
			mconf.mode = 0;
		}
		else if (mconf.mode == 0)
		{
			printf("ʹ���Զ�ģʽ\n");
		}
		else
		{
			printf("ʹ�ý���ģʽ\n");
		}
		while(true)
		{
			printf("��������Ҫִ�еĳ�����ţ�\n");
			while (scanf("%d", &select) != 1)
			{
				rewind(stdin);
				printf("����������������빦����ţ�\n");
			}
			switch (select)
			{
			//�˳�����
			case 0: return 0;
			//����ʵ��3�������ɼ�¼�ļ�
			case 1: call(); break;
			//��ȡָ�����ݼ�¼�ļ����Զ�ά����洢�����ͷ��ڴ�
			case 2: 
				loadfileInit();
				array2D = loadfile1();
				view1(array2D);
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//��ȡָ�����ݼ�¼�ļ����Խṹ������洢�����ͷ��ڴ�
			case 3:
				loadfileInit();
				arrayStruct = loadfile2();
				view2(arrayStruct);
				free(arrayStruct);
				break;
			//��ȡָ�����ݼ�¼�ļ����Խṹ��ָ������洢�����ͷ��ڴ�
			case 4:
				loadfileInit();
				ptrStruct = loadfile3();
				view3(ptrStruct);
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//��ȡָ�����ݼ�¼�ļ���������洢�����ͷ��ڴ�
			case 5:
				loadfileInit();
				listHead = loadfile4();
				view4(listHead);
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Զ�ά����洢�����ͷ��ڴ�
			case 6:
				call();
				loadfileInit();
				array2D = loadfile1();
				view1(array2D);
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Խṹ������洢�����ͷ��ڴ�
			case 7:
				call();
				loadfileInit();
				arrayStruct = loadfile2();
				view2(arrayStruct);
				free(arrayStruct);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Խṹ��ָ������洢�����ͷ��ڴ�
			case 8:
				call();
				loadfileInit();
				ptrStruct = loadfile3();
				view3(ptrStruct);
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ���������洢�����ͷ��ڴ�
			case 9:
				call();
				loadfileInit();
				listHead = loadfile4();
				view4(listHead);
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Զ�ά����洢�����Զ�ά�������򣬴�ӡ��������鼰��ʱ�����ͷ��ڴ�
			case 10:
				call();
				loadfileInit();
				array2D = loadfile1();
				printf("********** ����ǰ **********\n");
				view1(array2D);
				start = clock();
				qsort(array2D, dataGroup, sizeof(array2D[0]), cmp1);
				end = clock();
				printf("********** ����� **********\n");
				view1(array2D);
				printf("��ά���������ʱ��%lf����\n", ((double)end - (double)start));
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Խṹ������洢�����Խṹ���������򣬴�ӡ��������鼰��ʱ�����ͷ��ڴ�
			case 11:
				call();
				loadfileInit();
				arrayStruct = loadfile2();
				printf("********** ����ǰ **********\n");
				view2(arrayStruct);	
				start = clock();
				qsort(arrayStruct, dataGroup, sizeof(arrayStruct[0]), cmp2);
				end = clock();
				printf("********** ����� **********\n");
				view2(arrayStruct);
				printf("�ṹ�����������ʱ��%lf����\n", ((double)end - (double)start));
				free(arrayStruct);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ����Խṹ��ָ������洢�����Խṹ��ָ���������򣬴�ӡ��������鼰��ʱ�����ͷ��ڴ�
			case 12:
				call();
				loadfileInit();
				ptrStruct = loadfile3();
				printf("********** ����ǰ **********\n");
				view3(ptrStruct);
				start = clock();
				qsort(ptrStruct, dataGroup, sizeof(ptrStruct[0]), cmp3);
				end = clock();
				printf("********** ����� **********\n");
				view3(ptrStruct);
				printf("ָ�����������ʱ��%lf����\n", ((double)end - (double)start));
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ���������洢������ð��������������ӡ��������鼰��ʱ�����ͷ��ڴ�
			case 13:
				call();
				loadfileInit();
				listHead = loadfile4();
				printf("********** ����ǰ **********\n");
				view4(listHead);
				start = clock();
				bubbleSort(&listHead);
				end = clock();
				printf("********** ����� **********\n");
				view4(listHead);
				printf("����ð�������ʱ��%lf����\n", ((double)end - (double)start));
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//����ʵ��3�������ɼ�¼�ļ�����ȡָ�����ݼ�¼�ļ���������洢�����ÿ���������������ӡ��������鼰��ʱ�����ͷ��ڴ�
			case 14:
				call();
				loadfileInit();
				listHead = loadfile4();
				printf("********** ����ǰ **********\n");
				view4(listHead);
				start = clock();
				quickSort(listHead, NULL);
				end = clock();
				printf("********** ����� **********\n");
				view4(listHead);
				printf("������������ʱ��%lf����\n", ((double)end - (double)start));
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//�����޸����ò���ģ��
			case 15:
				confModify();
				break;
			//�������������ӡ��ʾ��Ϣ������ѭ��
			default:
				printf("��������ȷ����ţ�\n");
			}
		}
	}
	return 0;
}

/*
* �������ƣ�sysCheck
* �������ܣ������Լ죨�����������ļ����ⲿ���ó���
* �����������
* ����ֵ��int���Լ�ͨ������1�����򷵻�0
*/
int sysCheck()
{
	if (_access("Lab3.exe", 0))
		return 0;
	if (_access("conf.ini", 0))
		return 0;
	if (_access("mode.ini", 0))
		return 0;
	return 1;
}

/*
* �������ƣ�sysInit
* �������ܣ���ʼ�����ò�������ȡͬĿ¼��conf.ini��mode.ini�ļ�����������Ϣ�洢��ȫ�ֱ�����
* �����������
* ����ֵ����
*/
void sysInit()
{
	FILE* fp_conf = fopen("conf.ini", "r");
	if (fp_conf == NULL)
	{
		printf("Lab3���������ļ�����\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(dconf.fileSavePath, MAX_STR_LEN, fp_conf);
		fgets(dconf.fileName, MAX_STR_LEN, fp_conf);
		fscanf_s(fp_conf, "%d%d%d%d%d%d", &dconf.maxValue1, &dconf.minValue1, \
			& dconf.maxValue2, &dconf.minValue2, &dconf.recordCount1, &dconf.recordCount2);
		dconf.fileSavePath[strlen(dconf.fileSavePath) - 1] = '\0';
		dconf.fileName[strlen(dconf.fileName) - 1] = '\0';				//ȥ���ļ�Ŀ¼���ļ���ĩβ��'\n'������Ϊ'\0'
		fclose(fp_conf);
	}
	FILE* fp_mode = fopen("mode.ini", "r");
	if (fp_mode == NULL)
	{
		printf("Lab4ģʽ�����ļ�����\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(mconf.dataFilePath, MAX_STR_LEN, fp_mode);
		fgets(mconf.dataFileName, MAX_STR_LEN, fp_mode);
		fscanf_s(fp_mode, "%d", &mconf.mode);
		mconf.dataFilePath[strlen(mconf.dataFilePath) - 1] = '\0';
		mconf.dataFileName[strlen(mconf.dataFileName) - 1] = '\0';		//ȥ���ļ�Ŀ¼���ļ���ĩβ��'\n'������Ϊ'\0'
		fclose(fp_mode);
	}
}