#pragma once//防止头文件重复包含
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
	//构造函数
	WorkManager();

	//展示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker**m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//按照职工的编号判断职工是否存在，若存在则返回职工在数组中的位置，若不存在则返回-1
	int IsExist(int id);

	//删除员工
	void Del_Emp();

	//析构函数
	~WorkManager();


};

