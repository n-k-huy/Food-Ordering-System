#ifndef _DISH_
#define _DISH_

#include "Common.h"

class Dish
{
private:
	vector <int> ID;
	string name;
	float price;
	int categoryNumber;
public:
	Dish();
	Dish(vector <int> id, string n, float cost, int number);
	Dish(const Dish& dish);
	
	void setID(const vector <int>& id);
	void setName(const string& nameDish);
	void setPrice(const float& priceDish);
	void setCategoryNumber(const int& number);

	vector <int> getID() const;
	string getName() const;
	float getPrice() const;
	int getCategoryNumber() const;

	virtual ~Dish();
};

#endif

