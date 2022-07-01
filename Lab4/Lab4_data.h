/***********************************************
������Ϣ��
    ����������
    ѧ�ţ�21281163
    �༶�������2106��
ģ������:
    Lab4_data.h
��������:
    �ṹ�弰��������ģ�飬���ʵ��4��������Ľṹ������������������ȫ�ֱ�������
ģ����ʷ:
    ������2022��5��12�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#pragma once
#define MAX_STR_LEN 256                         //�ļ�����������
enum modes { automatic = 0, interactive = 1 };  //����ģʽ�б�

typedef struct DATAITEM
{
	int item1;
	int item2;
	int item3;
} dataItem;

typedef struct DATACONF{
    char fileSavePath[MAX_STR_LEN];             //���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
    char fileName[MAX_STR_LEN];                 //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
    int num;
    int maxValue1;      //���ڴ��ʵ��3�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
    int minValue1;      //���ڴ��ʵ��3�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
    int maxValue2;      //���ڴ��ʵ��3�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
    int minValue2;      //���ڴ��ʵ��3�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
    int recordCount1;   //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
    int recordCount2;   //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
} dataConf;

typedef struct MODECONF {
    char dataFilePath[MAX_STR_LEN];             //���ڴ��Ĭ�����ݼ����ļ��Ĵ洢Ŀ¼
    char dataFileName[MAX_STR_LEN];             //���ڴ��Ĭ�����ݼ����ļ��Ĵ洢Ŀ¼
    int mode;                                   //���ڴ��ʵ��������ģʽ
} modeConf;

typedef struct NODE {
    dataItem value;                             //����������
    struct NODE *next;                          //����ָ����
} node;

//ȫ�ֱ�������
extern dataConf dconf;                          //ʵ��3�����ļ��ṹ��
extern modeConf mconf;                          //ʵ��4�����ļ��ṹ��
extern char dataFile[];                         //�����ļ��������̷���·�����ļ�������չ����
extern int dataGroup;                           //�����ļ������ݵ�Ԫ������