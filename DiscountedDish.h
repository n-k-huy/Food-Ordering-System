#ifndef _DISCOUNTED_DISH_
#define _DISCOUNTED_DISH_

#include "Dish.h"

class DiscountedDish : public Dish
{
private:
	float discount;
	int limitedDish;
public:
	DiscountedDish();
	DiscountedDish(vector <int> id, string n, float cost, int number, float rate, int limited);
	DiscountedDish(const DiscountedDish& discountedDish);

	void setDiscount(const float& rate);
	void setLimitedDish(const int& limited);

	float getDiscount() const;
	int getLimitedDish() const;

	bool isDiscountedDish();
	bool isOvercomeLimitedDiscountDish(int numberOfDiscountedDish);

	~DiscountedDish();
};

#endif
