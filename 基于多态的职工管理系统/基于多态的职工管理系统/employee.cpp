#include "employee.h"

Employee::Employee(int id, string name, int dId)//���캯��
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:  " << this->m_Id
		<< "\tְ��������  " << this->m_Name
		<< "\t��λ��  " << this->getDeptName()
		<< "\t��λְ����ɾ�����������"<< endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}