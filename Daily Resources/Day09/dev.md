# Object-Oriented Programming (OOP) Principles

## Table of Contents
- [Introduction](#introduction)
- [Core OOP Principles](#core-oop-principles)
  - [1. Encapsulation](#1-encapsulation)
  - [2. Inheritance](#2-inheritance)
  - [3. Polymorphism](#3-polymorphism)
  - [4. Abstraction](#4-abstraction)
- [Additional OOP Concepts](#additional-oop-concepts)
- [Resources](#resources)

## Introduction

Object-Oriented Programming (OOP) is a programming paradigm that organizes code into objects and classes. It provides a way to structure programs so that properties and behaviors are bundled into individual objects. OOP makes code more modular, reusable, and easier to maintain.

**Why OOP Matters:**
- **Code Reusability**: Write once, use multiple times
- **Modularity**: Break complex problems into smaller, manageable pieces
- **Maintainability**: Easier to debug and modify code
- **Real-world Modeling**: Maps naturally to real-world entities and relationships

## Core OOP Principles

### 1. Encapsulation

**Definition**: Encapsulation is the bundling of data (attributes) and methods (functions) that operate on that data into a single unit (class), while restricting direct access to some components.

**Key Features:**
- **Data Hiding**: Internal implementation details are hidden from outside
- **Access Control**: Use of access modifiers (private, protected, public)
- **Interface**: Controlled way to interact with object's data

**Example (C++):**
```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;  // Private attribute

public:
    // Constructor
    BankAccount(string accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance) {}
    
    // Public method to get balance
    double getBalance() const {
        return balance;
    }
    
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    string getAccountNumber() const {
        return accountNumber;
    }
};
```

**Benefits:**
- Security: Prevents unauthorized access to data (In the above example, balance and account number can be accessed via the respective public methods only. User cannot directly access these attributes and modify them.)
- Flexibility: Internal implementation can change without affecting external code
- Validation: Control how data is modified

### 2. Inheritance

**Definition**: Inheritance allows a class (child/derived class) to inherit properties and methods from another class (parent/base class).

**Types of Inheritance:**
- **Single Inheritance**: One child class inherits from one parent class
- **Multiple Inheritance**: One child class inherits from multiple parent classes
- **Multilevel Inheritance**: Chain of inheritance (A → B → C)
- **Hierarchical Inheritance**: Multiple child classes inherit from one parent
- **Hybrid Inheritance**: Combination of multiple inheritance types

**Example (C++):**
```cpp
#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    string brand;
    int year;
    
public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    
    virtual void start() {
        cout << "Vehicle is starting..." << endl;
    }
    
    virtual ~Vehicle() {}  // Virtual destructor
};

// Derived class
class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}
    
    void start() override {
        cout << "Car engine is starting..." << endl;
    }
    
    void honk() {
        cout << "Car is honking!" << endl;
    }
    
    int getDoors() const { return doors; }
};
```

**Benefits:**
- Code Reusability: Avoid writing duplicate code
- Extensibility: Easy to add new features
- Maintainability: Changes in base class reflect in derived classes

### 3. Polymorphism

**Definition**: Polymorphism allows objects of different types to be treated as objects of a common base type, while maintaining their specific behaviors.

**Types:**
- **Compile-time Polymorphism**: [Method overloading](https://www.programiz.com/cpp-programming/function-overloading), [operator overloading](https://www.programiz.com/cpp-programming/operator-overloading)
- **Runtime Polymorphism**: [Method overriding, virtual functions](https://www.programiz.com/cpp-programming/virtual-functions)

**Example (C++):**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function (assigning 0 to a virtual function makes it a pure virtual function. this means that such a function has no implementation in the base class. any derived class must provide an implementation for this and use the override keyword. Pure virtual functions are used to define an interface or contract that derived classes must fulfill.)
    virtual double area() = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
    
    double area() override {
        return width * height;
    }
};

// Polymorphic function
void drawShape(Shape* shape) {
    shape->draw();
    cout << "Area: " << shape->area() << endl;
}
```

**Benefits:**
- Flexibility: Same interface for different implementations
- Extensibility: Easy to add new types without changing existing code
- Maintainability: Reduces conditional statements

### 4. Abstraction

**Definition**: Abstraction hides complex implementation details while exposing only the essential features and functionality.

**Implementation Methods:**
- **Abstract Classes**: Classes that cannot be instantiated directly
- **Interfaces**: Contracts that define what methods a class must implement
- **Abstract Methods**: Methods declared without implementation

**Example (C++):**
```cpp
#include <iostream>
using namespace std;

// Abstract base class
class DatabaseConnection {
public:
    virtual void connect() = 0;  // Pure virtual function
    virtual void executeQuery(string query) = 0;
    virtual void close() = 0;
    virtual ~DatabaseConnection() {}  // Virtual destructor
};

class MySQLConnection : public DatabaseConnection {
public:
    void connect() override {
        cout << "Connecting to MySQL database..." << endl;
    }
    
    void executeQuery(string query) override {
        cout << "Executing MySQL query: " << query << endl;
    }
    
    void close() override {
        cout << "Closing MySQL connection" << endl;
    }
};

class PostgreSQLConnection : public DatabaseConnection {
public:
    void connect() override {
        cout << "Connecting to PostgreSQL database..." << endl;
    }
    
    void executeQuery(string query) override {
        cout << "Executing PostgreSQL query: " << query << endl;
    }
    
    void close() override {
        cout << "Closing PostgreSQL connection" << endl;
    }
};
```

**Benefits:**
- Simplicity: Hide complex details from users
- Focus: Developers can focus on what objects do, not how they do it
- Modularity: Changes in implementation don't affect users

## Additional OOP Concepts

### Composition vs Inheritance
- **Inheritance**: "is-a" relationship (Car is a Vehicle)
- **Composition**: "has-a" relationship (Car has an Engine)

### [SOLID Principles](https://www.baeldung.com/solid-principles)
1. **S**ingle Responsibility Principle
2. **O**pen/Closed Principle
3. **L**iskov Substitution Principle
4. **I**nterface Segregation Principle
5. **D**ependency Inversion Principle

### Design Patterns
Common OOP design patterns:
- **Singleton**: Ensure only one instance of a class
- **Factory**: Create objects without specifying exact classes
- **Observer**: Notify multiple objects about state changes
- **Strategy**: Define family of algorithms and make them interchangeable

## Resources

### Online Resources
- [C++ OOP Concepts](https://www.learncpp.com/)
- [Geeks For Geeks OOPS in CPP](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)

### Practice Platforms
- **LeetCode**: OOP design problems
- **GeeksforGeeks**: OOP concepts and examples
- **HackerRank**: Object-oriented programming challenges
- **Coursera**: Object-Oriented Design courses
