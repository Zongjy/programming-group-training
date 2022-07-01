/***********************************************
作者信息：
	姓名：李怡
	学号：21281163
	班级：计算机2106班
模块名称:
	Lab4_main.cpp
功能描述:
	程序主控文件，存放run函数及其他需要配套的子函数
模块历史:
	李怡于2022年5月12日创建本模块，email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "Lab4_main.h"

//全局变量定义
dataConf dconf;							//实验3的配置参数
modeConf mconf;							//实验4的配置参数（包含实验4运行模式）
int dataGroup = 0;						//数据文件中数据单元的组数
char dataFile[2 * MAX_STR_LEN] = {};	//数据文件名（含盘符、路径、文件名和扩展名）

/*
* 函数名称：run
* 函数功能：程序自检、自检通过后打印功能菜单并调用其他模块实现相应功能
* 输入参数：int argc：命令行参数个数
			char* argv[]：命令行参数
* 返回值：int：无特殊意义
*/
int run(int argc, char* argv[])
{
	//自检过程，并打印对应的提示信息
	if (sysCheck() == 0)
	{
		printf("自检错误\n");
		return 0;
	}
	else
	{
		printf("自检通过\n");
		//初始化各变量
		int select = 0;
		int** array2D;
		dataItem* arrayStruct;
		dataItem** ptrStruct;
		node* listHead;
		clock_t start, end;
		//打印菜单，提示用户输入
		printf(menu);
		//初始化全局变量（结构体形式存储配置信息）
		sysInit();
		//判断运行模式并打印提示信息
		if (mconf.mode == -1)
		{
			printf("配置文件错误，启用自动模式\n");
			mconf.mode = 0;
		}
		else if (mconf.mode == 0)
		{
			printf("使用自动模式\n");
		}
		else
		{
			printf("使用交互模式\n");
		}
		while(true)
		{
			printf("请输入您要执行的程序序号：\n");
			while (scanf("%d", &select) != 1)
			{
				rewind(stdin);
				printf("输入错误，请重新输入功能序号：\n");
			}
			switch (select)
			{
			//退出程序
			case 0: return 0;
			//调用实验3程序生成记录文件
			case 1: call(); break;
			//读取指定数据记录文件，以二维数组存储，并释放内存
			case 2: 
				loadfileInit();
				array2D = loadfile1();
				view1(array2D);
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//读取指定数据记录文件，以结构体数组存储，并释放内存
			case 3:
				loadfileInit();
				arrayStruct = loadfile2();
				view2(arrayStruct);
				free(arrayStruct);
				break;
			//读取指定数据记录文件，以结构体指针数组存储，并释放内存
			case 4:
				loadfileInit();
				ptrStruct = loadfile3();
				view3(ptrStruct);
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//读取指定数据记录文件，以链表存储，并释放内存
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
			//调用实验3程序生成记录文件，读取指定数据记录文件，以二维数组存储，并释放内存
			case 6:
				call();
				loadfileInit();
				array2D = loadfile1();
				view1(array2D);
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以结构体数组存储，并释放内存
			case 7:
				call();
				loadfileInit();
				arrayStruct = loadfile2();
				view2(arrayStruct);
				free(arrayStruct);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以结构体指针数组存储，并释放内存
			case 8:
				call();
				loadfileInit();
				ptrStruct = loadfile3();
				view3(ptrStruct);
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以链表存储，并释放内存
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
			//调用实验3程序生成记录文件，读取指定数据记录文件，以二维数组存储，并对二维数组排序，打印排序后数组及耗时，并释放内存
			case 10:
				call();
				loadfileInit();
				array2D = loadfile1();
				printf("********** 排序前 **********\n");
				view1(array2D);
				start = clock();
				qsort(array2D, dataGroup, sizeof(array2D[0]), cmp1);
				end = clock();
				printf("********** 排序后 **********\n");
				view1(array2D);
				printf("二维数组排序耗时：%lf毫秒\n", ((double)end - (double)start));
				for (int i = 0; i < dataGroup; i++)
					free(array2D[i]);
				free(array2D);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以结构体数组存储，并对结构体数组排序，打印排序后数组及耗时，并释放内存
			case 11:
				call();
				loadfileInit();
				arrayStruct = loadfile2();
				printf("********** 排序前 **********\n");
				view2(arrayStruct);	
				start = clock();
				qsort(arrayStruct, dataGroup, sizeof(arrayStruct[0]), cmp2);
				end = clock();
				printf("********** 排序后 **********\n");
				view2(arrayStruct);
				printf("结构体数组排序耗时：%lf毫秒\n", ((double)end - (double)start));
				free(arrayStruct);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以结构体指针数组存储，并对结构体指针数组排序，打印排序后数组及耗时，并释放内存
			case 12:
				call();
				loadfileInit();
				ptrStruct = loadfile3();
				printf("********** 排序前 **********\n");
				view3(ptrStruct);
				start = clock();
				qsort(ptrStruct, dataGroup, sizeof(ptrStruct[0]), cmp3);
				end = clock();
				printf("********** 排序后 **********\n");
				view3(ptrStruct);
				printf("指针数组排序耗时：%lf毫秒\n", ((double)end - (double)start));
				for (int i = 0; i < dataGroup; i++)
					free(ptrStruct[i]);
				free(ptrStruct);
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以链表存储，并用冒泡排序处理链表，打印排序后数组及耗时，并释放内存
			case 13:
				call();
				loadfileInit();
				listHead = loadfile4();
				printf("********** 排序前 **********\n");
				view4(listHead);
				start = clock();
				bubbleSort(&listHead);
				end = clock();
				printf("********** 排序后 **********\n");
				view4(listHead);
				printf("链表冒泡排序耗时：%lf毫秒\n", ((double)end - (double)start));
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//调用实验3程序生成记录文件，读取指定数据记录文件，以链表存储，并用快速排序处理链表，打印排序后数组及耗时，并释放内存
			case 14:
				call();
				loadfileInit();
				listHead = loadfile4();
				printf("********** 排序前 **********\n");
				view4(listHead);
				start = clock();
				quickSort(listHead, NULL);
				end = clock();
				printf("********** 排序后 **********\n");
				view4(listHead);
				printf("链表快速排序耗时：%lf毫秒\n", ((double)end - (double)start));
				for (node* p = listHead; p != NULL;)
				{
					node* q = p;
					p = p->next;
					free(q);
				}
				break;
			//调用修改配置参数模块
			case 15:
				confModify();
				break;
			//其他错误输入打印提示信息并继续循环
			default:
				printf("请输入正确的序号！\n");
			}
		}
	}
	return 0;
}

/*
* 函数名称：sysCheck
* 函数功能：程序自检（即检查各配置文件和外部调用程序）
* 输入参数：无
* 返回值：int：自检通过返回1，否则返回0
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
* 函数名称：sysInit
* 函数功能：初始化配置参数，读取同目录的conf.ini和mode.ini文件，并将该信息存储到全局变量中
* 输入参数：无
* 返回值：无
*/
void sysInit()
{
	FILE* fp_conf = fopen("conf.ini", "r");
	if (fp_conf == NULL)
	{
		printf("Lab3数据配置文件错误！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(dconf.fileSavePath, MAX_STR_LEN, fp_conf);
		fgets(dconf.fileName, MAX_STR_LEN, fp_conf);
		fscanf_s(fp_conf, "%d%d%d%d%d%d", &dconf.maxValue1, &dconf.minValue1, \
			& dconf.maxValue2, &dconf.minValue2, &dconf.recordCount1, &dconf.recordCount2);
		dconf.fileSavePath[strlen(dconf.fileSavePath) - 1] = '\0';
		dconf.fileName[strlen(dconf.fileName) - 1] = '\0';				//去掉文件目录和文件名末尾的'\n'，并改为'\0'
		fclose(fp_conf);
	}
	FILE* fp_mode = fopen("mode.ini", "r");
	if (fp_mode == NULL)
	{
		printf("Lab4模式配置文件错误！\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(mconf.dataFilePath, MAX_STR_LEN, fp_mode);
		fgets(mconf.dataFileName, MAX_STR_LEN, fp_mode);
		fscanf_s(fp_mode, "%d", &mconf.mode);
		mconf.dataFilePath[strlen(mconf.dataFilePath) - 1] = '\0';
		mconf.dataFileName[strlen(mconf.dataFileName) - 1] = '\0';		//去掉文件目录和文件名末尾的'\n'，并改为'\0'
		fclose(fp_mode);
	}
}