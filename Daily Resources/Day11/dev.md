# Operator Overloading, Constructors and Destructors

## Table of Contents

1. [Operator Overloading](#operator-overloading)  
    1. [Introduction](#introduction)  
    2. [Syntax](#syntax)  
2. [Constructors](#constructors)  
    1. [Introduction](#introduction-1)  
    2. [Member Initializer List](#member-initializer-list)  
    3. [Constructor Delegation](#constructor-delegation)  
    4. [Inheriting Constructors](#inheriting-constructors)  
    5. [Explicit Constructors](#explicit-constructors)  
    6. [Copy Constructor](#copy-constructor)  
    7. [Default Constructor](#default-constructor)  
3. [Destructors](#destructors)  
   1. [Syntax](#syntax-1)  
   2. [Virtual Destructors](#virtual-destructors)  
4. [The Rule of Five](#the-rule-of-five)  
5. [Constructors and Destructors don't use dynamic dispatch](#constructors-and-destructors-dont-use-dynamic-dispatch)  
6. [Resources](#resources)


## Operator Overloading

Note: This is is just a wordy, less technical version of the [cppreference article](https://en.cppreference.com/w/cpp/language/operators.html), which can be read directly instead, or read after this section.

### Introduction
C++ allows you to define custom behavior for operators (like `+`, `-`, `*`, etc.) when they are used with user-defined types (classes). This is known as operator overloading.

This is useful for classes like `Complex` numbers for obvious reasons.

Note: It is only possible to overload existing operators and not define new operators in this manner. Also, logical operators like `&&`, `||`, lose their short-circuiting behavior when overloaded.

### Syntax


```cpp
class Complex {
public:
    double real, imag;
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Operator overloading as member function
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

// Non-member function for operator overloading
Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

// Operators can take parameter of other types as well
Complex operator*(double  scalar, Complex &c) {
    return Complex(c.real * scalar, c.imag * scalar);
}

// Operators can return any type, not just the class type
bool operator+(const Complex &c, double scalar) {
    return true; //This is legal, but very un-useful, don't do this
}

// You can also overload operators for built-in types
// This example overloads the << operator vector, you can add it to your CP template
template<typename T>
ostream& operator<<(ostream& o,const vector<T>& v) {for (auto& x: v) o << x << ' ';return o;}
```

The above code example should explain the following:

- Overloaded operators can be defined as member functions or non-member functions.
- Member functions are called on the left operand, while non-member functions take both operands as parameters.
- You can overload operators for user-defined types and even for built-in types.
- Operator functions can return any type, not just the class type. (but this is not common practice)

Note: The operators `=`, `[]`, `()` and `->` cannot be overloaded as non-member functions.

---

## Constructors

### Introduction
For those who are unfamiliar, a constructor is a special member function called to initialize objects of a class. It is `__init__` block in Python.

Constructors in C++ are suprisingly complicated, so don't worry about reading this in one go.

The syntax is simple: Just the class name followed by brackets and parameters, but no return type.

### Member Initializer List

Member initializer lists are the recommended way to intialise class members from parameters.

#### Basic Syntax

```cpp
class Person {
private:
    std::string name;
    int age;
    const int id;
    
public:
    Person(const std::string& n, int a, int i) 
        : name(n), age(a), id(i) {
    }
};
```

Assigning the members in the constructor simply can produce the following issues
```cpp
class Person {
private:
    std::string name;
    int age;
    const int id;
    
public:
    Person(const std::string& n, int a, int i) {
        id = i; //Error: cannot reassign const variable
        name = n; //No error: But an empty string was initaised earlier in waster; less efficient
        age = a;
    }
};
```



#### Order of Initialization

Members are initialized in the order they are declared in the class, not the order in the initializer list:

```cpp
class Example {
private:
    int a;
    int b;
    
public:
    Example(int val) : b(val), a(b + 1) { // a will get a random value becuase b is not initialized yet
    }
};
```

Thus it is best that during intialization, a parameter does not depend on other to avoid confusion.

### Constructor Delegation

Constructors can delegate to other constructors in the same class:

```cpp
class Delegating {
private:
    int value;
    std::string name;
    
public:
    Delegating() : Delegating(0, "default") {}
    
    Delegating(int v) : Delegating(v, "unnamed") {}
    
    Delegating(int v, const std::string& n) : value(v), name(n) {}
};
```

This is sometimes used instead of default values for parameters, as it allows for more complex initialization logic.


### Inheriting Constructors

Derived classes classes must call the base class constructor. They can do so explicitly by mentioning the base class constructor, or implicitly the default constructor is called if no constructor is specified.

```cpp
class Base {
public:
    Base(int value) {}
    Base(int value, const std::string& name) {}
};

class Derived : public Base {
public:
    using Base::Base;
    
    Derived(double value) : Base(static_cast<int>(value)) {}
};

Derived d1(42);
Derived d2(42, "test");
Derived d3(3.14);
```

### Explicit Constructors
All constructors are implicit by default, meaning they perform type conversion automatically. However, you can make a constructor explicit to prevent this behavior:

```cpp
class Complex {
    private:
        double real, imag;
    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}
        Complex(int r) : real(r), imag(0) {}
}

//consider this is cpp's std::vector
class Vector {
    public:
        explicit Vector(int size) : data(new int[size]), size(size) {}
        
}


int main() {
    Complex c = 5 //will work -> implicit constructor
    Vector v = 10; //will not work -> explicit constructor
    Vector v(10); //will work -> explicit constructor called directly
}
```

Here vector's constructor should be explicit to prevent accidental conversions from `int` to `Vector`

### Copy Constructor
A copy constructor is a special constructor that initializes a new object as a copy of an existing object. It is called when an object is passed by value or returned by value.

```cpp
class Complex {
public:
    double real, imag;
    
    // Default constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Copy constructor
    Complex(const Complex& other) : real(other.real), imag(other.imag) {
  
    }
};
```

The copy constructor is usually compiler-generated, to perform a shallow copy of the class members. 

### Default Constructor
Use `= default` to explicitly request compiler generation:

```cpp
class ExplicitDefault {
    int value;
    
public:
    ExplicitDefault() = default;
    ExplicitDefault(int v) : value(v) {}
};
```

Use `= delete` to prevent default constructor generation:

```cpp
class NoDefault {
public:
    NoDefault() = delete;
    NoDefault(int value) {}
};
```

---

## Destructors
The destructor is a special member function called when an object goes out of scope or is explicitly deleted. It is used to release resources, such as memory or file handles, that the object may have acquired during its lifetime.

Most classes do not need a destructor, as the compiler-generated destructor is sufficient for most cases. However, if your class manages resources (like dynamic memory), you should define a destructor to release those resources.

### Syntax
```cpp
class Resource {
private:
    // Resource members, e.g., pointers to dynamically allocated memory
    int* data;
public:
    Resource() {
        // Constructor logic
    }
    
    ~Resource() {
        delete[] data; // Release dynamically allocated memory
    }
};
```

### Virtual Destructors
If your class is intended to be a base class, you should declare its destructor as virtual. This ensures that the derived class's destructor is called when an object of the derived class is deleted through a base class pointer.

```cpp
class Base {
public:
    virtual ~Base() {
        // Base class destructor logic
    }
};
class Derived : public Base {
public:
    ~Derived() {
        // Derived class destructor logic
    }
};
```

---

## The Rule of Five
The following five are automatically generated by the compiler if not defined (includes =default and =delete):

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator
If you define any of these, you should consider defining all five to ensure proper resource management and avoid memory leaks or undefined behavior.

Note: We have not covered move semantics, it will be covered in a later.

## Constructors and Destructors don't use dynamic dispatch
Constructors create the objects, from the parent to the child, therefore they should not call virtual functions. If they do, it will call the base class version of the function, not the derived class version, because the derived class is not fully constructed yet.

Similarly, destructors should also not call virtual functions

## Resources
- [cppreference article on operator overloading](https://en.cppreference.com/w/cpp/language/operators.html)
- [cppreference article on constructors](https://en.cppreference.com/w/cpp/language/initializer_list.html)
- [cppreference article on destructors](https://en.cppreference.com/w/cpp/language/destructor.html)
- [Learncpp.com in general](https://learncpp.com/)
