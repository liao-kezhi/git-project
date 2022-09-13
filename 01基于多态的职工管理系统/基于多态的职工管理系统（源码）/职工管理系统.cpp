#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

//测试代码

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	Worker* manager = new Manager(2, "李四", 2);
	manager->showInfo();
	delete manager;

	Worker* boss = new Boss(3, "王五", 3);
	boss->showInfo();
	delete boss;
}

int main()
{
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//先展示菜单
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;		//接收用户的功能

		switch (choice)
		{
		case 0://退出程序
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		//	//测试
		//{	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "职工存在" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工不存在" << endl;
		//	}
		//	break; 
		//}
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}