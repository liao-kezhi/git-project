#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"

//���Դ���

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	Worker* manager = new Manager(2, "����", 2);
	manager->showInfo();
	delete manager;

	Worker* boss = new Boss(3, "����", 3);
	boss->showInfo();
	delete boss;
}

int main()
{
	//ʵ���������߶���
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//��չʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;		//�����û��Ĺ���

		switch (choice)
		{
		case 0://�˳�����
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		//	//����
		//{	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "ְ������" << endl;
		//	}
		//	else
		//	{
		//		cout << "ְ��������" << endl;
		//	}
		//	break; 
		//}
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
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