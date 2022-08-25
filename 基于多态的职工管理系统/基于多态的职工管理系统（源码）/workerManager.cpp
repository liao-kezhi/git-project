#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//���1.�ļ�����������ж�
	if (! ifs.is_open())
	{
		//cout << "�ļ�������" << endl;		//�������
		this->m_EmpNum = 0;		//��ʼ������
		this->m_EmpArray = NULL;	//��ʼ������
		this->m_FileIsEmpty = true;  //��ʼ���ļ�β�ձ�־
		ifs.close();  //�ر��ļ�
		return;
	}

	//���2.�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;		//��ȡ�ļ��еĵ�һ���ַ�
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	//���3���ļ����ڣ����Ҽ�¼��Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;	//���Դ���
	this->m_EmpNum = num;		//���³�Ա����

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "ְ��������" << this->m_EmpArray[i]->m_Name
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->DeptNum << endl;
	//}
}

//չʾ�˵�
void WorkerManager:: Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager:: exitSystem()
{
	cout << "��ӭ����´�ʹ��" << endl;
	system("pause");
	exit(0);	//�˳�����
}


//����ְ��
void WorkerManager::Add_Emp()
{
	cout << "������Ҫ���ְ����������" << endl;
	int addNum = 0;//�����û�����������

	cin >> addNum;
	if (addNum>0)
	{
		//���ְ����Ϣ
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С=ԭ��¼����+���������

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݣ������õ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this ->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name; //ְ������
			int dSelect;	//����ѡ��
			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			while (this->IsExist(id) != -1)
			{
				cout << "�ñ�ŵ�ְ���Ѿ����ڣ�����������" << endl;
				cin >> id;
			}

			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			//��ְ��ָ�뿪�ٵ�����
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

			//������ְ����Ϣ�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�,�����ͷ�Ҫ��������[]
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//����Ϣ���浽�ļ���
		this->save();
	}
	else
	{
		cout << "���ְ����������Ϊ0" << endl;
	}
	system("pause");
	system("cls");
}

//���溯��
void WorkerManager::save()
{
	//1������ͷ�ļ�  fstream

	//2������������
	ofstream ofs;

	//3.ָ���򿪷�ʽ:������ķ�ʽ���ļ� -- д�ļ�
	ofs.open(FILENAME, ios::out);

	//4��д����
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptNum << endl;
	}

	//5.�ر��ļ�
	ofs.close();
}

//ͳ������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int dept;

	int num = 0;

	while (ifs>>id&&ifs>>name && ifs>>dept)//��ȡһ������
	{
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept;

	int index = 0;//��¼����ԭ��������
	while (ifs >> id && ifs>>name && ifs>> dept)
	{
		Worker* worker = NULL;
		if (dept == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dept);
		}
		else if (dept == 2)//����
		{
			worker = new Manager(id, name, dept);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dept);
		}
		this->m_EmpArray[index ] = worker;
		index++;
	}

	//�ر��ļ�
	ifs.close();
}

//��ʾְ����Ϣ
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


//�ж�ְ���Ƿ����  ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;	//һ��ʼ���϶�ְ��������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//�ҵ�ְ��
			index = i;
			break;		//�˳�ѭ��
		}
	}
	return index;  //����id�������е�λ��
}


//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;  //���������м�¼��Ա����
			this->save();		//������ͬ�����µ��ļ���

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

		system("pause");	//�����������
		system("cls");		//��������
	}
}


//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ�������ͷŸ�ְ�����ڴ�
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "���ҵ���" << id << "��ְ������������ְ����ţ�" << endl;
			cin >> newId;

			cout << "�������µ�������" << endl;
			cin >> newName;

			cout << "�������¸�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;

			//�����ݱ��浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//���ֲ��ҷ�ʽ
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1������ְ����Ž��в���" << endl;
		cout << "2������ְ���������в���" << endl;
		int select;
		cin >> select;

		if (select ==1)//����ְ����Ų���
		{
			cout << "������Ҫ����ְ���ı�ţ�" << endl;
			int id;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret==-1)
			{
				cout << "��Ҫ���ҵ�ְ��������" << endl;
				//return;
			}
			else
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}

		}
		else if (select == 2)//����ְ����������
		{
			bool flag = false;//����Ƿ���ҵ�ְ��
			string name;
			cout << "������Ҫ����ְ����������" << endl;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "���ҳɹ�����ְ����ϢΪ��" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//��ʾ��Ϣ
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}

	//������ϣ���������
	system("pause");
	system("cls");
}

//ְ������
void WorkerManager::Sort_Emp()
{
	//���ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ����Ҫ����ķ�ʽ��" << endl;
		cout << "1������ְ����Ž�������" << endl;
		cout << "2������ְ����Ž��н���" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;

			for (int j = minOrMax+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
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

		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->Show_Emp();

	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ�����ְ���ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select;
	cin >> select;
	if (select==1)
	{
		//��ģʽ�� ios::trunc  �������ɾ���ļ������´���
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
			cout << "�ɹ���գ�" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		//ɾ��������ÿһ��ְ������
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//ɾ����������ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
