#include"pch.h"
#include"task3_run.h"
#include"task3_sumup_html.h"
#include"task3_data.h"
//�������ܣ���������html��д���ʼ����
FILE* fp;
void write_sumup_html()
{
	fp = fopen("sum.html", "w+");                //��������html
	if (fp == NULL) {
		printf("\033[1;31m���ɻ���html�ļ�ʧ�ܣ��������\033[0m\n");
		system("pause");
		exit(1);
	}

	//д��htmlͷ
	fprintf(fp, "<html>\n\
<head>\n\
<title>�ڶ�������ĵ�</title>\n\
</head>\n\
<body>\n");
}