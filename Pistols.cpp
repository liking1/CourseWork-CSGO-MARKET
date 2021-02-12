#include "Pistols.h"
#include <Windows.h>
#include <algorithm>
#include <fstream>

void Pistols::input()
{
	cin.ignore(32767, '\n');
	cout << "ENTER MODEL NAME : ";
	cin >> p.model_;
	cout << "ENTER PAINT : ";
	cin >> p.type_;
	cout << "ENTER FLOAT VALUE : ";
	cin >> p.f_value;
	cout << "ENTER MAX BULLETS : ";
	cin.ignore();
	cin >> p.MAX_BULLETS;
	cout << "ENTER RARE : ";
	cin >> p.rare_;
	cout << "ENTER PRICE : ";
	cin >> p.price_;
	ofstream fout("Pistol.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "~~~~~~~~~~~~~~" << endl;
		fout << "Name          " << p.model_ << endl;
		fout << "Type          " << p.type_ << endl;
		fout << "Float value   " << p.f_value << endl;
		fout << "Max Bullets   " << p.MAX_BULLETS << endl;
		fout << "Paint         " << p.paint_ << endl;
		fout << "Rare          " << p.rare_ << endl;
		fout << "~~~~~~~~~~~~~~" << endl;
		fout << endl;
		cout << "DATA WRITTENT SUCCESSFULY" << endl;
		Sleep(500);
		print();
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
}

void Pistols::showSkin()
{
	string line;
	ifstream myfile("Pistol.csv");
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
}

void Pistols::buySkin()
{
	vector<string> result;
	string name, res_main, s;
	cin.ignore(32767, '\n');
	cout << "Name of PISTOL: ";
	getline(cin, name);
	res_main = "Name          " + name;
	ifstream fileIn("Pistol.csv");
	if (!fileIn.is_open())
	{
		return;
	}
	while (getline(fileIn, s))
	{
		if (s.find(name) != string::npos) {
			for (int i = 0; i < 7; ++i) {
				getline(fileIn, s);
			}
		}
		else
		{
			result.push_back(s);
		}

	}

	fileIn.close();
	ofstream fileOut("Pistol.csv");
	for (auto& i : result) {
		fileOut << i << endl;
	}
	fileOut.close();
	PAUSE;
}

void Pistols::setPaintSkin(const string& type)
{
	if (!type.empty())
		this->p.type_ = type;
	else
		ERROR;
}


void Pistols::setModel(const string& model)
{
	if (!model.empty())
		this->p.model_ = model;
	else
		ERROR;
}

void Pistols::setPaint(const string& paint)
{
	if (!paint.empty())
		this->p.paint_ = paint;
	else
		ERROR;
}

void Pistols::setMaxBullets(const size_t& max)
{
	if (max != 0)
		this->p.MAX_BULLETS = max;
	else
		ERROR;
}

void Pistols::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->p.rare_ = rare;
	else
		ERROR;
}

void Pistols::setFValue(const float& f)
{
	if (f != 0)
		this->p.f_value = f;
	else
		ERROR;
}

void Pistols::setSeler(const bool& s)
{
	this->p.isSilencer = s;
}

void Pistols::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->p.price_ = price;
	else
		ERROR;
}

string Pistols::getName() const
{
	return p.model_;
}

void Pistols::sortByName()
{
	system("cls");
	string answer;
	cout << "Enter Pistol : " << endl;
	cin >> answer;
	if (answer == "pistol" || answer == "Pistol")
	{
		string nameFile = "Pistol.csv";
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


void Pistols::print() const
{
	CLEAN;
	cout << "~~~~~~~~PISTOL INFO~~~~~~~" << endl;
	cout << "Name of pistol :    " << p.model_ << endl;
	cout << "Paint of pistol :   " << p.type_ << endl;
	cout << "Float of pistol :   " << p.f_value << endl;
	cout << "Max bullets :       " << p.MAX_BULLETS << endl;
	cout << "Rare of pistol :    " << p.rare_ << endl;
	cout << "Price of pistol:    " << p.price_ << "$" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	PAUSE;
	CLEAN;
}