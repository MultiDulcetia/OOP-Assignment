/*
CCP4124 - Object Oriented Programming @ Multimedia University
Trimester 2410 - 2024
Assignment Topic: Restaurant / Eatery
Assignment Title: Point-of-Sale (POS) System
Group Members:  1. @MultiDulcetia
                2. @Baiyi05
                3. @riceo180
                4. @ygjiaa
*/

/*
Program Requirements:
1. At least one (1) base class.
2. At least two (2) derived classes inherited from the base class.
3. At least one (1) object for each class and one (1) has to be an array of objects.
4. At least one (1) default or parameterized constructor or overloading for each class.
5. At least one (1) friend function.
6. Apply dynamic memory allocation using keyword new and delete for any object or array of objects.
7. Must prompt user for input. (It is assumed that a user will input text and numbers in good faith and will not purposely enter text into a number field and will not key in non-alphanumeric characters for text fields.)
8. Must be written in standard C++ code using only standard libraries (standard c headers are also allowed).
9. Write sufficient comments in the script to explain your program
*/

#include <iostream>
#include <iomanip>
#include <cstring>


// we define constants for tax and service charge as well as the maximum number of food items
const double TAX = 0.08;
const double SERVICE_CHARGE = 0.1;
const int MAX_FOOD_ITEMS = 100;

class food
{
private:
    std::string name;
    int id;
    int price, quantity;
    float discount;
    bool isAvailable;
    bool hasDiscount;

public:
    food();                                                                                                      // default constructor
    food(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount);               // parameterized constructor
    food(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount); // overloaded constructor
    ~food();                                                                                                     // destructor

    // accessor functions
    std::string getName();
    int getID();
    int getPrice();
    int getQuantity();
    float getDiscount();
    bool getIsAvailable();
    bool getHasDiscount();

    // mutator functions
    void setName(std::string name);
    void setID(int id);
    void setPrice(int price);
    void setQuantity(int quantity);
    void setDiscount(float discount);
    void setIsAvailable(bool isAvailable);
    void setHasDiscount(bool hasDiscount);
};

food ::food() : name(""), id(0), price(0), quantity(0), discount(0.0), isAvailable(true), hasDiscount(false)
{
    std::cout << "Food created\n";
}
food ::food(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount)
    : name(name), id(id), price(price), quantity(quantity), discount(discount), isAvailable(isAvailable), hasDiscount(hasDiscount)
{
    std::cout << "Food created\n";
}

food ::food(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount)
    : name(name), id(id), price(price), discount(discount), isAvailable(isAvailable), hasDiscount(hasDiscount)
{
    std::cout << "Food created\n";
}

food ::~food()
{
    std::cout << "Food deconstructed\n";
}

std::string food::getName()
{
    return name;
}

int food::getID()
{
    return id;
}

int food::getPrice()
{
    return price;
}

int food::getQuantity()
{
    return quantity;
}

float food::getDiscount()
{
    return discount;
}

bool food::getIsAvailable()
{
    return isAvailable;
}

bool food::getHasDiscount()
{
    return hasDiscount;
}

void food::setName(std::string name)
{
    this->name = name;
}

void food::setID(int id)
{
    this->id = id;
}

void food::setPrice(int price)
{
    this->price = price;
}

void food::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void food::setDiscount(float discount)
{
    this->discount = discount;
}

void food::setIsAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}

void food::setHasDiscount(bool hasDiscount)
{
    this->hasDiscount = hasDiscount;
}

class AsianFood : public food // requirement 2 completed (derived class)
{
    std::string souptype;

public:
    AsianFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount);
    AsianFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount);
    AsianFood() : food(){};
    ~AsianFood();
};

AsianFood::AsianFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, quantity, discount, isAvailable, hasDiscount)
{
    std::cout << "Asian food created\n";
}

AsianFood::AsianFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, discount, isAvailable, hasDiscount)
{
    std::cout << "Asian food created\n";
}

AsianFood ::~AsianFood()
{
    std::cout << "Asian food deconstructed\n";
}

class WesternFood : public food // requirement 2 completed (derived class)
{
public:
    WesternFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount);
    WesternFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount);
    WesternFood() : food(){};
    ~WesternFood(){};
};

WesternFood ::WesternFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, quantity, discount, isAvailable, hasDiscount)
{
    std::cout << "Western food created\n";
}

WesternFood ::WesternFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, discount, isAvailable, hasDiscount)
{
    std::cout << "Western food created\n";
}

class EuropeanFood : public food // requirement 2 completed (derived class)
{
public:
    EuropeanFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount);
    EuropeanFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount);
    ~EuropeanFood(){};
};

EuropeanFood ::EuropeanFood(std::string name, int id, int price, int quantity, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, quantity, discount, isAvailable, hasDiscount)
{
    std::cout << "Western food created\n";
}

EuropeanFood ::EuropeanFood(std::string name, int id, int price, float discount, bool isAvailable, bool hasDiscount)
    : food(name, id, price, discount, isAvailable, hasDiscount)
{
    std::cout << "Western food created\n";
}

class drinks
{
private:
    std::string name;
    int id;
    int price;
    bool isAvailable;

public:
    drinks();
    drinks(std::string name, int id, int price);
    ~drinks();

    std::string getName() { return name; };
    int getID() { return id; };
    int getPrice() { return price; };
    bool getIsAvailable() { return isAvailable; };
    void setName(std::string name) { this->name = name; };
    void setID(int id) { this->id = id; };
    void setPrice(int price) { this->price = price; };
    void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; };
};

drinks::drinks() : name(""), id(0), price(0) {}
drinks ::drinks(std::string name, int id, int price) : name(name), id(id), price(price)
{
    std::cout << "Drinks created\n";
}

drinks ::~drinks()
{
    std::cout << "Drinks deconstructed\n";
}

void displayAsianFood(const std::string &category, AsianFood AsianFoodS[], int asianSize)
{
    std::cout << "Displaying " << category << " menu.\n";
    for (int i = 0; i < asianSize; i++)
    {
        std::cout << i + 1 << ". " << AsianFoodS[i].getName() << " - RM" << AsianFoodS[i].getPrice() << std::endl;
    }
}

void displayWesternFood(const std::string &category, WesternFood WesternFoodS[], int westernSize)
{
    std::cout << "Displaying " << category << " menu.\n";
    for (int i = 0; i < westernSize; i++)
    {
        std::cout << i + 1 << ". " << WesternFoodS[i].getName() << " - RM" << WesternFoodS[i].getPrice() << std::endl;
    }
}

void displayEuropeanFood(const std::string &category, EuropeanFood EuropeanFoodS[], int europeanSize)
{
    std::cout << "Displaying " << category << " menu.\n";
    for (int i = 0; i < europeanSize; i++)
    {
        std::cout << i + 1 << ". " << EuropeanFoodS[i].getName() << " - RM" << EuropeanFoodS[i].getPrice() << std::endl;
    }
}

void displayDrinks(const std::string &category, drinks Drinks[], int drinksSize)
{
    std::cout << "Displaying " << category << " menu.\n";
    for (int i = 0; i < drinksSize; i++)
    {
        std::cout << i + 1 << ". " << Drinks[i].getName() << " - RM" << Drinks[i].getPrice() << std::endl;
    }
}

// base class - requirement 1 completed
class table
{
private:
    int location; // number of table
    int capacity;
    bool membership;          // does the customer have a membership
    bool isOccupied;          // is the table occupied
    double totalBill;         // total bill of the table
    std::string orderedItems; // items ordered by the customer
    int orderedItemsQuantity; // quantity of items ordered by the customer

public:
    table();
    ~table();

    // accessor functions
    int getLocation();
    int getCapacity();
    bool isMember();
    bool getIsOccupied();
    int getTotalBill();
    std::string getOrderedItems();
    int getOrderedItemsQuantity();

    // mutator functions
    void setLocation(int);
    void setCapacity(int);
    void setMembership(bool);
    void setIsOccupied(bool);
    void setTotalBill(double);
    void setOrderedItems(std::string);
    void setOrderedItemsQuantity(int);
    friend void order(table *tables, int numTables, AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[]); // requirement 5 completed (friend function)
};

// accessor functions
int table::getLocation()
{
    return location;
}

int table::getCapacity()
{
    return capacity;
}

bool table::isMember()
{
    return membership;
}

bool table::getIsOccupied()
{
    return isOccupied;
}

int table::getTotalBill()
{
    return totalBill;
}

std::string table::getOrderedItems()
{
    return orderedItems;
}

int table::getOrderedItemsQuantity()
{
    return orderedItemsQuantity;
}

// mutator functions
void table::setLocation(int location)
{
    this->location = location;
}

void table::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void table::setMembership(bool isMember)
{
    this->membership = isMember;
}

void table::setIsOccupied(bool isOccupied)
{
    this->isOccupied = isOccupied;
}

void table::setTotalBill(double totalBill)
{
    this->totalBill = totalBill;
}

void table::setOrderedItems(std::string orderedItems)
{
    this->orderedItems = orderedItems;
}

void table::setOrderedItemsQuantity(int orderedItemsQuantity)
{
    this->orderedItemsQuantity = orderedItemsQuantity;
}

table::table()
    : location(0), capacity(0), membership(false), isOccupied(false), totalBill(0.0)
{
    std::cout << "Table created\n";
}

table::~table()
{
    std::cout << "Table deconstructed\n";
}

void order(table *tables, int numTables, AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[])
{
    int location;
    std::cout << "Enter table number: ";
    std::cin >> location;

    for (int i = 0; i < numTables; ++i)
    {
        if (tables[i].getLocation() == location)
        {
            if (tables[i].getIsOccupied() == true)
            {
                std::cout << "Table is already occupied.\n";
                return;
            }

            int capacity;
            std::cout << "Enter capacity: ";
            std::cin >> capacity;

            int userChoice;
            int foodChoice;
            int quantity;
            double subtotal = 0.0;

            do
            {
                system("cls"); // clear terminal (Windows only)
                std::cout << "Menu\n";
                std::cout << "1. Asian Food\n";
                std::cout << "2. Western Food\n";
                std::cout << "3. European Food\n";
                std::cout << "4. Drinks\n";
                std::cout << "5. Finish Ordering\n";

                std::cout << "Enter your choice: ";
                std::cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                    displayAsianFood("Asian Food", AsianFoodS, 2);
                    std::cout << "Enter your choice: ";
                    std::cin >> foodChoice;
                    tables[location - 1].setOrderedItems(AsianFoodS[foodChoice - 1].getName());
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    tables[location - 1].setOrderedItemsQuantity(quantity);
                    if (foodChoice >= 1 && foodChoice <= 2 && quantity > 0)
                    {
                        subtotal += AsianFoodS[foodChoice - 1].getPrice() * quantity;
                        std::cout << "Added " << quantity << " of " << AsianFoodS[foodChoice - 1].getName() << " to order.\n";
                    }
                    else
                    {
                        std::cout << "Invalid choice or quantity.\n";
                    }
                    break;
                case 2:
                    displayWesternFood("Western Food", WesternFoodS, 2);
                    std::cout << "Enter your choice: ";
                    std::cin >> foodChoice;
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    if (foodChoice >= 1 && foodChoice <= 2 && quantity > 0)
                    {
                        subtotal += WesternFoodS[foodChoice - 1].getPrice() * quantity;
                        std::cout << "Added " << quantity << " of " << WesternFoodS[foodChoice - 1].getName() << " to order.\n";
                    }
                    else
                    {
                        std::cout << "Invalid choice or quantity.\n";
                    }
                    break;
                case 3:
                    displayEuropeanFood("European Food", EuropeanFoodS, 2);
                    std::cout << "Enter your choice: ";
                    std::cin >> foodChoice;
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    if (foodChoice >= 1 && foodChoice <= 2 && quantity > 0)
                    {
                        subtotal += EuropeanFoodS[foodChoice - 1].getPrice() * quantity;
                        std::cout << "Added " << quantity << " of " << EuropeanFoodS[foodChoice - 1].getName() << " to order.\n";
                    }
                    else
                    {
                        std::cout << "Invalid choice or quantity.\n";
                    }
                    break;
                case 4:
                    displayDrinks("Drinks", Drinks, 2);
                    std::cout << "Enter your choice: ";
                    std::cin >> foodChoice;
                    std::cout << "Enter quantity: ";
                    std::cin >> quantity;
                    if (foodChoice >= 1 && foodChoice <= 2 && quantity > 0)
                    {
                        subtotal += Drinks[foodChoice - 1].getPrice() * quantity;
                        std::cout << "Added " << quantity << " of " << Drinks[foodChoice - 1].getName() << " to order.\n";
                    }
                    else
                    {
                        std::cout << "Invalid choice or quantity.\n";
                    }
                    break;
                case 5:
                    break;
                default:
                    std::cout << "Invalid choice.\n";
                    break;
                }

            } while (userChoice != 5);

            bool membership;
            std::cout << "Is customer a member? (1/0): ";
            std::cin >> membership;

            tables[i].setCapacity(capacity);
            tables[i].setMembership(membership);
            tables[i].setIsOccupied(true);

            tables[i].setTotalBill(subtotal);
            std::cout << "Order placed for Table " << location << ". \nTotal bill : RM" << std::fixed << std::setprecision(2) << tables[i].getTotalBill() << std::endl;
            std::cout << "Table " << location << " is now occupied.\n";
            return;
        }
    }
    std::cout << "Table not found.\n";
}

void payment(table *tables, int numTables)
{
    system("cls"); // clear terminal (Windows only)
    int location;
    std::cout << "Enter table number for payment: ";
    std::cin >> location;

    for (int i = 0; i < numTables; ++i)
    {
        if (tables[i].getLocation() == location && tables[i].getIsOccupied())
        {
            double totalBill = tables[i].getTotalBill();
            double tax = totalBill * TAX;
            double serviceCharge = totalBill * SERVICE_CHARGE;
            double finalBill = totalBill + tax + serviceCharge;

            std::cout << "Table Number: " << location << std::endl;
            std::cout << "Total Bill: RM" << std::fixed << std::setprecision(2) << totalBill << std::endl;
            std::cout << "Tax: RM" << tax << std::endl;
            std::cout << "Service Charge: RM" << serviceCharge << std::endl;
            std::cout << "Final Bill: RM" << finalBill << std::endl;

            tables[i].setTotalBill(0.0);
            tables[i].setIsOccupied(false);
            tables[i].setCapacity(0);
            tables[i].setMembership(false);

            std::cout << "Payment processed successfully.\n";
            return;
        }
    }
    std::cout << "Table not found or not occupied.\n";
}

bool allTablesPaid(table *tables, int numTables)
{
    for (int i = 0; i < numTables; ++i)
    {
        if (tables[i].getIsOccupied())
        {
            return false;
        }
    }
    return true;
}

void addFoodItem(AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[], int &asianSize, int &westernSize, int &europeanSize, int &drinksSize)
{
    int category;
    std::cout << "Select category to add food item:\n";
    std::cout << "1. Asian Food\n";
    std::cout << "2. Western Food\n";
    std::cout << "3. European Food\n";
    std::cout << "4. Drinks\n";
    std::cin >> category;

    switch (category)
    {
    case 1:
        if (asianSize < MAX_FOOD_ITEMS)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter price: ";
            std::cin >> price;

            std::cout << "Enter discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            AsianFoodS[asianSize++] = AsianFood(name, id, price, discount, isAvailable, hasDiscount);
            std::cout << "Asian food item added.\n";
        }
        else
        {
            std::cout << "Asian food array is full.\n";
        }
        break;
    case 2:
        if (westernSize < MAX_FOOD_ITEMS)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter price: ";
            std::cin >> price;

            std::cout << "Enter discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            WesternFoodS[westernSize++] = WesternFood(name, id, price, discount, isAvailable, hasDiscount);
            std::cout << "Western food item added.\n";
        }
        else
        {
            std::cout << "Western food array is full.\n";
        }
        break;
    case 3:
        if (europeanSize < MAX_FOOD_ITEMS)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter price: ";
            std::cin >> price;

            std::cout << "Enter discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            EuropeanFoodS[europeanSize++] = EuropeanFood(name, id, price, discount, isAvailable, hasDiscount);
            std::cout << "European food item added.\n";
        }
        else
        {
            std::cout << "European food array is full.\n";
        }
        break;
    case 4:
        if (drinksSize < MAX_FOOD_ITEMS)
        {
            std::string name;
            int id, price;
            bool isAvailable;

            std::cout << "Enter name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter price: ";
            std::cin >> price;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            Drinks[drinksSize++] = drinks(name, id, price);
            std::cout << "Drinks item added.\n";
        }
        else
        {
            std::cout << "Drinks array is full.\n";
        }
        break;
    default:
        std::cout << "Invalid category.\n";
        break;
    }
}

void deleteFoodItem(AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[], int &asianSize, int &westernSize, int &europeanSize, int &drinksSize)
{
    int category, index;
    std::cout << "Select category to delete food item:\n";
    std::cout << "1. Asian Food\n";
    std::cout << "2. Western Food\n";
    std::cout << "3. European Food\n";
    std::cout << "4. Drinks\n";
    std::cin >> category;

    switch (category)
    {
    case 1:
        displayAsianFood("Asian Food", AsianFoodS, asianSize);
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        if (index >= 1 && index <= asianSize)
        {
            for (int i = index - 1; i < asianSize - 1; ++i)
            {
                AsianFoodS[i] = AsianFoodS[i + 1];
            }
            --asianSize;
            std::cout << "Asian food item deleted.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 2:
        displayWesternFood("Western Food", WesternFoodS, westernSize);
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        if (index >= 1 && index <= westernSize)
        {
            for (int i = index - 1; i < westernSize - 1; ++i)
            {
                WesternFoodS[i] = WesternFoodS[i + 1];
            }
            --westernSize;
            std::cout << "Western food item deleted.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 3:
        displayEuropeanFood("European Food", EuropeanFoodS, europeanSize);
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        if (index >= 1 && index <= europeanSize)
        {
            for (int i = index - 1; i < europeanSize - 1; ++i)
            {
                EuropeanFoodS[i] = EuropeanFoodS[i + 1];
            }
            --europeanSize;
            std::cout << "European food item deleted.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 4:
        displayDrinks("Drinks", Drinks, drinksSize);
        std::cout << "Enter index to delete: ";
        std::cin >> index;
        if (index >= 1 && index <= drinksSize)
        {
            for (int i = index - 1; i < drinksSize - 1; ++i)
            {
                Drinks[i] = Drinks[i + 1];
            }
            --drinksSize;
            std::cout << "Drinks item deleted.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    default:
        std::cout << "Invalid category.\n";
        break;
    }
}

void modifyFoodItem(AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[], int &asianSize, int &westernSize, int &europeanSize, int &drinksSize)
{
    int category, index;
    std::cout << "Select category to modify food item:\n";
    std::cout << "1. Asian Food\n";
    std::cout << "2. Western Food\n";
    std::cout << "3. European Food\n";
    std::cout << "4. Drinks\n";
    std::cin >> category;

    switch (category)
    {
    case 1:
        displayAsianFood("Asian Food", AsianFoodS, asianSize);
        std::cout << "Enter index to modify: ";
        std::cin >> index;
        if (index >= 1 && index <= asianSize)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter new name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter new ID: ";
            std::cin >> id;

            std::cout << "Enter new price: ";
            std::cin >> price;

            std::cout << "Enter new quantity: ";
            std::cin >> quantity;

            std::cout << "Enter new discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            AsianFoodS[index - 1].setName(name);
            AsianFoodS[index - 1].setID(id);
            AsianFoodS[index - 1].setPrice(price);
            AsianFoodS[index - 1].setQuantity(quantity);
            AsianFoodS[index - 1].setDiscount(discount);
            AsianFoodS[index - 1].setIsAvailable(isAvailable);
            AsianFoodS[index - 1].setHasDiscount(hasDiscount);

            std::cout << "Asian food item modified.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 2:
        displayWesternFood("Western Food", WesternFoodS, westernSize);
        std::cout << "Enter index to modify: ";
        std::cin >> index;
        if (index >= 1 && index <= westernSize)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter new name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter new ID: ";
            std::cin >> id;

            std::cout << "Enter new price: ";
            std::cin >> price;

            std::cout << "Enter new quantity: ";
            std::cin >> quantity;

            std::cout << "Enter new discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            WesternFoodS[index - 1].setName(name);
            WesternFoodS[index - 1].setID(id);
            WesternFoodS[index - 1].setPrice(price);
            WesternFoodS[index - 1].setQuantity(quantity);
            WesternFoodS[index - 1].setDiscount(discount);
            WesternFoodS[index - 1].setIsAvailable(isAvailable);
            WesternFoodS[index - 1].setHasDiscount(hasDiscount);

            std::cout << "Western food item modified.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 3:
        displayEuropeanFood("European Food", EuropeanFoodS, europeanSize);
        std::cout << "Enter index to modify: ";
        std::cin >> index;
        if (index >= 1 && index <= europeanSize)
        {
            std::string name;
            int id, price, quantity;
            float discount;
            bool isAvailable, hasDiscount;

            std::cout << "Enter new name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter new ID: ";
            std::cin >> id;

            std::cout << "Enter new price: ";
            std::cin >> price;

            std::cout << "Enter new quantity: ";
            std::cin >> quantity;

            std::cout << "Enter new discount: ";
            std::cin >> discount;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            std::cout << "Has discount? (1/0): ";
            std::cin >> hasDiscount;

            EuropeanFoodS[index - 1].setName(name);
            EuropeanFoodS[index - 1].setID(id);
            EuropeanFoodS[index - 1].setPrice(price);
            EuropeanFoodS[index - 1].setQuantity(quantity);
            EuropeanFoodS[index - 1].setDiscount(discount);
            EuropeanFoodS[index - 1].setIsAvailable(isAvailable);
            EuropeanFoodS[index - 1].setHasDiscount(hasDiscount);

            std::cout << "European food item modified.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 4:
        displayDrinks("Drinks", Drinks, drinksSize);
        std::cout << "Enter index to modify: ";
        std::cin >> index;
        if (index >= 1 && index <= drinksSize)
        {
            std::string name;
            int id, price;
            bool isAvailable;

            std::cout << "Enter new name: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, name);

            std::cout << "Enter new ID: ";
            std::cin >> id;

            std::cout << "Enter new price: ";
            std::cin >> price;

            std::cout << "Is available? (1/0): ";
            std::cin >> isAvailable;

            Drinks[index - 1].setName(name);
            Drinks[index - 1].setID(id);
            Drinks[index - 1].setPrice(price);
            Drinks[index - 1].setIsAvailable(isAvailable);

            std::cout << "Drinks item modified.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;

    default:
        std::cout << "Invalid category.\n";
        break;
    }
}

void setFoodAvailability(AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[], int &asianSize, int &westernSize, int &europeanSize, int &drinksSize)
{
    int category, index;
    std::cout << "Select category to set food availability:\n";
    std::cout << "1. Asian Food\n";
    std::cout << "2. Western Food\n";
    std::cout << "3. European Food\n";
    std::cout << "4. Drinks\n";
    std::cin >> category;

    switch (category)
    {
    case 1:
        displayAsianFood("Asian Food", AsianFoodS, asianSize);
        std::cout << "Enter index to toggle availability: ";
        std::cin >> index;
        if (index >= 1 && index <= asianSize)
        {
            bool currentAvailability = AsianFoodS[index - 1].getIsAvailable();
            AsianFoodS[index - 1].setIsAvailable(!currentAvailability);
            std::cout << "Asian food availability updated.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 2:
        displayWesternFood("Western Food", WesternFoodS, westernSize);
        std::cout << "Enter index to toggle availability: ";
        std::cin >> index;
        if (index >= 1 && index <= westernSize)
        {
            bool currentAvailability = WesternFoodS[index - 1].getIsAvailable();
            WesternFoodS[index - 1].setIsAvailable(!currentAvailability);
            std::cout << "Western food availability updated.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 3:
        displayEuropeanFood("European Food", EuropeanFoodS, europeanSize);
        std::cout << "Enter index to toggle availability: ";
        std::cin >> index;
        if (index >= 1 && index <= europeanSize)
        {
            bool currentAvailability = EuropeanFoodS[index - 1].getIsAvailable();
            EuropeanFoodS[index - 1].setIsAvailable(!currentAvailability);
            std::cout << "European food availability updated.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    case 4:
        displayDrinks("Drinks", Drinks, drinksSize);
        std::cout << "Enter index to toggle availability: ";
        std::cin >> index;
        if (index >= 1 && index <= drinksSize)
        {
            bool currentAvailability = Drinks[index - 1].getIsAvailable();
            Drinks[index - 1].setIsAvailable(!currentAvailability);
            std::cout << "Drinks availability updated.\n";
        }
        else
        {
            std::cout << "Invalid index.\n";
        }
        break;
    default:
        std::cout << "Invalid category.\n";
        break;
    }
}

void adminOperations(AsianFood AsianFoodS[], WesternFood WesternFoodS[], EuropeanFood EuropeanFoodS[], drinks Drinks[], int asianSize, int westernSize, int europeanSize, int drinksSize)
{
    int adminChoice;
    do
    {
        system("cls"); // clear terminal (Windows only)
        std::cout << "Admin Menu\n";
        std::cout << "1. Add Food Item\n";
        std::cout << "2. Delete Food Item\n";
        std::cout << "3. Modify Food Item\n";
        std::cout << "4. Set Food Availability\n";
        std::cout << "5. Exit Admin Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> adminChoice;

        switch (adminChoice)
        {
        case 1:
            addFoodItem(AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks, asianSize, westernSize, europeanSize, drinksSize);
            break;
        case 2:
            deleteFoodItem(AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks, asianSize, westernSize, europeanSize, drinksSize);
            break;
        case 3:
            modifyFoodItem(AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks, asianSize, westernSize, europeanSize, drinksSize);
            break;
        case 4:
            setFoodAvailability(AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks, asianSize, westernSize, europeanSize, drinksSize);
            break;
        case 5:
            std::cout << "Exiting Admin Menu.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    } while (adminChoice != 5);
}

int main()
{
    // variables
    int userChoice;
    bool userContinue = false;

    // object creation
    table *Tables = new table[25]; // requirement 3 + 6 completed (array of objects & Dynamic Memory Allocation)
    for (int i = 0; i < 25; i++)
    {
        Tables[i].setLocation(i + 1);
        Tables[i].setIsOccupied(false);
    }
    // AsianFood
    AsianFood AsianFoodS[] = {AsianFood("Sushi", 1, 10, 1, 0.0, true, false), AsianFood("Ramen", 2, 15, 1, 0.0, true, false)};
    int asianSize = 2;
    // WesternFood
    WesternFood WesternFoodS[] = {WesternFood("Burger", 3, 20, 1, 0.0, true, false), WesternFood("Steak", 4, 30, 1, 0.0, true, false)};
    int westernSize = 2;
    // EuropeanFood
    EuropeanFood EuropeanFoodS[] = {EuropeanFood("Pasta", 5, 25, 1, 0.0, true, false), EuropeanFood("Pizza", 6, 18, 1, 0.0, true, false)};
    int europeanSize = 2;
    // Drinks
    drinks Drinks[] = {drinks("Coke", 7, 5), drinks("Juice", 8, 8)};
    int drinksSize = 2;

    do // while loop to continue the program
    {
        // display menu
        system("pause"); // pause terminal (Windows only)
        system("cls");   // clear terminal (Windows only)
        std::cout << "Welcome to the POS System\n";
        std::cout << "1. Order\n";
        std::cout << "2. Payment\n";
        std::cout << "3. Admin Operations\n";
        std::cout << "4. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            system("cls");                                                      // clear terminal (Windows only)
            order(Tables, 25, AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks); // call order function
            break;
        case 2:
            payment(Tables, 25); // call payment function
            break;
        case 3:
            adminOperations(AsianFoodS, WesternFoodS, EuropeanFoodS, Drinks, asianSize, westernSize, europeanSize, drinksSize); // call adminOperations function
            break;
        case 4:
            if (allTablesPaid(Tables, 25)) // check if all tables are paid
            {
                std::cout << "All tables have been paid. Exiting...\n";
                delete[] Tables; // deallocate memory
                system("pause"); // pause terminal (Windows only)
                return 0;        // exit the program
            }
            else
            {
                std::cout << "There are unpaid tables. Please ensure that all tables have been paid before exiting.\n";
                for (size_t i = 0; i < 25; i++) // loop through all tables to display unpaid tables
                {
                    if (Tables[i].getIsOccupied())
                    {
                        std::cout << "Table " << Tables[i].getLocation() << " is still occupied.\n";
                    }
                }
            }
            break;
        default:
            std::cout << "Invalid choice!\n";
            break;
        }

    } while (1);

    delete[] Tables; // deallocate memory

    return 0;
}