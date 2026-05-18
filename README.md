# Project Name
Food Ordering System
## Introduction
This project is a C++ console application that describes how working a simple restaurant ordering system.

The system allows customers to view menus, choose dishes, place orders, and check their order information. It also allows staff to manage menus, view customer orders, and update the order status.

**Goal**: Practice OOP in C++, file handling, class design follow **`SOLID principle`**, inheritance, basic order management logic.
## Features
### 1. Customer Features

- View available restaurant menus
- Choose dishes by dish code
- Select quantity for each dish
- Place one or more orders
- View order information
- View total price of an order
- Support discounted dishes with limited quantity

### 2. Staff Features

- View customer orders
- Update order status
- Add a new menu
- Remove an existing menu
- Display order details for staff management

### 3. System Features

- Read menu data from `Menu.txt`
- Save new menu data to `Menu.txt`
- Group dishes by category
- Calculate total price with restaurant mission
- Generate random customer IDs and order IDs

## Technologies

- C++
- OOP
- File handling with `fstream`
- SOLID Principle

## Architechture/Flow
### 1. System Flow

```text
Start Program
     ↓
Load menu data from Menu.txt
     ↓
Show main menu
     ↓
User chooses Staff mode or Customer mode
     ↓
Customer places orders / Staff manages orders
     ↓
System displays order information based on User (Staff/Customer) mode
```

### 2. Customer Order Flow

```text
Customer
   ↓
Choose menu
   ↓
Choose dish code and quantity
   ↓
System checks dish information
   ↓
System adds dish to order
   ↓
System calculates total price
   ↓
Customer views order information
```

### 3. Staff Management Flow

```text
Staff
   ↓
View customer orders
   ↓
Update order status
   ↓
Add or remove menu
   ↓
Display updated restaurant information
```

### 4. Class Diagram
![Food Ordering System Class Diagram](Food%20Ordering%20System.png)
## Project Structure
```bash
Food-Ordering-System-main/
│
├── main.cpp                  # Entry point of the program
│
├── Common.h                  # Common libraries, enums, constants
├── Common.cpp                # Helper functions for category and status display
│
├── User.h                    # Abstract base class for users
├── User.cpp                  # User implementation file
│
├── Customer.h                # Customer class and customer helper functions
├── Customer.cpp              # Customer order logic
│
├── Staff.h                   # Staff class
├── Staff.cpp                 # Staff management logic
│
├── Restaurant.h              # Restaurant class
├── Restaurant.cpp            # Restaurant menu and staff management
│
├── Dish.h                    # Base Dish class
├── Dish.cpp                  # Dish information logic
│
├── DiscountedDish.h          # Discounted dish class
├── DiscountedDish.cpp        # Discount and limited quantity logic
│
├── Menu.h                    # Menu class
├── Menu.cpp                  # Read/write menu data and display menu
│
├── Order.h                   # Order class
├── Order.cpp                 # Order status, timestamp, and total price calculation
│
├── Setting.h                 # Restaurant setup functions
├── Setting.cpp               # Menu and staff setup logic
│
├── User_Interface.h          # Console UI function declarations
├── User_Interface.cpp        # Console UI and user mode handling
│
├── Menu.txt                  # Sample menu data
│
├── Food Ordering System.png  # Project diagram/image
│
├── .gitignore
│
└── README.md
```
### 1. Menu data format
The project stores menu data in `Menu.txt`.

Example:

```text
MENU MAN
991
Sup toc tien
25000
1
0
0
-----------------------------------
```

Each dish is stored with the following information:

```text
Dish ID
Dish name
Price
Category number
Discount percentage
Limited discount quantity
```

Category numbers:

```text
1 = APPETIZER
2 = MAIN_COURSE
3 = DESSERT
4 = DRINK
```
## What I learn?

1. Design a small system C++ application
2. Apply OOP in a real example
3. Organize code into multiple `.h` and `.cpp` files
4. Separate responsibilities between customer, staff, menu, and order logic
5. Apply principle Open/Close, Liskov Substitution in application

## Future Improvement

1. Better input validation
2. Login system for staff and customers
3. Order history storage
5. Cross-platform support for Windows, Linux, and macOS
6. Unit tests for edge case (wrong user input, caculation price)
7. A simple GUI version using Qt

## Author
- **Full Name**: Nguyen Kim Huy
- **Major**: Automotive Engineering Technology
- **Github**: ***https://github.com/n-k-huy***
