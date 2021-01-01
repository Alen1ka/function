#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
using namespace std;

string str;
int z = 0;
string path = "function.txt";

int know_size_mass()
{
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			(file >> str).get();
			auto pos = str.find(";");
			if (pos != string::npos)
			{
				string x = str.substr(0, pos);
				string rez = str.substr(pos + 1);
			}
			z++;
		}
	}
	else{ cout << "Файл не существует" << endl; }
	file.close();
}
int input_data()
{
	string *mas_x = new string[z];
	string *mas_rez = new string[z];

	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		for (int i = 0; i < z; i++)
		{
			(file >> str).get();
			auto pos = str.find(";");
			if (pos != string::npos)
			{
				string x = str.substr(0, pos);
				string rez = str.substr(pos + 1);
				mas_x[i] = x;
				mas_rez[i] = rez;
			}
		}
	}
	else
		cout << "Файл не существует" << endl;
	file.close();
}

int output_data()
{
	char k;
	for (int i = 0; i < z; i++)
	{
		const char * _x = mas_x[i].c_str();
		double x = atof(_x);

		if (x > 2){
			ofstream file("function1.csv", ios::app);
			int f_x = sqrt(x - 3);
			if (mas_rez[i] == "NaN"){
				int f_x = sqrt(x - 3);
				k = '-';
			}
			else{
				const char * _rez = mas_rez[i].c_str();
				double rez = atof(_rez);
				if (f_x == rez) k = '+';
				else k = '-';
			}
			file << mas_x[i] << ";" << mas_rez[i] << ";" << f_x << ";" << k << endl;
		}
		else
		{
			ofstream file("function1.csv", ios::app);
			string f_x = "NaN";
			if (f_x == mas_rez[i]) k = '+';
			else k = '-';
			file << mas_x[i] << ";" << mas_rez[i] << ";" << f_x << ";" << k << endl;
		}
	}
	system("pause");
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	know_size_mass();
	input_data();
	output_data();
}