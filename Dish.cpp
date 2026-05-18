#include "Dish.h"

Dish::Dish()
{
    categoryNumber = 1;

    ID = vector <int>(3, 0);
    srand(time(NULL));
    for (int index = 0; index < ID.size() - 1; index++)
    {
        ID[index] = rand() % 10;
    }

    name = "";
    price = 0.00;
}

Dish::Dish(vector<int> id, string n, float cost, int number)
{
    setID(id);
    setName(n);
    setPrice(cost);
    setCategoryNumber(number);
}

Dish::Dish(const Dish& dish)
{
    setID(dish.ID);
    setName(dish.name);
    setPrice(dish.price);
    setCategoryNumber(dish.categoryNumber);
}

void Dish::setID(const vector <int>& id)
{
    ID = id;
}

void Dish::setName(const string& nameDish)
{
    name = nameDish;
}

void Dish::setPrice(const float& priceDish)
{
    price = priceDish;
}

void Dish::setCategoryNumber(const int& number)
{
    categoryNumber = number;
}

vector<int> Dish::getID() const
{
    return ID;
}

string Dish::getName() const
{
    return name;
}

float Dish::getPrice() const
{
    return price;
}

int Dish::getCategoryNumber() const
{
    return categoryNumber;
}

Dish::~Dish()
{
}
