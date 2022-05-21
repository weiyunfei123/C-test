#include "workManager.h"


WorkManager::WorkManager()
{
	////��ʼ������
	//this->m_EmpNum = 0;

	//this->m_EmpArray = NULL;


	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	//1���ļ����������
	if (!ifs.is_open())
	{
		//�������
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ����ڣ���¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ������ݣ��浽������
	this->init_Emp();

	//���Դ���
	for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ���ţ�  " << this->m_EmpArray[i]->m_Id
		     << "  ְ�������� " << this->m_EmpArray[i]->m_Name
		     << "  ���ű�ţ�  " << this->m_EmpArray[i]->m_DeptId << endl;
	}
	


}

//չʾ�˵�
void WorkManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkManager::Add_Emp()
{
	cout << "���������ְ���������� " << endl;

	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����¼����+��������
		
		//�����¿ռ�
		Worker ** newSpace = new Worker*[newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker*worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;
		
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ����" << endl;

		//�ɹ�����ļ���Ӧ�������ļ���
		this->save();

		

		
	}
	else
	{
		cout << "�������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� --д�ļ�

	//��ÿ����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "  "
			<< this->m_EmpArray[i]->m_Name << "  "
			<< this->m_EmpArray[i]->m_DeptId<< endl;
	}

	//�ر��ļ�
	ofs.close();
}


 //ͳ���ļ�������
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ���ļ�

	int id;
	string name;
	int dId;
	
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;

}


//��ʼ��Ա��
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker*worker = NULL;
		//���ݲ�ͬ�Ĳ���ID������ͬ�Ķ���
		if (dId == 1)//1.��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//2.����
		{
			worker = new Manager(id, name, dId);
		}
		else//3.�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾְ��
void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//ְ���Ƿ���ڵĺ���
int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}


//ɾ��Ա��
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "����������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//˵��index�ϵ�λ��������Ҫɾ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpArray--;

			this->save();//ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}

	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
