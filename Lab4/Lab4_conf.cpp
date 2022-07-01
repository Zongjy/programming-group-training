/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_conf.cpp
功能描述:
	系统配置模块，存放与修改配置文件相关的功能函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_conf.h"
extern dataConf dconf;

/*
* 函数名称：confModify
* 函数功能：修改实验三和实验四配置文件参数
* 输入参数：无
* 返回值：无
*/
void confModify()
{
	printf(confMenu);
	int sel = 1, res;
	while (sel!=0)
	{
		printf("请输入您要修改的配置序号：\n");
		while (scanf("%d", &sel) != 1)
		{
			rewind(stdin);
			printf("输入错误，请重新输入功能序号：\n");
		}
		switch (sel)
		{
		case 1:
			printf("默认文件存储路径\n原配置参数：%s\n新配置参数：", dconf.fileSavePath);
			res = scanf("%s", dconf.fileSavePath);
			break;
		case 2:
			printf("默认文件存储名\n原配置参数：%s\n新配置参数：", dconf.fileName);
			res = scanf("%s", dconf.fileName);
			break;
		case 3:
			printf("第一、二个元素最大值\n原配置参数：%d\n新配置参数：", dconf.maxValue1);
			res = scanf("%d", &dconf.maxValue1);
			break;
		case 4:
			printf("第一、二个元素最小值\n原配置参数：%d\n新配置参数：", dconf.minValue1);
			res = scanf("%d", &dconf.minValue1);
			break;
		case 5:
			printf("第三个元素最大值\n原配置参数：%d\n新配置参数：", dconf.maxValue2);
			res = scanf("%d", &dconf.maxValue2);
			break;
		case 6:
			printf("第三个元素最小值\n原配置参数：%d\n新配置参数：", dconf.minValue2);
			res = scanf("%d", &dconf.minValue2);
			break;
		case 7:
			printf("记录条数最大值\n原配置参数：%d\n新配置参数：", dconf.recordCount1);
			res = scanf("%d", &dconf.recordCount1);
			break;
		case 8:
			printf("记录条数最小值\n原配置参数：%d\n新配置参数：", dconf.recordCount2);
			res = scanf("%d", &dconf.recordCount2);
			break;
		case 9:
			printf("默认数据读取文件路径\n原配置参数：%s\n新配置参数：", mconf.dataFilePath);
			res = scanf("%s", mconf.dataFilePath);
			break;
		case 10:
			printf("默认数据读取文件名\n原配置参数：%s\n新配置参数：", mconf.dataFileName);
			res = scanf("%s", mconf.dataFileName);
			break;
		case 11:
			printf("默认运行模式（0：自动模式， 1：交互模式）\n原配置参数：%d\n新配置参数：", mconf.mode);
			res = scanf("%d", &mconf.mode);
			break;
		case 0:
			update();
			printf("配置参数修改成功！\n");
			break;
		default:
			printf("请输入正确的序号！\n");
		}
	}
}

/*
* 函数名称：update
* 函数功能：修改实验三和实验四配置文件参数
* 输入参数：无
* 返回值：无
*/
void update()
{
	FILE* fp_conf = fopen("conf.ini", "w");
	if (fp_conf == NULL)
	{
		printf("Lab3数据配置文件错误！\n");
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
		printf("Lab4模式配置文件错误！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(fp_mode, "%s\n%s\n%d", mconf.dataFilePath, mconf.dataFileName, mconf.mode);
		fclose(fp_mode);
	}
}