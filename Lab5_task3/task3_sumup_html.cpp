#include"pch.h"
#include"task3_run.h"
#include"task3_sumup_html.h"
#include"task3_data.h"
//函数功能：创建汇总html并写入初始内容
FILE* fp;
void write_sumup_html()
{
	fp = fopen("sum.html", "w+");                //创建汇总html
	if (fp == NULL) {
		printf("\033[1;31m生成汇总html文件失败！程序结束\033[0m\n");
		system("pause");
		exit(1);
	}

	//写入html头
	fprintf(fp, "<html>\n\
<head>\n\
<title>第二组汇总文档</title>\n\
</head>\n\
<body>\n");
}