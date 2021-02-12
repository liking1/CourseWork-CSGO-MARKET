#pragma once
#include <iostream>
#include <string>
#include "Shop.h"
#include "Knife.h"
#include "Gun.h"
#include "Pistols.h"
#include "windows.h"

#define CLEAN system("cls");
#define QUIT system("cls"); system("pause");

using namespace std;

void showMenu();

void quest();

void User()
{
	CLEAN;
	int action;

	do
	{
		system("mode con cols=50 lines=40");
		system("Color 3");
		cout << "________USER MENU_______" << endl;
		cout << "| 1.  Show all skin   |" << endl;
		cout << "-----------------------" << endl;
		cout << "| 2.   Buy a skin     |" << endl;
		cout << "-----------------------" << endl;
		cout << "| 3.  Back to Menu    |" << endl;
		cout << "-----------------------" << endl;
		cout << "| 0.      Exit        |" << endl;
		cout << "-----------------------" << endl;
		cout << endl;
		cout << "Enter action : "; cin >> action;
		switch (action)
		{
		case 1:
		{
			string type;
			cout << "Enter type skin : "; cin >> type;
			if (type == "Knife" || type == "knife")
			{
				Knife k;
				k.showSkin();
			}
			else if (type == "Gun" || type == "gun")
			{
				Gun g;
				g.showSkin();
			}
			else if (type == "Pistol" || type == "Pistols" || type == "pistol" || type == "pistols")
			{
				Pistols p;
				p.showSkin();
			}
		}break;
		case 2:
		{
			string type;
			cout << "Enter type skin : "; cin >> type;
			if (type == "Knife" || type == "knife")
			{
				Knife k;
				k.buySkin();
			}
			else if (type == "Gun" || type == "gun")
			{
				Gun g;
				g.buySkin();
			}
			else if (type == "Pistol" || type == "Pistols" || type == "pistol" || type == "pistols")
			{
				Pistols p;
				p.buySkin();
			}
		}break;
		case 3:
		{
			if (action == 3)
			{
				quest();
			}
			else if (action != 3)
			{
				User();
			}
		}break;
		case 0:
		{
			exit(0);
		}break;
		}
		CLEAN;
	} while (action != 3);

}
void quest();
void Admin()
{
	system("cls");
	string action;
	do
	{
		system("mode con cols=50 lines=40");
		system("Color 2");
		cout << " ------------------------ " << endl;
		cout << "| 1.   Add skin in db    |" << endl;
		cout << " ------------------------" << endl;
		cout << "| 2.   Delete product    |" << endl;
		cout << " ------------------------" << endl;
		cout << "| 3.  Show all product   |" << endl;
		cout << " ------------------------" << endl;
		cout << "| 4.    Back to menu	  |" << endl;
		cout << " ------------------------" << endl;
		cout << "| 5.    Sort By Name	  |" << endl;
		cout << " ------------------------" << endl;
		cout << "| 0.       Exit		  |" << endl;
		cout << " ------------------------" << endl;
		cout << "Enter action : ";
		cin >> action;
		if (action == "1")
		{
			string type;
			cout << "Enter type skin : "; cin >> type;
			if (type == "Knife" || type == "knife")
			{
				Knife k;
				k.input();
			}
			else if (type == "Gun" || type == "gun")
			{
				Gun g;
				g.input();
			}
			else if (type == "Pistol" || type == "Pistols" || type == "pistol" || type == "pistols")
			{
				Pistols p;
				p.input();
			}
			CLEAN;
		}
		else if (action == "2")
		{
			string type;
			cout << "Enter type skin : "; cin >> type;
			if (type == "Knife" || type == "knife")
			{
				Knife k;
				k.buySkin();
			}
			else if (type == "Gun" || type == "gun")
			{
				Gun g;
				g.buySkin();
			}
			else if (type == "Pistol" || type == "Pistols" || type == "pistol" || type == "pistols")
			{
				Pistols p;
				p.buySkin();
			}


		}
		else if (action == "3")
		{
			string type;
			cout << "Enter type skin : "; cin >> type;
			if (type == "Knife" || type == "knife")
			{
				Knife k;
				k.showSkin();
			}
			else if (type == "Gun" || type == "gun")
			{
				Gun g;
				g.showSkin();
			}
			else if (type == "Pistol" || type == "Pistols" || type == "pistol" || type == "pistols")
			{
				Pistols p;
				p.showSkin();
			}
			CLEAN;
		}
		else if (action == "4")
		{
			quest();
		}
		else if (action == "5")
		{
			string sort;
			cout << "Enter gun sort: ";
			cin >> sort;
			if (sort == "Knife" || sort == "knife")
			{
				Knife s122;
				s122.sortByName();
			}
		}
		else if (action == "0")
		{
			exit(0);
		}
		else if (action != "0")
		{
			Admin();
		}
	} while (true);
}

void quest()
{
	int action;
	do
	{
		system("mode con cols=25 lines=15");
		system("Color 6");
		CLEAN;
		cout << "| 1. Admin panel  |" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "| 2. User panel   |" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "| 3.	Exit	   |" << endl;
		cout << "\n\n\n\n\n\n" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
		{
			Admin();
		}break;
		case 2:
		{
			User();
		}
		case 3:
		{
			system("Color 4");
			cout << "Market is closet";
			exit(0);
		}
		}
	} while (action != 3);
	CLEAN;
}

void showMenu()
{
	CLEAN;
	quest();
}