#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkManager
{
public:
	//���캯��
	WorkManager();

	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker**m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//����ְ���ı���ж�ְ���Ƿ���ڣ��������򷵻�ְ���������е�λ�ã����������򷵻�-1
	int IsExist(int id);

	//ɾ��Ա��
	void Del_Emp();

	//��������
	~WorkManager();


};

