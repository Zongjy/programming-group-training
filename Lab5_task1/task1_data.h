#pragma once
#define MAX_LEN 1024		//�洢�ļ�����󳤶�
typedef struct statistics
{
	char filename[MAX_LEN];	//�洢�ļ���
	int mode;				//��ʱ��ģʽ
	int word;				//Ӣ�ĵ���
	int character;			//�ַ�����
	int num;				//����
	int blank;				//�հ��ַ�
	int letter;				//Ӣ����ĸ
	int others;				//�����ַ��ĸ���
	int paras;				//������
}STAC;	
extern STAC stac;			//ȫ�ֱ����ṹ��(ͳ������)��������