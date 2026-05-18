#ifndef _USER_INTERFACE_
#define _USER_INTERFACE_

#include "Common.h"
#include "Setting.h"

void userInterface();

void userInterfaceForStaff();

void chooseModeForStaff(Restaurant*& restaurant, vector <Customer*>& listCustomer);

void userInterfaceForCustomer();

void chooseModeForCustomer(Customer*& customer, const vector <Menu*>& listMenu);

#endif