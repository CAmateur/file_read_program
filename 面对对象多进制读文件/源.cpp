#include<iostream>
#include"file_operation.h"
using namespace std;

void tip()
{
	cout << "d(down)往下翻页，u(up)往上翻页，q(quit)退出读此文件,c(clear)清空屏幕" << endl;
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
			cout << "文件读取不成功!请重新输入文件路径。" << endl;
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
			case 'd':if (!read_file->read_down()) cout << "已经读到最地部" << endl; break;
			case 'u':if (!read_file->read_up()) cout << "已经读到最顶部" << endl; break;
			case 'c':read_file->clear(); break;
			default:cout << "没有此命令!" << endl; break;
			}
		}
		read_file.reset();
	}
	system("pause");
	return 0;
}