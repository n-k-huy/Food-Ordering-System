#include "Order.h"

Order::Order()
{
    ID = vector <int>(3, 0);
    srand(time(NULL));
    for (int& val : ID)
        val = rand() % 10;

    dishes = vector <pair <int, DiscountedDish*>>{};
    status = Status::PENDING;
}

Order::Order(vector<int> id, vector<pair<int, DiscountedDish*>> dish, Status state)
{
    setID(id);
    setDishes(dish);
    setStatus(state);
}

Order::Order(const Order& order)
{
    setID(order.ID);
    setDishes(order.dishes);
    setStatus(order.status);
}

void Order::setID(const vector<int>& id)
{
    ID = id;
}

void Order::setDishes(const vector<pair<int, DiscountedDish*>>& dish)
{
    dishes.clear();
    for (const pair <int, DiscountedDish*>& food : dish)
    {
        DiscountedDish* newFood = new DiscountedDish(*food.second);
        dishes.push_back({ food.first, newFood });
    }
}

void Order::setStatus(const Status& state)
{
    status = state;
}

vector<int> Order::getID() const
{
    return ID;
}

vector<pair<int, DiscountedDish*>> Order::getDishes() const
{
    return dishes;
}

Status Order::getStatus() const
{
    return status;
}

float Order::totalPrice()
{
    float totalMoney = 0;
    vector <pair <int, DiscountedDish*>> dish = dishes;
    for (const auto& ele : dish)
    {
        float comission = ele.second->getPrice() * RESTAURANT_COMISSION / 100.00;
        if (ele.second->isDiscountedDish() == true)
        {
            float price = ele.second->getPrice();
            float discount = ele.second->getDiscount();
            totalMoney += (ele.first * (price - (discount * price / 100.00) + comission));
        }
        else totalMoney += (ele.first * (ele.second->getPrice() + comission));
    }
    return totalMoney;
}

char* Order::timeStamp()
{
    time_t mileStone = time(NULL);
    char* realTime = new char[BUFFER_SIZE] {0};
    ctime_s(realTime, BUFFER_SIZE, &mileStone);
    return realTime;
}

Order::~Order()
{
    for (pair <int, DiscountedDish*>& food : dishes)
    {
        delete food.second;
        food.second = NULL;
    }
}
