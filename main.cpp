#include "Setting.h"
#include "User_Interface.h"

int main()
{
	Restaurant* restaurant = new Restaurant;

	// Mo Menu.txt
	fstream menuFile("Menu.txt");
	if (menuFile.is_open() == false)
	{
		cout << "System error!" << endl;
		return -1;
	}

	// Kiem tra Menu file co du lieu hay khong
	int currPos = menuFile.tellg();
	menuFile.seekg(0, ios::end);
	int lastPos = menuFile.tellg();

	if (currPos == lastPos)
		settingRestaurant(restaurant);
	else
	{
		menuFile.seekg(0, ios::beg);		// Dua con tro ve dau
		
		// Cai dat nhan vien
		vector <Staff*> listStaff = makeListStaff();
		restaurant->setListStaff(listStaff);

		// Cai dat menu
		vector <Menu*> listMenu;
		int currPosText = 0;
		while (currPosText != EOF)
		{
			Menu* menu = new Menu;
			int newPos = menu->readFromFile(currPosText, menu);
			currPosText = newPos;

			// Dua menu vao listMenu
			listMenu.push_back(menu);
		}
		restaurant->setListMenu(listMenu);
	}

	// Tuong tac nguoi dung va nha hang
	vector <Customer*> listCustomer;

	char usingMore = 'y';
	while (usingMore == 'y' || usingMore == 'Y')
	{
		userInterface();
		cout << "Please choose your chosen: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
			{
				chooseModeForStaff(restaurant, listCustomer);
				break;
			}
			case 2:
			{
				cin.ignore(1);	// Bo ki tu enter de nhap ten nguoi dung
				Customer* customer = new Customer;
				vector <Menu*> listMenu = restaurant->getListMenu();
				chooseModeForCustomer(customer, listMenu);

				// Luu nguoi dung lai de quan li
				listCustomer.push_back(customer);
				break;
			}
			case 3:
			{
				system("cls");
				cout << "THANK FOR USING." << endl;
				system("pause");
				cin.ignore(1);
				return 1;
			}
			default:
			{
				cout << "Wrong choice. Please input again" << endl;
				system("pause");
				system("cls");
				cin.ignore(1);
				break;
			}
		}

		// Hoi nguoi su dung co muon tiep tuc su dung ung dung
		if (choice < 3)
		{
			cout << "Do you want to continue using app? (Y/N): ";
			cin >> usingMore;
			if (usingMore != 'y' && usingMore != 'Y')
				cout << "THANK FOR USING." << endl;
			system("pause");
			system("cls");
			cin.ignore(1);
		}
	}

	delete restaurant;
	//Customer* customer = new Customer;

	//settingRestaurant(restaurant);

	//customer->placeOrder(restaurant->getListMenu());
	//customer->informationOrders(customer->getListOrder());

	//// Cap nhat trang thai don hang nguoi dung
	//restaurant->getListStaff()[0]->informationOrders(customer->getListOrder());
	//restaurant->getListStaff()[0]->updateStateOrder(customer->getListOrder()[0]);
	//restaurant->getListStaff()[0]->informationOrders(customer->getListOrder());

	//Menu* menu = new Menu;
	//vector <Menu*> listMenu = restaurant->getListMenu();
	//restaurant->getListStaff()[0]->addMenuItem(listMenu, menu);
	//restaurant->setListMenu(listMenu);
	//restaurant->getListStaff()[0]->removeMenuItem(listMenu, menu);
	//restaurant->setListMenu(listMenu);

	//delete restaurant;
	//delete customer;
	
	return 1;
}