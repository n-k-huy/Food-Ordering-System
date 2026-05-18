#ifndef _COMMON_
#define _COMMON_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>

#define BUFFER_SIZE 26
#define RESTAURANT_COMISSION 2
#define ATTRIBUTES_OF_EACH_DISH 6

using namespace std;

enum class CategoryDish
{
	APPETIZER = 1,
	MAIN_COURSE,
	DESSERT,
	DRINK
};

string printKindOfDish(CategoryDish dish);

CategoryDish transformIntToCategory(int number);

enum class Status
{
	PENDING = 1,
	PREPARING,
	COMPLETED
};

string printStatusOfOrder(Status status);

#endif

