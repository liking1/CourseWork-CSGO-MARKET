#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

#define CLEAN system("cls");
#define PAUSE system("pause");
#define ERROR cerr << "Error!" << endl;

class Skin abstract
{
public:
	virtual void input() = 0; // abstract
	virtual void setPaintSkin(const string& type) = 0;
	virtual void setRareSkin(const string& rare) = 0;
	virtual void setPriceSkin(const size_t& price) = 0;
	virtual void setFValue(const float& f) = 0;
	virtual void print() const = 0;
	virtual void showSkin() = 0;
	virtual void buySkin() = 0;
	virtual string getName() const {
		return "fsd";

	};
};