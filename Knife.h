#pragma once
#include "Shop.h"
#include <fstream>
#include <Windows.h>
#include <string>

struct CData
{
	string name_, rare_, type_, paint_;
	float f_value_;
	size_t price_;
};

class Knife : public Skin
{
public:
	Knife(const string& type, const string& rare, const size_t& price, const float& f, const string& sortN)
	{
		setPaintSkin(type);
		setRareSkin(rare);
		//setPaint(paint);
		setPriceSkin(price);
		setFValue(f);
		//sortByName(name);
	}
	Knife() = default;
	void input() override;
	void showSkin() override;
	void buySkin() override;
	//void setPaint(const string& paint);
	void setPaintSkin(const string& type) override;
	void setRareSkin(const string& rare) override;
	void setFValue(const float& f) override;
	void setPriceSkin(const size_t& price) override;
	void setName(const string& name) ;
	void sortByName();
	string getName() const;
	string getPaint() const;
	string getRareSkin() const;
	bool operator<(const Skin* obj) const;
	float getFValue() const;
	const size_t getPriceSkin() const;

	void print() const override;
private:
	vector<Skin*> knives;
	CData product;
	CData data_;
};