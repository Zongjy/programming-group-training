#pragma once
//��ͷ�ļ����ڴ洢�ⲿ����

#define MAX_LEN 1028
typedef struct statistics
{
	char filename1[MAX_LEN];  //�账���Ӣ���ĵ��ĵ�ַ
	char filename2[MAX_LEN];//�����账���Ӣ���ĵ�������txt�ĵ�ַ
	char filename3[MAX_LEN];  //�����账���Ӣ���ĵ�html����ĵ�ַ
	char dirname[MAX_LEN]; //����ȡ�ĺ���һ��txt�ļ���Ŀ¼����
}STAC;
extern STAC stac;

extern FILE* fp;//�������html���ļ�ָ��
extern int option;

