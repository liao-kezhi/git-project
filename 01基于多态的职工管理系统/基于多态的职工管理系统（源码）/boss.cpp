#pragma once
#pragma once
#include"boss.h"

//��ʼ�����캯��
Boss::Boss(int id, string name, int deptNum)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptNum = deptNum;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->GetDeptName()
		<< "\t��λְ�𣺸������·����񣬹���˾����" << endl;
}

//��ȡ��λ����
string Boss::GetDeptName()
{
	return string("�ϰ�");
}