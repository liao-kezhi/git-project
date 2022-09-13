#pragma once
#pragma once
#include"boss.h"

//初始化构造函数
Boss::Boss(int id, string name, int deptNum)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptNum = deptNum;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->GetDeptName()
		<< "\t岗位职责：给经理下发任务，管理公司事务" << endl;
}

//获取岗位名称
string Boss::GetDeptName()
{
	return string("老板");
}