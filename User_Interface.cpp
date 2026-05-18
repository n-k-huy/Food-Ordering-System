#include "User_Interface.h"

void userInterface()
{
	cout << "--------------------------------------" << endl;
	cout << " 1) FOR STAFF" << endl;
	cout << " 2) FOR CUSTOMER" << endl;
	cout << " 3) EXITS" << endl;
	cout << "--------------------------------------" << endl;
}

void userInterfaceForStaff()
{
	cout << "--------------------------------------" << endl;
	cout << " 1) UPDATE STATE ORDER" << endl;
	cout << " 2) ADD MENU" << endl;
	cout << " 3) REMOVE MENU" << endl;
	cout << " 4) VIEW INFORMATION ORDERS" << endl;
	cout << " 5) EXITS" << endl;
	cout << "--------------------------------------" << endl;
}

void chooseModeForStaff(Restaurant*& restaurant, vector <Customer*>& listCustomer)
{
	Staff* staff = restaurant->getListStaff()[0];	// Gia su co 1 nhan vien quan ly

	system("cls");
	char usingMore = 'y';
	while (usingMore == 'y' || usingMore == 'Y')
	{
		userInterfaceForStaff();
		cout << "Input your choice: ";
		int mode;
		cin >> mode;
		switch (mode)
		{
			case 1:
			{
				for (Customer*& customer : listCustomer)
				{
					vector <Order*> listOrder = customer->getListOrder();
					for (Order*& order : listOrder)
					{
						// Hoi nhan vien co muon update don hang nay khong
						cout << "Do you want to update order #";
						for (const int& val : order->getID())
							cout << val;
						cout << " ? (Y/N): ";
						
						char wantToUpdate;
						cin >> wantToUpdate;

						if (wantToUpdate == 'y' || wantToUpdate == 'Y')
						{
							// Update don hang
							cout << "Order #";
							for (const int& val : order->getID())
								cout << val;
							cout << " is updating." << endl;

							bool update = staff->updateStateOrder(order);
							if (update == true)
								cout << "Update successfully" << endl;
							else cout << "Fail to update" << endl << endl;
						}
						else continue;
					}

					customer->setOrder(listOrder);
				}
				system("pause");
				break;
			}
			case 2:
			{
				cin.ignore(1);	// Bo ki tu enter
				vector <Menu*> listMenu = restaurant->getListMenu();
				
				// Tao menu moi
				Menu* newMenu = settingMenu();
				staff->addMenuItem(listMenu, newMenu);

				// Set lai listMenu cho Restaurant
				restaurant->setListMenu(listMenu);

				break;
			}
			case 3:
			{
				cin.ignore(1);	// Bo ki tu enter

				// Hien cac menu cho nhan vien
				vector <Menu*> listMenu = restaurant->getListMenu();
				controlPanel(listMenu);

				cout << "Which menu do you want to remove?: ";
				int orderedMenu;
				cin >> orderedMenu;

				if (orderedMenu <= listMenu.size())
				{
					// Xoa menu
					staff->removeMenuItem(listMenu, listMenu[orderedMenu - 1]);
					restaurant->setListMenu(listMenu);
				}

				break;
			}
			case 4:
			{
				for (Customer*& customer : listCustomer)
				{
					vector <Order*> listOrder = customer->getListOrder();
					staff->informationOrders(listOrder);
				}
				system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				return;
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
		
		system("cls");
		if (mode < 5)
		{
			cout << "Do you want to continue choosing another mode? (Y/N): ";
			cin >> usingMore;
			system("cls");
			cin.ignore(1);
		}
	}
}

void userInterfaceForCustomer()
{
	cout << "--------------------------------------" << endl;
	cout << " 1) PLACE ORDER" << endl;
	cout << " 2) VIEW INFORMATION ORDERS" << endl;
	cout << " 3) EXITS" << endl;
	cout << "--------------------------------------" << endl;
}

void chooseModeForCustomer(Customer*& customer, const vector <Menu*>& listMenu)
{
	system("cls");
	// Cai dat ten nguoi dung
	cout << "Input your name: ";
	string name;
	getline(cin, name);
	customer->setName(name);

	system("cls");
	char usingMore = 'y';
	while (usingMore == 'y' || usingMore == 'Y')
	{
		userInterfaceForCustomer();
		cout << "Input your choice: ";
		int mode;
		cin >> mode;
		switch (mode)
		{
			case 1:
			{
				customer->placeOrder(listMenu);
				break;
			}
			case 2:
			{
				vector <Order*> listOrder = customer->getListOrder();
				customer->informationOrders(listOrder);
				system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				return;
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

		system("cls");
		if (mode < 3)
		{
			cout << "Do you want to continue choosing another mode? (Y/N): ";
			cin >> usingMore;
			system("cls");
			cin.ignore(1);
		}
	}
}
