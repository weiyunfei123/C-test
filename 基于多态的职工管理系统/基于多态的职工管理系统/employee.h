//��ͨԱ��ͷ�ļ�
#pragma once
#include <iostream>;
using namespace std;
#include "worker.h"


class Employee :public Worker
{
public:
	//���캯��
	Employee(int id,string name,int dId);

	//��ʾ������Ϣ
	void  showInfo() ;

	//��ȡ��λ����
	string getDeptName();
};