#pragma once

#include "Shop.h"
#include <Windows.h>

struct PData
{
	string model_, type_, paint_, rare_;
	size_t MAX_BULLETS, price_;
	bool isSilencer = false;
	float f_value;
};

class Pistols : public Skin
{
public:
	Pistols() = default;
	void input() override;
	void showSkin() override;
	void buySkin() override;
	void setPaintSkin(const string& type) override;
	void setModel(const string& model);
	void setPaint(const string& paint);
	void setMaxBullets(const size_t& max);
	void setRareSkin(const string& rare) override;
	void setFValue(const float& f) override;
	void setSeler(const bool& s);
	void setPriceSkin(const size_t& price) override;
	string getName() const;
	void sortByName();
	void print() const override;
private:
	PData p;
};