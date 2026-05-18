#ifndef _STAFF_
#define _STAFF_

#include "User.h"
#include "Menu.h"

class Staff : public User
{
public:
	bool updateStateOrder(Order* order);
	bool addMenuItem(vector <Menu*>& listMenu, Menu*& newMenu);
	bool removeMenuItem(vector <Menu*>& listMenu, Menu*& deletedMenu);
	void informationOrders(vector <Order*> orders) override;
};

#endif