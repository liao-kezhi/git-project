
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//������
class Manager :public Worker
{
public:
	//��ʼ�����캯��
	Manager(int id, string name, int DeptNum);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string GetDeptName();
};