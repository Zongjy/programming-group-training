#include "pch.h"
#include "Lab3_run.h"
#include "Lab3_fun.h"
const char textsuffix[] = ".txt";
CONF config;

void run(int argc, char* argv[]) 
{
	int mode = 1;						//���ݴ洢�ķ�ʽ��1(Ĭ��)����ά���飻2���ṹ��
	char output_path[MAX_STR_LEN];		//����ļ��Ĵ洢Ŀ¼
	char output_name[MAX_STR_LEN];		//����ļ���
	char output_ext[_MAX_EXT];
	config_init();
	mode = menu();
	if (argc == 1)
	{
		printf("������ɼ�¼������\n");
		config.number = ran_num(config.recordcount1, config.recordcount2);
		printf("ʹ��Ĭ���ļ��洢���á�\n");
		strcpy_s(output_path, config.filesavepath);
		strcpy_s(output_name, config.filename);
	}
	else if (argc == 3)
	{
		config.number = atoi(argv[1]);		//�������в�����ȡ��¼����
		_splitpath(argv[2], NULL, output_path, output_name, output_ext);
		if (is_file_legal(output_name) )			//�ж��ļ����Ƿ���ȷ
		{
			strcat_s(output_name, output_ext);
		}
		else
		{
			printf("�����ļ�����Ч��ʹ��Ĭ���ļ�����\n");
			strcpy_s(output_name, config.filename);
		}
	}
	else
	{
		printf("����������󣬳��������\n");	//�����������ֱ���˳�
		exit(EXIT_FAILURE);
	}
	write_file(output_path, output_name, mode); 
}