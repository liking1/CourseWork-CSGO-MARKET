#include "Gun.h"
#include <Windows.h>
#include <algorithm>
#include <fstream>

void Gun::input()
{
	cin.ignore(32767, '\n');
	cout << "ENTER TYPE : ";
	cin >> d.type_;
	//cout << "ENTER MODEL : ";
	//cin >> d.model_;
	cout << "ENTER FLOAT VALUE : ";
	cin >> d.f_value;
	cout << "ENTER MAX BULLETS : ";
	cin.ignore();
	cin >> d.MAX_BULLETS;
	cout << "ENTER PAINT : ";
	cin >> d.paint_;
	cout << "ENTER RARE : ";
	cin >> d.rare_;
	cout << "ENTER PRICE : ";
	cin >> d.price_;
	ofstream fout("Gun.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "~~~~~~~~~~~~~~" << endl;
		fout << "Name         " << d.model_ << endl;
		fout << "Float value   " << d.f_value << endl;
		fout << "Max Bullets   " << d.MAX_BULLETS << endl;
		fout << "Paint         " << d.paint_ << endl;
		fout << "Rare          " << d.rare_ << endl;
		fout << "~~~~~~~~~~~~~~" << endl;
		cout << "DATA WRITTENT SUCCESSFULY" << endl;
		Sleep(500);
		print();
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
}

void Gun::showSkin()
{
	string line;
	ifstream myfile("Gun.csv");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << line << endl;
		}
	}
	myfile.close();
	PAUSE;
	CLEAN;
}

void Gun::buySkin()
{
	vector<string> result;
	string name, res_main, s;
	cin.ignore(32767, '\n');
	cout << "Name of GUN: ";
	getline(cin, name);
	res_main = "Name          " + name;
	ifstream fileIn("Gun.csv");
	if (!fileIn.is_open())
	{
		return;
	}
	while (getline(fileIn, s))
	{
		if (s.find(name) != string::npos) {
			for (int i = 0; i < 6; ++i) {
				getline(fileIn, s);
			}
		}
		else
		{
			result.push_back(s);
		}

	}

	fileIn.close();
	ofstream fileOut("Gun.csv");
	for (auto& i : result) {
		fileOut << i << endl;
	}
	fileOut.close();
	PAUSE;
}

void Gun::setPaintSkin(const string& type)
{
	if (!type.empty())
		this->d.type_ = type;
	else
		ERROR;
}

void Gun::setModel(const string& model)
{
	if (!model.empty())
		this->d.model_ = model;
	else
		ERROR;
}

void Gun::setPaint(const string& paint)
{
	if (!paint.empty())
		this->d.paint_ = paint;
	else
		ERROR;
}

void Gun::setMaxBullets(const size_t& max)
{
	if (max != 0)
		this->d.MAX_BULLETS = max;
	else
		ERROR;
}

void Gun::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->d.rare_ = rare;
	else
		ERROR;
}

void Gun::setFValue(const float& f)
{
	if (f != 0)
		this->d.f_value = f;
	else
		ERROR;
}

void Gun::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->d.price_ = price;
	else
		ERROR;
}

void Gun::sortByName()
{
	system("cls");
	string answer;
	cout << "Enter Gun : " << endl;
	cin >> answer;
	if (answer == "gun" || answer == "Gun")
	{
		string nameFile = "Gun.csv";
		vector<string> buff;
		{

			string line;
			ifstream file(nameFile);
			while (getline(file, line)) {
				buff.push_back(line);
				if (line == "exit") {
					system("cls");
				}
			}
		}
		sort(buff.begin(), buff.end());
		{
			ofstream file(nameFile, ios::out | ios::trunc);
			for (auto& str : buff)
				file << str << endl;
			cout << "File was sorted!" << endl;
			cout << "Enter 'exit' for exit apps" << endl;
		}
	}
}


void Gun::print() const
{
	CLEAN;
	cout << "~~~~~~~~GUN INFO~~~~~~~" << endl;
	cout << "Type : " << d.type_ << endl;
	cout << "Model : " << d.model_ << endl;
	cout << "Paint : " << d.paint_ << endl;
	cout << "Rare : " << d.rare_ << endl;
	cout << "Max bullets : " << d.MAX_BULLETS << endl;
	cout << "Float value : " << d.f_value << endl;
	cout << "Price : " << d.price_ << "$" << endl;
	cout << "_________________" << endl;
	PAUSE;
	CLEAN;
}