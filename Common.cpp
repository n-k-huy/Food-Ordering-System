#include "Common.h"

string printKindOfDish(CategoryDish dish)
{
	switch (dish)
	{
	case CategoryDish::APPETIZER:
		return "APPETIZER";
	case CategoryDish::MAIN_COURSE:
		return "MAIN COURSE";
	case CategoryDish::DESSERT:
		return "DESSERT";
	case CategoryDish::DRINK:
		return "DRINK";
	default:
		return "UPDATING...";
	}
}

CategoryDish transformIntToCategory(int number)
{
	switch (number)
	{
	case 1:
		return CategoryDish::APPETIZER;
	case 2:
		return CategoryDish::MAIN_COURSE;
	case 3:
		return CategoryDish::DESSERT;
	case 4:
		return CategoryDish::DRINK;
	default:
		cout << "Wrong choice. Please input again." << endl;
		break;
	}
}

string printStatusOfOrder(Status status)
{
	switch (status)
	{
	case Status::PENDING:
		return "PENDING";
	case Status::PREPARING:
		return "PREPARING";
	case Status::COMPLETED:
		return "COMPLETED";
	default:
		return "UPDATING...";
	}
}