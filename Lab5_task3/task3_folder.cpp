#include"pch.h"
#include"task3_run.h"
#include"task3_folder.h"
#include"task3_data.h"
#include"task3_sumup_html.h"
#include"task3_call.h"
//�������ܣ�����������1,2����һ�����ļ����е�Ӣ��txt�ļ������ƻ���html
void process_folder()
{
	//���֪ʶ�㣺C���Զ�ȡָ���ļ����µ������ļ�
	struct _finddata_t fileinfo;  //�ļ�������Ϣ�ṹ��
	intptr_t fHandle;   //�����ļ����
	char tem[MAX_LEN];
	int cnt=0;
	strcpy(tem, stac.dirname);
	strcat(tem, "/*.txt");     //Ϊ��findfirst��ʾĿ���ļ���ʽʱʹ��
	if ((fHandle = _findfirst(tem, &fileinfo))==-1L)
	{
		printf("\033[1;31m��ǰĿ¼��û��txt�ļ�,�������\033[0m\n");
		system("pause");
		exit(1);
	}
	else
	{
		write_sumup_html();  //����sum.html
		double start = clock();
		do{
			cnt++;
			strcpy(stac.filename1, stac.dirname);
			strcat(stac.filename1, "/");
			strcat(stac.filename1, fileinfo.name);
			call_task1();
			call_task2();
			//¼����ļ���ͳ���ĵ����ܽ�html��
			fprintf(fp, "<a href=\"%s\">��ת��%s��ͳ��ҳ��</a>\n<br>\n<br>\n", stac.filename3, fileinfo.name);
		} while (_findnext(fHandle, &fileinfo) == 0);

		double end = clock();
		printf("��������3����������1ͳ�ƴ��ļ��й���ʱΪ \033[1;33m% lf����\033[0m\n", ((double)end - (double)start));
		fprintf(fp, "</body>\n</html>\n"); 
	}
	_findclose(fHandle);
	fclose(fp);
}