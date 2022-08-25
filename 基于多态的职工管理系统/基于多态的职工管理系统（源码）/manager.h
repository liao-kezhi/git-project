
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//经理类
class Manager :public Worker
{
public:
	//初始化构造函数
	Manager(int id, string name, int DeptNum);

	//显示个人信息
	void showInfo();

	//获取岗位名称
	string GetDeptName();
};