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
		config.filename[strlen(config.filename) - 1] = '\0';		//去掉文件目录和文件名末尾的'\n'，并改为'\0'。
	}
}


int menu()
{
	int mode = 1;
	printf("李怡的实验3程序：\n"
	"\t1. 生成数据记录文件（使用二维数组存储）\n"
	"\t2. 生成数据记录文件（使用结构体数组存储）\n"
	"请输入您要执行的功能序号:（1 or 2）\n");
	while (1)
	{
		if (scanf("%d", &mode) == 1 && (mode <= 2 && mode >= 1))
			return mode;
		else
		{
			rewind(stdin);
			printf("输入错误，请重新输入!\n");
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
			printf("数据错误，请重新输入记录条数(正整数)!\n");
		}
	}
}


bool is_file_legal(char* p)
{
	if (p == NULL)
		return false;					
	if (*p == ' ')							//文件名开头不能为空格
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
	return (int)(rand() % (nMax - nMin + 1) + nMin);//产生指定范围内的伪随机数
}


void write_file(char* path, char* name, int mode) 
{
	FILE* fp;
	char filename[2 * MAX_STR_LEN] = {};
	if (name==NULL||path == NULL)
		exit(EXIT_FAILURE);
	if (_access(path, 0) !=0)			//没有该目录时，创建该目录
		if (_mkdir(path) != 0)
		{
			perror("1path error");
			exit(EXIT_FAILURE);
		}
	else
	{
		if (_access(path, 6) !=0)		//存在该目录，但权限不足时，删除并重建目录
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
		fprintf(fp, "%d\n", config.number);		//从文件内第一行存储记录条数，第二行逐行存储三元数据
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