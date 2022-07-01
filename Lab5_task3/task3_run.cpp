#include"pch.h"
#include"task3_run.h"
#include"task3_data.h"
#include"task3_call.h"
#include"task3_folder.h"
#include"task3_sumup_html.h"
STAC stac;
int option;
char menu[] = "\033[1;34m������������С���ʵ��5����\033[0m\n\
\t\033[1;36m1.�Ե���Ӣ���ĵ�����ͳ��\033[0m\n\
\t\033[1;36m2.������Ӣ���ĵ�����ͳ��\033[0m\n\
\t\033[1;36m0.�˳�\033[0m\n\
\033[1;36m��������Ҫִ�еĳ�����ţ�\033[0m\n";
void run()
{
	while (1)
	{
		printf("%s", menu);                  //�˵�����
		scanf("%d", &option);
		if (option == 0)
		{
			printf("�������");
			return;
		}
		else if (option == 1)
		{
			printf("\033[1;33m��ǰ���ܴ�����Ӣ���ĵ�\033[0m\n");
			printf("��������Ҫ�����Ӣ���ĵ�·�������Ի����·������ ./data/article.txt����");
			scanf("%s", stac.filename1);
			double start = clock();
			call_task1();
			double end = clock();
			call_task2();
			printf("��������3����������1ͳ�ƴ��ĵ���ʱΪ\033[1;33m%lf����\033[0m\n", ((double)end - (double)start));
		}
		else if (option == 2)
		{
			printf("\033[1;34m��ǰ���ܴ���һ���ļ��������е�Ӣ���ĵ�\033[0m\n");
			printf("��������Ҫ������ļ���·��������·�������·��,�� ./data����");
			scanf("%s", stac.dirname);
			process_folder();
			//����Ĭ��������򿪻���html
			HINSTANCE r = ShellExecute(NULL, TEXT("open"), L"sum.html", NULL, NULL, SW_SHOWNORMAL);
			if ((DWORD)r <= 32)
			{
				printf("\033[1;31m����html����ҳ��ʧ�ܣ��������\033[0m\n");
				system("pause");
				exit(1);
			}
		}
		else
		{
			printf("033[1;31m��������ȷ�����\033[0m\n");
		}
	}
}

