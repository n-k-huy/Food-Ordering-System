#ifndef _CUSTOMER_
#define _CUSTOMER_

#include "Order.h"
#include "Restaurant.h"
#include "User.h"

// Lay ma mon an tu nguoi dung
vector <int> getDishCode(const int& codeDish, const Menu* menu);

// Tim mon an trong menu co san
DiscountedDish* findDishInMenu(const vector <int>& dishCode, const Menu& menu);

// Nguoi dung chon mon trong 1 hoac nhieu Menu
// Man hinh bat buoc la ban phim so
vector <pair<int, int>> chooseDish(const Menu& menu);

// Cai dat order cua nguoi mua
Order* settingOrders(vector <pair<int, int>>& listCodeDish, Order*& order,const Menu* menu);

// Lua chon menu
Order* chooseMenu(const vector<Menu*>& menu, Order*& order);

class Customer : public User
{
private:
	string name;
	vector <int> ID;
	vector <Order*> listOrder;
public:
	Customer();
	Customer(string n, vector <int> id, vector <Order*> orders);
	Customer(const Customer& customer);

	void setName(const string& n);
	void setID(const vector <int>& id);
	void setOrder(const vector <Order*>& orders);

	string getName() const;
	vector <int> getID() const;
	vector <Order*> getListOrder() const;

	void placeOrder(const vector <Menu*>& menu);
	void informationOrders(vector <Order*> orders) override;

	~Customer();
};

#endif
