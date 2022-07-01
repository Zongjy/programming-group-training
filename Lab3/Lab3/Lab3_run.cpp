#include "pch.h"
#include "Lab3_run.h"
#include "Lab3_fun.h"
const char textsuffix[] = ".txt";
CONF config;

void run(int argc, char* argv[]) 
{
	int mode = 1;						//数据存储的方式，1(默认)：二维数组；2：结构体
	char output_path[MAX_STR_LEN];		//输出文件的存储目录
	char output_name[MAX_STR_LEN];		//输出文件名
	char output_ext[_MAX_EXT];
	config_init();
	mode = menu();
	if (argc == 1)
	{
		printf("随机生成记录条数。\n");
		config.number = ran_num(config.recordcount1, config.recordcount2);
		printf("使用默认文件存储配置。\n");
		strcpy_s(output_path, config.filesavepath);
		strcpy_s(output_name, config.filename);
	}
	else if (argc == 3)
	{
		config.number = atoi(argv[1]);		//从命令行参数获取记录条数
		_splitpath(argv[2], NULL, output_path, output_name, output_ext);
		if (is_file_legal(output_name) )			//判断文件名是否正确
		{
			strcat_s(output_name, output_ext);
		}
		else
		{
			printf("输入文件名无效，使用默认文件名。\n");
			strcpy_s(output_name, config.filename);
		}
	}
	else
	{
		printf("输入参数错误，程序结束。\n");	//其他错误情况直接退出
		exit(EXIT_FAILURE);
	}
	write_file(output_path, output_name, mode); 
}