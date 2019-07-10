#include<iostream>
#include"file_operation.h"
using namespace std;

void tip()
{
	cout << "d(down)���·�ҳ��u(up)���Ϸ�ҳ��q(quit)�˳������ļ�,c(clear)�����Ļ" << endl;
	Sleep(5000);
	system("cls");
}



int main(int argc, char**argv)
{
	string file_name;
	char tem_char;
	tip();
	while (cin >> file_name)
	{
		shared_ptr < file_operation >read_file = make_shared<file_operation>(file_name, 16, 8);
		if (!read_file->is_open())
		{
			cout << "�ļ���ȡ���ɹ�!�����������ļ�·����" << endl;
			Sleep(2000);
			system("cls");
			file_name.clear();
			continue;
		}
		while (cin >> tem_char)
		{
			if (tem_char == 'q')
				break;
			switch (tem_char)
			{
			case 'd':if (!read_file->read_down()) cout << "�Ѿ�������ز�" << endl; break;
			case 'u':if (!read_file->read_up()) cout << "�Ѿ��������" << endl; break;
			case 'c':read_file->clear(); break;
			default:cout << "û�д�����!" << endl; break;
			}
		}
		read_file.reset();
	}
	system("pause");
	return 0;
}