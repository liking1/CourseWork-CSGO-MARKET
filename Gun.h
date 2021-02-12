#pragma once
#include "Shop.h"
#include <Windows.h>

struct Data
{
	string model_, type_, paint_, rare_;
	size_t MAX_BULLETS, price_;
	float f_value;
};

class Gun : public Skin
{
public:
	Gun() = default;
	Gun(const string& model, const string& type, const string& paint, const size_t& MAX_BULLETS)
	{
		setModel(model);
		setPaintSkin(type);
		setPaint(paint);
		setMaxBullets(MAX_BULLETS);
	}
	string getName() const { return d.model_; };

	void input() override;
	void showSkin() override;
	void buySkin() override;
	void setPaintSkin(const string& type) override;
	void setModel(const string& model);
	void setPaint(const string& paint);
	void setMaxBullets(const size_t& max);
	void setRareSkin(const string& rare) override;
	void setFValue(const float& f) override;
	void setPriceSkin(const size_t& price) override;
	void sortByName();
	void print() const override;

private:
	Data d;
};