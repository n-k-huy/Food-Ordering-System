#ifndef _USER_
#define _USER_

#include "Order.h"

class User
{
public:
	virtual void informationOrders(vector <Order*> orders) = 0;
};

#endif
