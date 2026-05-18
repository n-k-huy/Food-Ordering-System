#ifndef _ORDER_
#define _ORDER_

#include "DiscountedDish.h"

class Order
{
private:
	vector <int> ID;
	vector <pair <int, DiscountedDish*>> dishes;
	Status status;
public:
	Order();
	Order(vector <int> id, vector <pair <int, DiscountedDish*>> dish, Status state);
	Order(const Order& order);

	void setID(const vector <int>& id);
	void setDishes(const vector <pair <int, DiscountedDish*>>& dish);
	void setStatus(const Status& state);

	vector <int> getID() const;
	vector <pair <int, DiscountedDish*>> getDishes() const;
	Status getStatus() const;

	float totalPrice();
	char* timeStamp();

	~Order();
};

#endif

