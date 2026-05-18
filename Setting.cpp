#include "Setting.h"

Menu* settingMenu()
{
	// Tao menu
	Menu* menu = new Menu;
	unordered_map <CategoryDish, vector <DiscountedDish*>>* listDish = menu->getListDish();

	// Nhap danh sach mon an
	string name;
	float price;
	int categoryNumber;
	string menuName;

	cout << "Setting menu for restaurant." << endl;

	// Nhap ten menu
	cout << "Input name of the menu: ";
	getline(cin, menuName);
	menu->setName(menuName);		// Dua ten menu vao Menu
	system("cls");

	// Nhap mon cho menu
	char more = 'y';
	while (more == 'y' || more == 'Y')
	{
		cout << menu->getName() << endl;
		// Nhap du lieu cho mon an

		DiscountedDish* dish = new DiscountedDish;
		// Ten mon
		cout << "Input name dish: ";
		getline(cin, name);

		// Gia tien
		cout << "Input price: ";
		cin >> price;

		// Mon an co giam gia khong
		char isDiscount;
		cout << "Is " << name << " discount (Y/N)? ";
		cin >> isDiscount;
		if (isDiscount == 'Y' || isDiscount == 'y')
		{
			float discount;
			int numberOfLimitedDish;

			// Nhap phan tram giam gia
			cout << "Input discount: ";
			cin >> discount;

			// Nhap so luong gioi han
			cout << "Input limited dishes: ";
			cin >> numberOfLimitedDish;

			// Dua du lieu giam gia vao mon
			dish->setDiscount(discount);
			dish->setLimitedDish(numberOfLimitedDish);
		}

		// Loai mon an
		cout << " 1: APPETIZER" << endl;
		cout << " 2: MAIN_COURSE" << endl;
		cout << " 3: DESSERT" << endl;
		cout << " 4: DRINK" << endl;
		cout << "Input category number: ";
		cin >> categoryNumber;
		system("cls");

		// Dua du lieu vao Dish
		dish->setName(name);
		dish->setPrice(price);
		dish->setCategoryNumber(categoryNumber);

		// Chi so cuoi cua ma mon se theo danh muc
		vector <int> id = dish->getID();
		id[id.size() - 1] = categoryNumber;
		dish->setID(id);

		// Dua Dish vao menu
		CategoryDish category = transformIntToCategory(categoryNumber);
		(*listDish)[category].push_back(dish);

		cout << "Do you want to add another dish? (Y/N)" << endl;
		cin >> more;
		system("cls");
		cin.ignore(1);
	}

	// Dua du lieu vao Menu
	menu->setListDish(listDish);

	return menu;
}

vector<Menu*> makeListMenu()
{
	vector <Menu*> listMenu;

	char continueToMakeMenu = 'y';
	while (continueToMakeMenu == 'y' || continueToMakeMenu == 'Y')
	{
		Menu* newMenu = settingMenu();

		newMenu->saveToFile(*newMenu);	// Luu du lieu vao file

		listMenu.push_back(newMenu);

		cout << "Do you want to create another menu? (Y/N)" << endl;
		cin >> continueToMakeMenu;
		system("cls");
		cin.ignore(1);
	}

	return listMenu;
}

vector<Staff*> makeListStaff()
{
	vector <Staff*> listStaff;
	char continueToManageStaff = 'y';
	while (continueToManageStaff == 'y' || continueToManageStaff == 'Y')
	{
		Staff* staff = new Staff;
		listStaff.push_back(staff);

		cout << "Restaurant has " << listStaff.size() << " staff now. " << endl;
		cout << "Do you want to manage more staff? (Y/N)" << endl;
		cin >> continueToManageStaff;
		system("cls");
		cin.ignore(1);
	}
	return listStaff;
}

void settingRestaurant(Restaurant*& res)
{
	vector <Menu*> listMenu = makeListMenu();
	vector <Staff*> listStaff = makeListStaff();
	res->setListMenu(listMenu);
	res->setListStaff(listStaff);
}
