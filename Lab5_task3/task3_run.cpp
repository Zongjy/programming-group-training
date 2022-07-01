#include"pch.h"
#include"task3_run.h"
#include"task3_data.h"
#include"task3_call.h"
#include"task3_folder.h"
#include"task3_sumup_html.h"
STAC stac;
int option;
char menu[] = "\033[1;34m李怡，罗语潼小组的实验5程序：\033[0m\n\
\t\033[1;36m1.对单个英文文档进行统计\033[0m\n\
\t\033[1;36m2.对批量英文文档进行统计\033[0m\n\
\t\033[1;36m0.退出\033[0m\n\
\033[1;36m请输入您要执行的程序序号：\033[0m\n";
void run()
{
	while (1)
	{
		printf("%s", menu);                  //菜单功能
		scanf("%d", &option);
		if (option == 0)
		{
			printf("程序结束");
			return;
		}
		else if (option == 1)
		{
			printf("\033[1;33m当前仅能处理单个英文文档\033[0m\n");
			printf("请输入您要处理的英文文档路径（绝对或相对路径，如 ./data/article.txt）：");
			scanf("%s", stac.filename1);
			double start = clock();
			call_task1();
			double end = clock();
			call_task2();
			printf("由子任务3调用子任务1统计此文档用时为\033[1;33m%lf毫秒\033[0m\n", ((double)end - (double)start));
		}
		else if (option == 2)
		{
			printf("\033[1;34m当前您能处理一个文件夹内所有的英文文档\033[0m\n");
			printf("请输入您要处理的文件夹路径（绝对路径或相对路径,如 ./data）：");
			scanf("%s", stac.dirname);
			process_folder();
			//调用默认浏览器打开汇总html
			HINSTANCE r = ShellExecute(NULL, TEXT("open"), L"sum.html", NULL, NULL, SW_SHOWNORMAL);
			if ((DWORD)r <= 32)
			{
				printf("\033[1;31m整合html用网页打开失败，程序结束\033[0m\n");
				system("pause");
				exit(1);
			}
		}
		else
		{
			printf("033[1;31m请输入正确的序号\033[0m\n");
		}
	}
}

