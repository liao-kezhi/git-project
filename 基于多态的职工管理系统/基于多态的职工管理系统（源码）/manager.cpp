
#pragma once
#include<iostream>
using namespace std;
#include"manager.h"

//初始化构造函数
Manager::Manager(int id, string name, int deptNum)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptNum = deptNum;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：完成BOSS交给的任务，并将任务下发给员工" << endl;
}

//获取岗位名称
string Manager::GetDeptName()
{
	return string("经理");
}
