/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	task2_fun.cpp
��������:
	���ܺ���ģ�飬��ż���ļ���������ģʽ������html�ļ�����ʾ�������ع�������ĺ���
ģ����ʷ:
	������2022��5��31�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "task2_data.h"
#include "task2_fun.h"

/*
* �������ƣ�isalpha
* �������ܣ��ж��ַ��Ƿ�ΪӢ����ĸ(��Сд����)
* ���������char: ���ж��ַ�
* ����ֵ��bool: �����Ӣ����ĸ�򷵻�true�����򷵻�false
*/
bool isalpha(char sum) {
	if ((sum <= 'z' && sum >= 'a') || (sum <= 'Z' && sum >= 'A')) return true;
	else return false;
}

/*
* �������ƣ�check_filename
* �������ܣ��ж������в����е��ļ����Ƿ���ȷ,���洢��ȷ���ļ���
* ���������char*: ���ж��ַ������ļ�����
* ����ֵ����
*/
void check_filename(char* path) {
	int flag = 1;
	if (_access(path, 0) != 0) flag = 0;
	if (flag == 0) {
		printf("����·���������ļ����ļ����󣬳����˳�\n");
		exit(EXIT_FAILURE);
	}
	//��ȡ�ļ���
	strcpy(stac.filename, path);
}

/*
* �������ƣ�check_mode
* �������ܣ��ж������в����е�����ģʽ�Ƿ���ȷ,���洢��ȷ������ģʽ��0: �Զ����չʾģʽ��1: ��Ĭ���չʾģʽ��
* ���������char*: ���ж��ַ���������ģʽ��
* ����ֵ����
*/
void check_mode(char* mode) {
	int len = strlen(mode);
	if (len != 1 || (mode[0] != '0' && mode[0] != '1')) {
		printf("�������ģʽ�������󣬳����˳�\n");
		exit(EXIT_FAILURE);
	}
	//��ȡ�ļ�ģʽ
	stac.mode = mode[0] - '0';
}

/*
* �������ƣ�read_file
* �������ܣ���ȡͳ�ƽ���ĵ���������ݣ����������ȫ�ֱ���stac��
* �����������
* ����ֵ����
*/
void read_file() {
	//�Ƚ������м�¼�����ĳ�ʼ��
	stac.blank = 0; stac.character = 0; stac.letter = 0; stac.num = 0; stac.others = 0; stac.word = 0;
	FILE* fp = fopen(stac.filename, "r");
	if (fp == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}
	//��ʼͳ�Ƹ���
	else {
		//����Ӣ���ĵ��е�Ӣ�ĵ��ʡ��ַ������֡��հ��ַ���Ӣ����ĸ�������ַ��ĸ���
		fscanf_s(fp, "%d", &stac.word);
		fscanf_s(fp, "%d", &stac.character);
		fscanf_s(fp, "%d", &stac.num);
		fscanf_s(fp, "%d", &stac.blank);
		fscanf_s(fp, "%d", &stac.letter);
		fscanf_s(fp, "%d", &stac.others);
		fscanf_s(fp, "%d", &stac.paras);
	}
	fclose(fp);
}

/*
* �������ƣ�write_file
* �������ܣ���ͳ�ƽ������html��ʽд��ͬĿ¼��html�ļ����е�ͬ��html�ļ���
* �����������
* ����ֵ����
*/
void write_file() {
	char* temp = strrchr(stac.filename, '/');
	char name[MAX_LEN] = { 0 };
	if (temp == NULL)
	{
		printf("ͳ���ļ�·�����󣬳����˳�\n");
		exit(EXIT_FAILURE);
	}
	strcpy(name, temp + 1);
	strncpy(stac.htmlname, temp + 1, MAX_LEN - 4);
	//��txt�ļ��ĺ�׺���html���ļ�
	int len = strlen(stac.htmlname);
	stac.htmlname[len - 3] = 'h', stac.htmlname[len - 2] = 't', stac.htmlname[len - 1] = 'm', stac.htmlname[len] = 'l', stac.htmlname[len + 1] = '\0';
	char path[MAX_LEN] = { 0 };
	//�����ǰĿ¼��û��html���Ŀ¼���ʹ���һ��
	strcpy(path, "./html/");
	if (_access(path, 0)) {
		_mkdir(path);
	}
	strcat(path, stac.htmlname);
	FILE* fp = fopen(path, "w+");
	if (fp == NULL) {
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	//��html�﷨д��ͳ�ƽ����������һ����Ƹ�ʽ�Ű�
	fprintf(fp, "<!DOCTYPE html>\n");
	fprintf(fp, "<html>\n<head>\n");
	fprintf(fp, "<title>�ڶ����ͳ�ƽ��</title>");
	fprintf(fp, "<link rel=\"icon\" href=\"https://s1.ax1x.com/2022/06/06/X0cgsg.jpg\">\n");
	fprintf(fp, "</head>\n<body>\n");
	fprintf(fp, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
	fprintf(fp, "<font color = red>��Ŀǰͳ�Ƶ��ļ���Ϊ:%s</font>\n", name);
	fprintf(fp, "<br>\n<hr/>\n");
	fprintf(fp, "<ul>");
	fprintf(fp, "<li>��ƪ���µ�Ӣ�ĵ��ʸ���Ϊ:%d</li>\n", stac.word);
	fprintf(fp, "<br>\n<li><font color = blue>��ƪ���µ��ַ�����Ϊ:%d</font></li>\n", stac.character);
	fprintf(fp, "<br>\n<li>��ƪ���µ����ָ���Ϊ:%d</li>\n", stac.num);
	fprintf(fp, "<br>\n<li><font color = blue>��ƪ���µĿհ��ַ�����Ϊ:%d</font></li>\n", stac.blank);
	fprintf(fp, "<br>\n<li>��ƪ���µ�Ӣ����ĸ����Ϊ:%d</li>\n", stac.letter);
	fprintf(fp, "<br>\n<li><font color = blue>��ƪ���µ������ַ�����Ϊ:%d</font></li>\n", stac.others);
	fprintf(fp, "<br>\n<li>��ƪ���µĶ������Ϊ:%d</li>\n", stac.paras);
	fprintf(fp, "</ul>");
	fprintf(fp, "</body>\n</html>\n");
	fclose(fp);
}

/*
* �������ƣ�show
* �������ܣ���������ģʽ�ڿ���̨�ն˴�ӡ��Ӧ�����
* �����������
* ����ֵ����
*/
void show() {
	//path��ʾ����·��
	char path[MAX_LEN];
	_getcwd(path, MAX_LEN);
	strcat(path, "\\html\\");
	strcat(path, stac.htmlname);
	//��char*�ַ���ת��ΪLPWSTR���ֽ��ַ������Ա�����Ϊ����windows.h�⺯���Ĳ�������
	int dwlen = strlen(path) + 1;
	//�ȼ����Ӧת����Ŀ��ֽ��ַ������ȣ�����̬�����ڴ�
	int nwlen = MultiByteToWideChar(CP_ACP, 0, path, dwlen, NULL, 0);
	LPWSTR lpszPath = (LPWSTR)malloc(nwlen * sizeof(WCHAR));
	MultiByteToWideChar(CP_ACP, 0, path, dwlen,lpszPath, nwlen);
	//δ�ܳɹ�ת��ʱ�������˳�
	if (lpszPath == 0)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	//������Զ����չʾģʽ
	if (stac.mode==0) {
		//����Ĭ���������html�ļ�
		HINSTANCE r = ShellExecute(NULL, TEXT("open"), lpszPath, NULL, NULL, SW_SHOWNORMAL);
		if ((DWORD)r <= 32)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	//����Ǿ�Ĭ���չʾģʽ
	else {
		printf("������html�ļ�\nhtml�ļ�·��Ϊ��\033[1;32m%s\033[0m\n", path);
	}
}