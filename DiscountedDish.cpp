#include "DiscountedDish.h"

DiscountedDish::DiscountedDish() : Dish()
{
    discount = 0.00;
    limitedDish = 0;
}

DiscountedDish::DiscountedDish(vector<int> id, string n, float cost, int number, float rate, int limited) : Dish(id, n, cost, number)
{
    setDiscount(rate);
    setLimitedDish(limited);
}

DiscountedDish::DiscountedDish(const DiscountedDish& discountedDish) : Dish(discountedDish)
{
    setDiscount(discountedDish.discount);
    setLimitedDish(discountedDish.limitedDish);
}

void DiscountedDish::setDiscount(const float& rate)
{
    discount = rate;
}

void DiscountedDish::setLimitedDish(const int& limited)
{
    limitedDish = limited;
}

float DiscountedDish::getDiscount() const
{
    return discount;
}

int DiscountedDish::getLimitedDish() const
{
    return limitedDish;
}

bool DiscountedDish::isDiscountedDish()
{
    return (discount != 0);
}

bool DiscountedDish::isOvercomeLimitedDiscountDish(int numberOfDiscountedDish)
{
    return (numberOfDiscountedDish <= limitedDish);
}

DiscountedDish::~DiscountedDish()
{
}
