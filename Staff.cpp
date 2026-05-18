#include "Staff.h"

bool Staff::updateStateOrder(Order* order)
{
    order->setStatus(Status::PREPARING);
    if (order->getStatus() == Status::PENDING)
    {
        return false;
    }
    return true;
}

bool Staff::addMenuItem(vector <Menu*>& listMenu, Menu*& newMenu)
{
    for (const auto& menu : listMenu)
    {
        if (newMenu == menu)
        {
            cout << "New menu has already in list" << endl;
            return false;
        }
    }
    listMenu.push_back(newMenu);
    cout << "Add successfully" << endl;
    return true;
}

bool Staff::removeMenuItem(vector <Menu*>& listMenu, Menu*& deletedMenu)
{
    vector <Menu*>::iterator found = find(listMenu.begin(), listMenu.end(), deletedMenu);
    if (found != listMenu.end())
    {
        listMenu.erase(found);
        cout << "Remove succesfully" << endl;
        return true;
    }
    cout << "Not found" << endl;
    return false;
}

void Staff::informationOrders(vector<Order*> orders)
{
    for (Order*& order : orders)
    {
        cout << "---------------------------" << endl;

        // ID
        cout << "Order: #";
        for (const int& val : order->getID())
            cout << val;

        // Trang thai
        cout << "\t\t" << printStatusOfOrder(order->getStatus()) << endl;

        // Thong tin cac mon an
        cout << setw(10) << left << "ID" << left << setw(35) << "Name" << left << setw(15) << "Numbers" << endl;
        for (const pair <int, Dish*>& dish : order->getDishes())
        {
            string numberCode = "";
            vector <int> id = dish.second->getID();
            for (const int& val : id)
                numberCode += to_string(val);
            cout << setw(10) << left << numberCode << left << setw(35) << dish.second->getName() << left << setw(15) << dish.first << endl;

        }
        cout << "---------------------------" << endl << endl;
    }
}
