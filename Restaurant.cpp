#include "Restaurant.h"

void controlPanel(const vector <Menu*>& menu)
{
    cout << "-------------------------------" << endl;
    cout << "\tMENU ITEMS" << endl;
    cout << "-------------------------------" << endl;
    for (int index = 0; index < menu.size(); index++)
        cout << "\t" << index + 1 << ") " << menu[index]->getName() << endl;
    cout << "\t" << menu.size() + 1 << ") EXITS" << endl;
    cout << "-------------------------------" << endl;
}

Restaurant::Restaurant()
{
    listMenu = vector <Menu*>{};
    listStaff = vector <Staff*>{};
}

Restaurant::Restaurant(const vector<Menu*>& menus, const vector<Staff*>& staffs)
{
    setListMenu(menus);
    setListStaff(staffs);
}

Restaurant::Restaurant(const Restaurant& restaurant)
{
    setListMenu(restaurant.listMenu);
    setListStaff(restaurant.listStaff);
}

void Restaurant::setListMenu(const vector<Menu*>& menus)
{
    listMenu.clear();
    for (const Menu* menu : menus)
    {
        Menu* m = new Menu(*menu);
        listMenu.push_back(m);
    }
}

void Restaurant::setListStaff(const vector<Staff*>& staffs)
{
    listStaff.clear();
    for (const Staff* staff : staffs)
    {
        Staff* st = new Staff(*staff);
        listStaff.push_back(st);
    }
}

vector<Menu*> Restaurant::getListMenu() const
{
    return listMenu;
}

vector<Staff*> Restaurant::getListStaff() const
{
    return listStaff;
}

Restaurant::~Restaurant()
{
    for (const Menu* menu : listMenu)
    {
        delete menu;
        menu = NULL;
    }
    for (const Staff* staff : listStaff)
    {
        delete staff;
        staff = NULL;
    }
}
