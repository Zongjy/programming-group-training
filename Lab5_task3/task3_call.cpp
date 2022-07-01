#include"pch.h"
#include"task3_data.h"
#include"task3_call.h"
//函数功能：调用子程序1
void call_task1()
{
	char command[MAX_LEN];
	memset(command, 0, sizeof(command));
	sprintf_s(command, "%s %s %d","Lab5_task1.exe", stac.filename1, 1);
	if (system(command) != 0)
	{
		printf("\033[1;31m调用子程序1失败，程序结束\033[0m\n");
		system("pause");
		exit(1);
	}
}


//函数功能：调用子程序2
void call_task2()
{
	char command[MAX_LEN];
	char tem1[MAX_LEN];            //tem1是用于得到对应统计文档的html结果的地址的中转变量
	char* ret;
	ret = strrchr(stac.filename1, '/');
	char suffix[] = {'h','t','m','l'}; //后缀
	memset(command, 0, sizeof(command));
	memset(tem1, 0, sizeof(tem1));
	memset(stac.filename2, 0, sizeof(stac.filename2));
	int i=strlen(ret)-4;
	strcpy(tem1, ret + 1);
	strcpy(stac.filename2, "result/");          
	strcat(stac.filename2, tem1);             
	for (int j = 0; j < 4; j++)
	{
		tem1[i] = suffix[j];             //更改文件名后缀，如art.txt -> art.html
		i++;
	}
	
	strcpy(stac.filename3, "html/");       //补充目录信息
	strcat(stac.filename3, tem1); 
	if(option==2)
		sprintf(command, "%s %s %d", "Lab5_task2.exe", stac.filename2, 1);
	else if(option==1)
		sprintf(command, "%s %s %d", "Lab5_task2.exe",stac.filename2, 0);
	if (system(command) != 0)
	{
		printf("\033[1;31m调用子程序2失败，程序结束\033[0m\n");
		system("pause");
		exit(1);
	}
}