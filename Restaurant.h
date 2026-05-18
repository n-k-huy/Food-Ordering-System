#ifndef _RESTAURANT_
#define _RESTAURANT_

#include "Common.h"
#include "Menu.h"
#include "Staff.h"

// Bang dieu khien chon Menu
void controlPanel(const vector <Menu*>& menu);

class Restaurant
{
private:
	vector <Menu*> listMenu;
	vector <Staff*> listStaff;
public:
	Restaurant();
	Restaurant(const vector <Menu*>& menus, const vector <Staff*>& staffs);
	Restaurant(const Restaurant& restaurant);

	void setListMenu(const vector <Menu*>& menus);
	void setListStaff(const vector <Staff*>& staffs);

	vector <Menu*> getListMenu() const;
	vector <Staff*> getListStaff() const;

	~Restaurant();
};

#endif

