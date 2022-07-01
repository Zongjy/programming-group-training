/***********************************************
������Ϣ��
	����������
	ѧ�ţ�21281163
	�༶�������2106��
ģ������:
	task1_fun.cpp
��������:
	���ܺ���ģ�飬��ż���ļ���������ģʽ��ͳ���ĵ�����ʾ�������ع�������ĺ���
ģ����ʷ:
	������2022��5��27�մ�����ģ�飬email:21281163@bjtu.edu.cn
**********************************************/

#include "pch.h"
#include "task1_data.h"
#include "task1_fun.h"

/*
* �������ƣ�isalpha
* �������ܣ��ж��ַ��Ƿ�ΪӢ����ĸ(��Сд����)
* ���������char: ���ж��ַ�
* ����ֵ��bool: �����Ӣ����ĸ�򷵻�true�����򷵻�false
*/
bool isalpha(char c)
{
	if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
		return true;
	else
		return false;
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
* �������ܣ��ж������в����е�����ģʽ�Ƿ���ȷ,���洢��ȷ������ģʽ��0: ϸ��ģʽ��1: ��Ҫģʽ��
* ���������char*: ���ж��ַ���������ģʽ��
* ����ֵ����
*/
void check_mode(char* p) {
	int sz = strlen(p);
	if (sz != 1 || (p[0] != '0' && p[0] != '1')) {
		printf("�����ģʽ�������󣬳����˳�\n");
		exit(EXIT_FAILURE);
	}
	//��ȡ�ļ�ģʽ
	stac.mode = p[0] - '0';
}

/*
* �������ƣ�read_file
* �������ܣ���ȡӢ���ĵ���������ݣ�������ͳ�ƣ����������ȫ�ֱ���stac��
* �����������
* ����ֵ����
*/
void read_file() {
	//���м�¼���ݳ�ʼ��Ϊ0
	stac.character = 0, stac.blank = 0; stac.letter = 0; stac.num = 0; stac.others = 0; stac.word = 0, stac.paras = 0;
	FILE* fp = fopen(stac.filename, "r");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ������˳�\n");
		exit(EXIT_FAILURE);
	}
	//ͳ�Ƹ���
	char ch = 'a', prech = 'b';
	while ((ch = fgetc(fp)) != EOF) 
	{
		if (ch!='\n')
			stac.character++;							//�ַ�����
		if (ch >= '0' && ch <= '9') stac.num++;			//���ָ���
		else if (isalpha(ch)) stac.letter++;			//Ӣ����ĸ����
		else if (ch == ' ' || ch == '\t') stac.blank++;	//�ո����
		else if (ch == '\n') stac.paras++;				//�������
		else stac.others++;								//�����ַ�����(�����ո�)
		//�����ʱ���ַ�����Ӣ����ĸ������������һ����Ӣ����ĸ���������һ��Ӣ�ĵ���(�������и�����ַ������)
		if (isalpha(ch) == false && isalpha(prech) == true && ch != '\'' && ch != '-') stac.word++;
		prech = ch;
		stac.paras++;
	}
	//�������һ����ĸ��Ӣ����ĸ����󵥴�����Ҫ��һ
	if (isalpha(prech)) stac.word++;
	fclose(fp);
}

/*
* �������ƣ�write_file
* �������ܣ���ͳ�ƽ�����ո�ʽ�����ͬĿ¼��result�ļ����е�ͬ���ı��ļ���
* �����������
* ����ֵ����
*/
void write_file() {
	char temp[MAX_LEN] = { 0 };
	//��鵱ǰĿ¼��û��result���Ŀ¼�����û�оʹ���һ��
	strcpy(temp, "./result/");
	if (_access(temp, 0)) {
		int r = _mkdir(temp);
	}
	//����ͳ�ƽ���ļ����ǰ׺
	if (strrchr(stac.filename, '/')) {
		strcat(temp, strrchr(stac.filename, '/') + 1);
	}
	FILE* fp = fopen(temp, "w");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ������˳�\n");
		exit(EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	int t = fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n", stac.word, stac.character, stac.num, stac.blank, stac.letter, stac.others, stac.paras);
	fclose(fp);
}

/*
* �������ƣ�show
* �������ܣ���������ģʽ�ڿ���̨�ն˴�ӡ��Ӧ�����
* �����������
* ����ֵ����
*/
void show() {
	 //ϸ��ģʽ
	if (stac.mode == 0)
	{
		printf("�����е�Ӣ�ĵ�������Ϊ��\033[1;36m%d\033[0m\n\
�����еĶ�������Ϊ��\033[1;36m%d\033[0m\n\
�����е��ַ�����Ϊ��\033[1;36m%d\033[0m\n\
�����е���������Ϊ��\033[1;36m%d\033[0m\n\
�����еĿհ��ַ�����Ϊ��\033[1;36m%d\033[0m\n\
�����е�Ӣ����ĸ����Ϊ��\033[1;36m%d\033[0m\n\
�����е������ַ�����Ϊ��\033[1;36m%d\033[0m\n", stac.word, stac.paras, stac.character, stac.num, stac.blank, stac.letter, stac.others);
	}
	 //��Ҫģʽ
	else 
	{
		//resource��ʾ��ȡ���ļ���,target��ʾ���յ��ļ�·��
		char resource[MAX_LEN], target[MAX_LEN];
		//�Ѷ�ȡ���ļ���������
		char* temp;
		if (strrchr(stac.filename, '/')) {
			temp = strrchr(stac.filename, '/');
		}
		else {
			temp = strrchr(stac.filename, '\\');
		}
		strcpy(resource, temp + 1);
		//�����մ�ŵ�λ�õ�·�����ļ���������
		char * a = _getcwd(target, MAX_LEN);
		strcat(target, "\\result\\");
		strcat(target, resource);
		printf("�����%s�ļ���ͳ��\nͳ�ƽ���ļ�·����\033[1;32m%s\033[0m\n", resource, target);
	}
}