#pragma once
#include<iostream>
using namespace std;
#include<string>

//ְ��������
class Worker
{
public:

	//ְ������
	//ְ�����
	int m_Id;

	//ְ������
	string m_Name;

	//���ű��
	int DeptNum;

	//����
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string GetDeptName() = 0;

	
};
