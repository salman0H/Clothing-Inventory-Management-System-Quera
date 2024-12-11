# Clothing Inventory Management System

## Overview
A C++ application for managing clothing inventory with support for shirts, pants, and detailed production date tracking.

## Features
- Date management with validation
- Clothing base class with common attributes
- Specialized shirt and pants classes
- Operator overloading for input/output
- Dynamic inventory creation
- Production date tracking

## Class Hierarchy
- `date`: Manages date information
- `Clothing`: Base class for clothing items
  - Attributes: price, size, color, production date
- `Shirt`: Derived from Clothing
  - Additional attributes: button count, sleeve length
- `Pants`: Derived from Clothing
  - Additional attributes: leg length, waist circumference

## Input Requirements
1. Number of shirts
2. Shirt details (price, size, color, production date, button count, sleeve length)
3. Number of pants
4. Pants details (price, size, color, production date, leg length, waist circumference)

## Filtering Criteria
- Displays shirts and pants with:
  - Odd production day
  - Even production month

## Prerequisites
- C++ Compiler supporting C++11 or later
- Standard C++ Library

## Compilation
```bash
g++ -std=c++11 clothing_inventory_manager.cpp -o clothing_inventory
```

## Usage Example
```
Enter a number for your Shirt: 2
Enter shirt 1 details: 100.50 M blue 15/06/1402 4 45.5
Enter shirt 2 details: 85.75 L red 20/07/1402 3 42.0

Enter a number for your Pants: 2
Enter pants 1 details: 120.00 L blue 10/05/1402 84.5 94.0
Enter pants 2 details: 95.50 M black 25/08/1402 82.0 90.5
```

## Potential Improvements
- Enhanced input validation
- Dynamic memory management
- More advanced filtering mechanisms
- Error handling

## Limitations
- Fixed month day counts
- Basic size and price validation
- Limited error checking

## Author
Salman Hashemi
