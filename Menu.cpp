#include "Menu.h"

Menu::Menu()
{
    name = "";
    listDish = new unordered_map<CategoryDish, vector<DiscountedDish*>>;
}

Menu::Menu(string n, unordered_map<CategoryDish, vector<DiscountedDish*>>* list)
{
    setName(n);
    setListDish(list);
}

Menu::Menu(const Menu& menu)
{
    setName(menu.name);
    setListDish(menu.listDish);
}

void Menu::setName(const string& n)
{
    name = n;
}

void Menu::setListDish(unordered_map <CategoryDish, vector <DiscountedDish*>>* list)
{
    listDish = new unordered_map<CategoryDish, vector<DiscountedDish*>>;
    for (const auto& dish : *list)
    {
        vector <DiscountedDish*> copiedDish;
        for (DiscountedDish* d : dish.second)
            copiedDish.push_back(new DiscountedDish(*d));

        (*listDish)[dish.first] = copiedDish;
    }
}

string Menu::getName() const
{
    return name;
}

unordered_map<CategoryDish, vector<DiscountedDish*>>* Menu::getListDish() const
{
    return listDish;
}

fstream Menu::saveToFile(const Menu& menu)
{
    fstream menuFile;

    menuFile.open("Menu.txt", ios::app | ios::out);
    if (menuFile.is_open() == true)
    {
        menuFile << menu.getName() << endl;     // Luu ten menu

        // Luu danh sach mon an
        unordered_map <CategoryDish, vector <DiscountedDish*>>* listDish = menu.getListDish();
        for (const pair < CategoryDish, vector <DiscountedDish*>>& dish : *listDish)
        {
            // Danh sach mon an theo danh muc
            for (const DiscountedDish* normalDish : dish.second)        
            {
                for (const int& val : normalDish->getID())              // ID
                    menuFile << val;
                menuFile << endl;
                menuFile << normalDish->getName() << endl;              // Name
                menuFile << normalDish->getPrice() << endl;             // Price
                menuFile << normalDish->getCategoryNumber() << endl;    // Category number
                menuFile << normalDish->getDiscount() << endl;          // Rate discount
                menuFile << normalDish->getLimitedDish() << endl;       // limited of discount dish
            }
        }
        menuFile << "-----------------------------------" << endl;   // Ket thuc 1 menu

        menuFile.close();
    }
    else cout << "Fail to open." << endl;
    return menuFile;
}

int Menu::readFromFile(int position, Menu*& menu)
{
    fstream menuFile("Menu.txt", ios::in);
    if (menuFile.is_open() == true)
    {
        menuFile.seekg(position, ios::beg);
        unordered_map <CategoryDish, vector <DiscountedDish*>>* listDish = menu->getListDish();     // Danh muc thuc an

        string line = "";
        getline(menuFile, line);              // Menu name
        menu->setName(line);

        getline(menuFile, line);              // Take ID
        while (line.find("--") == string::npos)
        {
            DiscountedDish* dish = new DiscountedDish;
            vector <int> id(3, 0);                // ID
            int number = stoi(line);
            for (int index = id.size() - 1; index >= 0; index--)
            {
                id[index] = number % 10;
                number /= 10;
            }
            dish->setID(id);
            
            getline(menuFile, line);              // Name Dish
            dish->setName(line);

            getline(menuFile, line);              // Price
            dish->setPrice(stof(line));

            getline(menuFile, line);              // Category number
            dish->setCategoryNumber(stoi(line));

            getline(menuFile, line);              // Rate discount
            dish->setDiscount(stof(line));

            getline(menuFile, line);              // number of limited discounted dish
            dish->setLimitedDish(stoi(line));

            // Chia theo danh muc mon an de them mon an vao menu
            CategoryDish category = transformIntToCategory(dish->getCategoryNumber());
            (*listDish)[category].push_back(dish);

            getline(menuFile, line);
        }

        menu->setListDish(listDish);    // Cai dat lai menu

        int currPosition = menuFile.tellg();    // Lay vi tri hien tai cua con tro trong menuFile

        menuFile.close();
        return currPosition;
    }
    else
    {
        cout << "Fail to read" << endl;
        return EOF;
    }
}

Menu::~Menu()
{
    if (listDish != NULL)
    {
        for (const auto& dish : *listDish)
        {
            for (DiscountedDish* ele : dish.second)
            {
                delete ele;
                ele = NULL;
            }
        }
    }
    delete listDish;
    listDish = NULL;
}

ostream& operator << (ostream& output, const Menu& menu)
{
    output << "---------------------------------------------------------------" << endl;
    output << fixed << setw(35) << menu.name << endl;
    for (const auto& dish : *(menu.getListDish()))
    {
        output << "---------------------------------------------------------------" << endl;
        output << fixed << setw(35) << printKindOfDish(dish.first) << endl;
        output << "---------------------------------------------------------------" << endl;
        output << setw(10) << left << "ID" << setw(35) << left << "Name" << setw(15) << left << "Price(VND)" << setw(20) << left << "Discount(%)" << setw(20) << left << "Limited Quantity" << endl;
        for (int index = 0; index < dish.second.size(); index++)
        {
            // Ma mon an
            string idStr = "";
            for (int val : dish.second[index]->getID())
                idStr += to_string(val);

            // In ma, ten, gia, giam gia, so luong mon giam gia gioi han cua mon an
            output << setw(10) << left << idStr;
            output << setw(35) << left << dish.second[index]->getName();
            output << fixed << setprecision(1) << setw(15) << left << dish.second[index]->getPrice();
            output << fixed << setprecision(1) << setw(20) << left << dish.second[index]->getDiscount();
            output << setw(20) << left;

            string unlimited = "Unlimited";
            if (dish.second[index]->getLimitedDish() != 0)
                output << dish.second[index]->getLimitedDish() << endl;
            else output << unlimited << endl;
        }
    }
    output << endl;
    
    return output;
}

bool compare(const pair <int, vector <DiscountedDish*>>& a, const pair <int, vector <DiscountedDish*>>& b)
{
    return (a.first < b.first);
}

bool operator == (const Menu& menu1, const Menu& menu2)
{
    vector < pair <int, vector <DiscountedDish*>>> listMenu1;
    for (const auto& dish : *(menu1.listDish))
    {
        /*vector <DiscountedDish*> newDish;
        for (const DiscountedDish* iteratorDish : dish.second)
            newDish.push_back(new DiscountedDish(*iteratorDish));*/

        listMenu1.push_back({ static_cast <int>(dish.first), dish.second });
    }

    vector <pair <int, vector <DiscountedDish*>>> listMenu2;
    for (const auto& dish : *(menu2.listDish))
    {
        /*vector <DiscountedDish*> newDish;
        for (const DiscountedDish* iteratorDish : dish.second)
            newDish.push_back(new DiscountedDish(*iteratorDish));*/

        listMenu2.push_back({ static_cast <int>(dish.first), dish.second });
    }

    sort(listMenu1.begin(), listMenu1.end(), compare);
    sort(listMenu2.begin(), listMenu2.end(), compare);
    return (listMenu1 == listMenu2);
}
