
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//�ϰ���
class Boss :public Worker
{
public:
	//��ʼ�����캯��
	Boss(int id, string name, int DeptNum);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string GetDeptName();
};