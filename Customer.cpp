#include "Customer.h"

// Lay ma mon an tu nguoi nhap
vector <int> getDishCode(const int& codeDish, const Menu* menu)
{
	// Lay ma mon an
	vector <int> code(3, 0);
	int temp = codeDish;
	for (int index = code.size() - 1; index >= 0; index--)
	{
		code[index] = temp % 10;
		temp /= 10;
	}

	return code;
}

// Tim mon trong menu co san
DiscountedDish* findDishInMenu(const vector <int>& dishCode, const Menu& menu)
{
	// Lay danh muc thuc an
	int categoryDish = dishCode[dishCode.size() - 1];
	CategoryDish kindOfDish = static_cast <CategoryDish> (categoryDish);

	// Truy xuat key -> val
	unordered_map <CategoryDish, vector <DiscountedDish*>>* listDish = menu.getListDish();
	vector <DiscountedDish*> dishes = listDish->at(kindOfDish);


	// Tim mon an vao danh sach mon an theo don hang cua nguoi dung
	for (DiscountedDish* dish : dishes)
	{
		if (dishCode == dish->getID())
			return dish;
	}
	return NULL;
}

// Nguoi dung chon mon trong 1 hoac nhieu Menu
vector <pair<int, int>> chooseDish(const Menu& menu)
{
	vector <pair <int, int>> listCodeDish;
	int code;
	int numberOfDish;

	char addMore = 'y';
	// Tien hanh nhap
	do
	{
		cout << menu << endl;
		// Nhap ma mon
		cout << "Please input dish code (Code of each dish must include 3 number): ";
		cin >> code;

		// Nhap so luong mon
		cout << "Input the number of dish: ";
		cin >> numberOfDish;

		// Kiem tra ma co phai la mon giam gia
		vector <int> dishCode = getDishCode(code, &menu);	// Ma mon an
		DiscountedDish* dish = findDishInMenu(dishCode, menu);	// Lay mon an tu menu

		// Kiem tra lay co thanh cong
		if (dish != NULL)
		{
			if (dish->isDiscountedDish() == true)
			{
				while (dish->isOvercomeLimitedDiscountDish(numberOfDish) == false)
				{
					cout << "The dish " << dish->getName() << " has only " << dish->getLimitedDish() << " dishes. Please input the number of your dish again." << endl;
					system("pause");
					system("cls");
					cin.ignore(1);

					cout << menu << endl;
					cout << "Input the number of " << dish->getName() << " dish: ";
					cin >> numberOfDish;
				}
			}
		}

		// Luu vao danh sach listCodeDish
		listCodeDish.push_back({ code, numberOfDish });

		cout << "Do you want to add more dish in this menu? (Y/N): ";
		cin >> addMore;
		system("cls");
	} while (addMore == 'y' || addMore == 'Y');

	return listCodeDish;
}

// Cai dat order cua nguoi mua
Order* settingOrders(vector <pair<int, int>>& listCodeDish, Order*& order,const Menu* menu)
{
	vector <pair <int, DiscountedDish*>> totalDishes = order->getDishes();

	// Truy xuat mon theo ma dua vao order->dishes
	for (const pair <int, int>& codeDish : listCodeDish)
	{
		vector <int> code = getDishCode(codeDish.first, menu);

		// Check xem trong danh sach mon cua nguoi dung co mon nay khong
		DiscountedDish* dish = findDishInMenu(code, *menu);
		if (dish != NULL)
		{
			bool alreadyHad = false;
			// Tim mon an co trong danh sach mon cua nguoi dung chua
			for (pair <int, DiscountedDish*>& customerDish : totalDishes)
			{
				if (code == customerDish.second->getID())	// Mon an da co trong danh sach
				{
					alreadyHad = true;
					customerDish.first += codeDish.second;	// Cap nhat so luong
					if (customerDish.second->isDiscountedDish() == true)
					{
						if (customerDish.second->isOvercomeLimitedDiscountDish(customerDish.first) == false)	// Kiem tra mon an do co phai la mon giam gia
							customerDish.first = customerDish.second->getLimitedDish();
					}
					break;
				}
			}
			if (alreadyHad == false)
				totalDishes.push_back({ codeDish.second, dish });	// Mon an chua co trong danh sach cua khach hang
		}
	}

	// Luu lai cho order->dishes
	order->setDishes(totalDishes);

	return order;
}

// Lua chon menu
Order* chooseMenu(const vector<Menu*>& menu, Order*& order)
{
	char addMore = 'y';
	while (addMore == 'y' || addMore == 'Y')
	{
		system("cls");
		controlPanel(menu);
		cout << "Please choose your menu: ";
		int choice;
		cin >> choice;
		system("cls");
		if (choice > 0 && choice <= menu.size())
		{
			vector <pair <int, int>> codeDish = chooseDish(*menu[choice - 1]);
			settingOrders(codeDish, order, menu[choice - 1]);
		}
		else if (choice == menu.size() + 1)
			break;
		else
		{
			cout << "UPDATING....." << endl;
			system("pause");
			system("cls");
		}

		cin.ignore(1);
		controlPanel(menu);
		cout << "Want to choose another menu? (Y/N): ";
		cin >> addMore;
		system("cls");
	}
	return order;
}

Customer::Customer()
{
    name = "";
    ID = vector <int>(12, 0);
    for (int& val : ID)
        val = rand() % 9;
	listOrder = vector <Order*>{};
}

Customer::Customer(string n, vector<int> id, vector<Order*> orders)
{
    setName(n);
    setID(id);
    setOrder(orders);
}

Customer::Customer(const Customer& customer)
{
    setID(customer.ID);
    setName(customer.name);
    setOrder(customer.listOrder);
}

void Customer::setName(const string& n)
{
    name = n;
}

void Customer::setID(const vector<int>& id)
{
    ID = id;
}

void Customer::setOrder(const vector<Order*>& orders)
{
	listOrder.clear();
    for (const Order* order : orders)
        listOrder.push_back(new Order(*order));
}

string Customer::getName() const
{
    return name;
}

vector<int> Customer::getID() const
{
    return ID;
}

vector<Order*> Customer::getListOrder() const
{
    return listOrder;
}

void Customer::placeOrder(const vector<Menu*>& menu)
{
	char wantToPlace = 'y';
	while (wantToPlace == 'y' || wantToPlace == 'Y')
	{
		Order* order = new Order;
		// Menu cho khach hang lua chon
		order = chooseMenu(menu, order);
		listOrder.push_back(order);

		cout << "Do you want to place more orders? (Y/N): ";
		cin >> wantToPlace;
		system("cls");
	}
}

void Customer::informationOrders(vector <Order*> orders)
{
    cout << "-----------------------------------------" << endl;
    cout << "Customer: " << name << endl;
    cout << "ID: ";
    for (int val : ID)
        cout << val;
    cout << endl;
    for (Order*& order : orders)
    {
        cout << "---------------" << endl;
        cout << "Order: #";
        for (int val : order->getID())
            cout << val;
        cout << "\t\t Status: " << printStatusOfOrder(order->getStatus()) << endl;
        cout << "Time ordered: " << order->timeStamp();
        cout << "Total money needs to pay: " << order->totalPrice() << " VND" << endl;
    }
}

Customer::~Customer()
{
    for (Order* order : listOrder)
    {
        delete order;
        order = NULL;
    }
}
