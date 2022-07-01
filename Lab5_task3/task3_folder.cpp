#include"pch.h"
#include"task3_run.h"
#include"task3_folder.h"
#include"task3_data.h"
#include"task3_sumup_html.h"
#include"task3_call.h"
//函数功能：调用子任务1,2处理一整个文件夹中的英文txt文件并完善汇总html
void process_folder()
{
	//相关知识点：C语言读取指定文件夹下的所有文件
	struct _finddata_t fileinfo;  //文件储存信息结构体
	intptr_t fHandle;   //保存文件句柄
	char tem[MAX_LEN];
	int cnt=0;
	strcpy(tem, stac.dirname);
	strcat(tem, "/*.txt");     //为了findfirst表示目标文件格式时使用
	if ((fHandle = _findfirst(tem, &fileinfo))==-1L)
	{
		printf("\033[1;31m当前目录下没有txt文件,程序结束\033[0m\n");
		system("pause");
		exit(1);
	}
	else
	{
		write_sumup_html();  //创建sum.html
		double start = clock();
		do{
			cnt++;
			strcpy(stac.filename1, stac.dirname);
			strcat(stac.filename1, "/");
			strcat(stac.filename1, fileinfo.name);
			call_task1();
			call_task2();
			//录入此文件的统计文档到总结html中
			fprintf(fp, "<a href=\"%s\">跳转到%s的统计页面</a>\n<br>\n<br>\n", stac.filename3, fileinfo.name);
		} while (_findnext(fHandle, &fileinfo) == 0);

		double end = clock();
		printf("由子任务3调用子任务1统计此文件夹共用时为 \033[1;33m% lf毫秒\033[0m\n", ((double)end - (double)start));
		fprintf(fp, "</body>\n</html>\n"); 
	}
	_findclose(fHandle);
	fclose(fp);
}