#ifndef _MENU_
#define _MENU_

#include "DiscountedDish.h"

class Menu
{
private:
	string name;
	unordered_map <CategoryDish, vector <DiscountedDish*>>* listDish;
public:
	Menu();
	Menu(string n, unordered_map <CategoryDish, vector <DiscountedDish*>>* list);
	Menu(const Menu& menu);

	void setName(const string& n);
	void setListDish(unordered_map <CategoryDish, vector <DiscountedDish*>>* list);

	string getName() const;
	unordered_map <CategoryDish, vector <DiscountedDish*>>* getListDish() const;

	fstream saveToFile(const Menu& menu);
	int readFromFile(int position, Menu*& menu);

	friend ostream& operator << (ostream& output, const Menu& menu);

	friend bool operator == (const Menu& menu1, const Menu& menu2);

	~Menu();
};

#endif
