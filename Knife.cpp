#include "Knife.h"
#include <Windows.h>
#include <algorithm>
#include <fstream>
using namespace std;

void Knife::input()
{
	cin.ignore(32767, '\n');
	cout << "ENTER NAME : ";
	cin >> data_.name_;
	cout << "ENTER FLOAT VALUE : ";
	cin >> data_.f_value_;
	cout << "ENTER RARE : ";
	cin >> data_.rare_;
	cout << "ENTER PAINT : ";
	cin >> data_.type_;
	cout << "ENTER PRICE : ";
	cin >> data_.price_;
	ofstream fout("Knife.csv", ios::out | ios::app);
	if (fout.is_open())
	{
		fout << "~~~~~~~~"<< data_.name_ << "~~~~~~~~" << endl;
		fout << data_.name_  << "\tName : " << data_.name_ << endl;
		fout << data_.name_  << "\tType : " << data_.type_ << endl;
		fout << data_.name_  << "\tFloat value : " << data_.f_value_ << endl;
		fout << data_.name_  << "\tPrice : " << data_.price_ << endl;
		fout << data_.name_  << "\tRare : " << data_.rare_ << endl;
		fout << "~~~~~~~~" << data_.name_ << "~~~~~~~~" << endl;
		fout << endl;
		cout << "DATA WRITTENT SUCCESSFULY" << endl;
		Sleep(500);
		print();
	}
	else
		cout << "Error: The file was not opened.";
	fout.close();
}

void Knife::showSkin()
{
	string line;
	ifstream myfile("knife.csv");
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

void Knife::buySkin()
{
	vector<string> result;
	string name, res_main, s;
	cin.ignore(32767, '\n');
	cout << "Name of KNIFE: ";
	getline(cin, name);
	res_main = "Name          " + name;
	ifstream fileIn("Knife.csv");
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
	ofstream fileOut("Knife.csv");
	for (auto& i : result) {
		fileOut << i << endl;
	}
	fileOut.close();
	PAUSE;
}

//void Knife::buySkin()
//{
//	vector<string> result;
//	string name, s;
//	cin.ignore(32767, '\n');
//	cout << "Name of KNIFE: ";
//	getline(cin, name);
//	ifstream fout("Knife.csv");
//	if (fout.is_open())
//	{
//		while (getline(fout, s))
//		{
//			if (s.find(name) != string::npos)
//				result.push_back(s);
//		}
//	}
//	else
//		cout << "Error: The file was not opened.";
//	fout.close();
//	ofstream fsut("Knife.csv", ofstream::out | ofstream::trunc);
//	fsut.close();
//	ofstream fomt("Knife.csv", ios::out | ios::app);
//	if (fomt.is_open())
//	{
//		for (int i = 0; i < result.size(); i++)
//			fomt << result[i] << endl;
//		cout << "Knife was bought" << endl;
//		fomt.close();
//	}
//	else
//		cout << "Error: The file was not opened.";
//	fout.close();
//	PAUSE;
//}

void Knife::setPaintSkin(const string& type)
{
	if (!type.empty())
		this->data_.type_ = type;
	else
		cerr << "error with type knife!" << endl;
}

void Knife::setRareSkin(const string& rare)
{
	if (!rare.empty())
		this->data_.rare_ = rare;
	else
		cerr << "error with rare knife!" << endl;
}

void Knife::setFValue(const float& f)
{
	if (f != 0)
		this->data_.f_value_ = f;
	else
		ERROR;

}
void Knife::setPriceSkin(const size_t& price)
{
	if (price != 0)
		this->data_.price_ = price;
	else
		cerr << "error with price knife!" << endl;
}

void Knife::setName(const string& name)
{
	this->data_.name_ = name;
}

//void Knife::sortByName()
//{
//	ifstream fileIn("Knife.csv");
//	if (!fileIn.good())
//	{
//		return;
//	}
//	Knife tmp;
//	string line;
//	getline(fileIn, line);
//
//	while (!fileIn.eof()) {
//		getline(fileIn, line);
//		line.erase(line.begin(), line.begin() + 14);
//		tmp.setName(line);
//		getline(fileIn, line);
//		line.erase(line.begin(), line.begin() + 14);
//		tmp.setPaintSkin(line);
//		getline(fileIn, line);
//		cout << "tmo: " << line << endl;
//		line.erase(line.begin(), line.begin() + 14);
//		tmp.setFValue(stof(line));
//		getline(fileIn, line);
//		line.erase(line.begin(), line.begin() + 14);
//		tmp.setPriceSkin(stoi(line));
//		getline(fileIn, line);
//		line.erase(line.begin(), line.begin() + 14);
//		tmp.setRareSkin(line);
//		getline(fileIn, line);
//		getline(fileIn, line);
//		getline(fileIn, line);
//
//		knives.push_back(&tmp);
//	}
//	sort(knives.begin(), knives.end(), [](const auto obj1, const auto* obj2) {return obj1->getName() < obj2->getName(); });
//	for (auto& i : knives)
//	{
//		i->print();
//	}
//	fileIn.close();
//	/*vector<string> sortName;
//	string sbn, name;
//	string path("Knife.csv");
//	getline(cin, name);
//	ifstream allF("Knife.csv");
//	allF.open(path);
//	if (allF.is_open())
//	{
//		sort(sortName.begin(), sortName.end());
//	}*/
//	//if (!allF.is_open())
//	//{
//	//	return;
//	//}
//	//while (getline(allF, sbn))
//	//{
//	//	if (sbn.find(name) == string::npos) {
//	//		for (int i = 0; i < 6; ++i) {
//	//			getline(allF, sbn);
//	//		}
//	//		sort(sortName.begin(), sortName.end());
//	//	}
//	//	else
//	//	{
//	//		
//	//	}
//	//}
//	//ofstream rfile("Knife.csv");
//	//for (auto& i : sortName) {
//	//	rfile << i << endl;
//	//}
//	//allF.close();
//	////ofstream fileOutt("Knife.csv");
//	////for (auto& i : sortName) {
//	////	fileOutt << i << endl;
//	////}
//	////fileOutt.close();
//	//CLEAN;
//	////sort(sortName.begin(), sortName.end());
//	//string path("Knife.csv");
//	//ifstream allF("Knife.csv", ios::out | ios::app);
//	//allF.open(path);
//	//while (true)
//	//{
//	//	sort(n.begin(), n.end());	
//	//}
//	//allF.close();
//}

void Knife::sortByName()
{
	system("cls");
	string answer;
	cout << "Enter  Knife : " << endl;
	cin >> answer;
	if (answer == "knife" || answer == "Knife")
	{
		string nameFile = "Knife.csv";
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

string Knife::getName() const
{
	return data_.name_;
}

void Knife::print() const
{
	CLEAN;
	cout << "~~~~~~~~KNIFE INFO~~~~~~~" << endl;
	cout << "Name of knife : " << data_.name_ << endl;
	cout << "Rare of knife : " << data_.rare_ << endl;
	cout << "Paint of knife : " << data_.type_ << endl;
	cout << "Float value : " << data_.f_value_ << endl;
	cout << "Price of knife : " << data_.price_ << "$" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	PAUSE;
	CLEAN;
}