#pragma once
#include"employee.h"

//��ʼ�����캯��
Employee::Employee(int id,string name,int deptNum)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptNum = deptNum;
}

//��ʾ������Ϣ
 void Employee::showInfo()
{
	 cout << "ְ����ţ�" << this->m_Id
		 << "\tְ��������" << this->m_Name
		 << "\t��λ��" << this->GetDeptName()
		 << "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
 string Employee::GetDeptName()
{
	 return string("��ͨԱ��");
}