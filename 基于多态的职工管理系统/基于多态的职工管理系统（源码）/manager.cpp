
#pragma once
#include<iostream>
using namespace std;
#include"manager.h"

//��ʼ�����캯��
Manager::Manager(int id, string name, int deptNum)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptNum = deptNum;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ�����BOSS���������񣬲��������·���Ա��" << endl;
}

//��ȡ��λ����
string Manager::GetDeptName()
{
	return string("����");
}
