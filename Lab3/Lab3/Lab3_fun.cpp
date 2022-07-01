#include "pch.h"
#include "Lab3_fun.h"
#include "Lab3_data.h"
#define clear_error(f) if(ferror(f)){printf("Error operation to file!\n");clearerr(f);}
extern CONF config;

void config_init()
{
	FILE* fpconf;
	const char configFileName[] = "conf.ini";
	fpconf = fopen(configFileName, "r");
	if (fpconf == NULL)
	{
		perror("config init error");
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(config.filesavepath, MAX_STR_LEN, fpconf);
		clear_error(fpconf)
		fgets(config.filename, MAX_STR_LEN, fpconf);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.maxvalue1);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.minvalue1);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.maxvalue2);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.minvalue2);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.recordcount1);
		clear_error(fpconf)
		fscanf_s(fpconf, "%d", &config.recordcount2);
		clear_error(fpconf)
		fclose(fpconf);
		config.filesavepath[strlen(config.filesavepath) - 1] = '\0';
		config.filename[strlen(config.filename) - 1] = '\0';		//ȥ���ļ�Ŀ¼���ļ���ĩβ��'\n'������Ϊ'\0'��
	}
}


int menu()
{
	int mode = 1;
	printf("������ʵ��3����\n"
	"\t1. �������ݼ�¼�ļ���ʹ�ö�ά����洢��\n"
	"\t2. �������ݼ�¼�ļ���ʹ�ýṹ������洢��\n"
	"��������Ҫִ�еĹ������:��1 or 2��\n");
	while (1)
	{
		if (scanf("%d", &mode) == 1 && (mode <= 2 && mode >= 1))
			return mode;
		else
		{
			rewind(stdin);
			printf("�����������������!\n");
		}
	}
}

int get_num()
{
	int num;
	while (1)		
	{
		if (scanf("%d", &num) == 1)
		{
			return num;
		}
		else
		{
			rewind(stdin);
			printf("���ݴ��������������¼����(������)!\n");
		}
	}
}


bool is_file_legal(char* p)
{
	if (p == NULL)
		return false;					
	if (*p == ' ')							//�ļ�����ͷ����Ϊ�ո�
		return false;
	for (int i=0; *(p+i) != '\0'; ++i)
	{
		if (*(p + i) == '?' || *(p + i) == '*' || *(p + i) == '/' || *(p + i) == '|' || *(p + i) == '\\' || *(p + i) == ':' || *(p + i) == '<' || *(p + i) == '>')
			return false;
	}
	return true;
}


int ran_num(int nMax, int nMin) 
{
	return (int)(rand() % (nMax - nMin + 1) + nMin);//����ָ����Χ�ڵ�α�����
}


void write_file(char* path, char* name, int mode) 
{
	FILE* fp;
	char filename[2 * MAX_STR_LEN] = {};
	if (name==NULL||path == NULL)
		exit(EXIT_FAILURE);
	if (_access(path, 0) !=0)			//û�и�Ŀ¼ʱ��������Ŀ¼
		if (_mkdir(path) != 0)
		{
			perror("1path error");
			exit(EXIT_FAILURE);
		}
	else
	{
		if (_access(path, 6) !=0)		//���ڸ�Ŀ¼����Ȩ�޲���ʱ��ɾ�����ؽ�Ŀ¼
		{
			if (_rmdir(path) != 0)
			{
				perror("2path error");
				exit(EXIT_FAILURE);
			}
			if(_mkdir(path)!=0)
			{
				perror("3path error");
				exit(EXIT_FAILURE);
			}
		}
	}
	strcat_s(filename, path);
	strcat_s(filename, name);
	fp = fopen(filename, "w");
	srand((unsigned)time(NULL));
	if (fp == NULL)
	{
		perror("file error");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(fp, "%d\n", config.number);		//���ļ��ڵ�һ�д洢��¼�������ڶ������д洢��Ԫ����
		if (mode == 1)
		{
			int** data = (int**)malloc(config.number * sizeof(int*));
			if (data == NULL)
				perror("malloc error");
			else
			{
				for (int i = 0; i < config.number; ++i)
				{
					data[i] = (int*)malloc(3 * sizeof(int));
					if (data[i] == NULL)
					{
						perror("malloc error");
						exit(EXIT_FAILURE);
					}
					else
					{
						data[i][0] = ran_num(config.maxvalue1, config.minvalue1);
						data[i][1] = ran_num(config.maxvalue1, config.minvalue1);
						data[i][2] = ran_num(config.maxvalue2, config.minvalue2);
						fprintf(fp, "%d,%d,%d\n", data[i][0], data[i][1], data[i][2]);
						//printf("%d,%d,%d\n", data[i][0], data[i][1], data[i][2]);
					}
				}
			}
			for (int i = 0; i < config.number; ++i)
			{
				free(data[i]);
			}
			free(data);
		}
		else if (mode == 2)
		{
			DATAITEM* data = (DATAITEM*)malloc(config.number * sizeof(DATAITEM));
			if (data == NULL)
			{
				perror("malloc error");
				exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0; i < config.number; ++i)
				{
					data[i].item1 = ran_num(config.maxvalue1, config.minvalue1);
					data[i].item2 = ran_num(config.maxvalue1, config.minvalue1);
					data[i].item3 = ran_num(config.maxvalue2, config.minvalue2);
					fprintf(fp, "%d,%d,%d\n", data[i].item1, data[i].item2, data[i].item3);
					//printf("%d,%d,%d\n", data[i].item1, data[i].item2, data[i].item3);
				}
			}
			free(data);
		}
		fclose(fp);
	}
}