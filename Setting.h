#ifndef _SETTING_
#define _SETTING_

#include "Customer.h"
#include "Order.h"
#include "Menu.h"

Menu* settingMenu();

vector <Menu*> makeListMenu();

vector <Staff*> makeListStaff();

void settingRestaurant(Restaurant*& res);

#endif
