#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//��ͨԱ����
class Employee :public Worker
{
public:
	//��ʼ�����캯��
	Employee(int id, string name, int DeptNum);

	//��ʾ������Ϣ
	 void showInfo() ;

	//��ȡ��λ����
	 string GetDeptName() ;
};