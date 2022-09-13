#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//情况1.文件不存在情况判断
	if (! ifs.is_open())
	{
		//cout << "文件不存在" << endl;		//测试输出
		this->m_EmpNum = 0;		//初始化人数
		this->m_EmpArray = NULL;	//初始化数组
		this->m_FileIsEmpty = true;  //初始化文件尾空标志
		ifs.close();  //关闭文件
		return;
	}

	//情况2.文件存在，并且没有记录
	char ch;
	ifs >> ch;		//读取文件中的第一个字符
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	//情况3：文件存在，并且记录不为空
	int num = this->get_EmpNum();
	cout << "职工个数为：" << num << endl;	//测试代码
	this->m_EmpNum = num;		//更新成员属性

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "职工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "部门编号：" << this->m_EmpArray[i]->DeptNum << endl;
	//}
}

//展示菜单
void WorkerManager:: Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager:: exitSystem()
{
	cout << "欢迎你的下次使用" << endl;
	system("pause");
	exit(0);	//退出程序
}


//增加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入要添加职工的数量：" << endl;
	int addNum = 0;//保存用户的输入数量

	cin >> addNum;
	if (addNum>0)
	{
		//添加职工信息
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间大小=原纪录人数+新添加人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝得到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this ->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name; //职工姓名
			int dSelect;	//部门选择
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			while (this->IsExist(id) != -1)
			{
				cout << "该编号的职工已经存在，请重新输入" << endl;
				cin >> id;
			}

			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			//将职工指针开辟到堆区
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			//将创建职工信息，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间,数组释放要加中括号[]
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//将信息保存到文件中
		this->save();
	}
	else
	{
		cout << "添加职工人数不能为0" << endl;
	}
	system("pause");
	system("cls");
}

//保存函数
void WorkerManager::save()
{
	//1、包含头文件  fstream

	//2、创建流对象
	ofstream ofs;

	//3.指定打开方式:以输出的方式打开文件 -- 写文件
	ofs.open(FILENAME, ios::out);

	//4、写内容
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptNum << endl;
	}

	//5.关闭文件
	ofs.close();
}

//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dept;

	int num = 0;

	while (ifs>>id&&ifs>>name && ifs>>dept)//读取一行数据
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept;

	int index = 0;//记录表中原有数据量
	while (ifs >> id && ifs>>name && ifs>> dept)
	{
		Worker* worker = NULL;
		if (dept == 1)//普通员工
		{
			worker = new Employee(id, name, dept);
		}
		else if (dept == 2)//经理
		{
			worker = new Manager(id, name, dept);
		}
		else//老板
		{
			worker = new Boss(id, name, dept);
		}
		this->m_EmpArray[index ] = worker;
		index++;
	}

	//关闭文件
	ifs.close();
}

//显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//判断职工是否存在  如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;	//一开始先认定职工不存在
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;
			break;		//退出循环
		}
	}
	return index;  //返回id在数组中的位置
}


//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//说明职工存在，并且要删除index位置上的职工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;  //更新数组中记录人员个数
			this->save();		//将数据同步更新到文件中

			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}

		system("pause");	//按任意键继续
		system("cls");		//清屏操作
	}
}


//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工，先释放该职工的内存
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查找到：" << id << "号职工，请输入新职工编号：" << endl;
			cin >> newId;

			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			cout << "请输入新岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;

			//将数据保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//两种查找方式
		cout << "请选择查找方式：" << endl;
		cout << "1、按照职工编号进行查找" << endl;
		cout << "2、按照职工姓名进行查找" << endl;
		int select;
		cin >> select;

		if (select ==1)//按照职工编号查找
		{
			cout << "请输入要查找职工的编号：" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret==-1)
			{
				cout << "你要查找的职工不存在" << endl;
				//return;
			}
			else
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}

		}
		else if (select == 2)//按照职工姓名查找
		{
			bool flag = false;//标记是否查找到职工
			string name;
			cout << "请输入要查找职工的姓名：" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "查找成功，该职工信息为：" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//提示信息
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}

	//查找完毕，进行清屏
	system("pause");
	system("cls");
}

//职工排序
void WorkerManager::Sort_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择你要排序的方式：" << endl;
		cout << "1、按照职工编号进行升序" << endl;
		cout << "2、按照职工编号进行降序" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;

			for (int j = minOrMax+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}

			}

			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->Show_Emp();

	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空职工文件？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;

	int select;
	cin >> select;
	if (select==1)
	{
		//打开模式： ios::trunc  如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
			ofs.close();

			if (this->m_EmpArray !=NULL)
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i] != NULL)
					{
						delete this->m_EmpArray[i];
					}
				}
				this->m_EmpNum = 0;
				this->m_EmpArray = NULL;
				this->m_FileIsEmpty = true;
			}
			cout << "成功清空！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		//删除堆区的每一个职工对象
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
