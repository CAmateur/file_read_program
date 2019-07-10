#pragma once
#include<iostream>
#include<set>	
#include<fstream>
#include<string>
#include<Windows.h>
#include<memory>
#include<iomanip>
using namespace std;
class file_operation
{
public:
	file_operation(string &file_name, int x, int y, int show_x = 50);//默认值一定要在声明处出现定义内不能出现
	~file_operation();
	bool read_up();
	bool read_down();
	bool is_open();
	void clear();
private:
	void puts_hex();
	void puts_chars();
	void get_cursor(int &x, int &y);
	void set_cursor(int x, int y);
private:
	int axis_horizontal;
	int axis_vertical;
	int buffer_size;
	int show_horizontal;
	int char_show_x;
	int char_show_y;
	int hex_show_x;
	int hex_show_y;
	int read_surplus_size;
	int file_size;
	fstream file;
	shared_ptr<byte> buffer;
	string name;
	set<char> except_for;
};

