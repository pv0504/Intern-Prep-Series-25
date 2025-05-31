# Virtual Functions & VTables

## Table of Contents

- [Introduction](#introduction)
- [Demonstration: Animal Hierarchy](#demonstration-animal-hierarchy)
- [Explanation](#explanation)
- [Virtual Tables (VTables)](#virtual-tables-vtables)
- [Hands-On Task](#hands-on-task)
- [Common Pitfalls](#common-pitfalls)
- [Resources](#resources)


---

## Introduction

Virtual functions are used when when *dynamic* dispatch of methods in classes is required instead of static. Unlike some languages like python/Java. The methods which have to be called are resolved at compile time by default. See the following example for explanation 

## Demonstration: Animal Hierarchy

### Code

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a generic sound" << endl;
    }
    
    virtual void sound_virtual() {
        cout << "Animal makes a generic virtual sound" << endl;
    }
    
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Woof!" << endl;
    }
    
    void sound_virtual() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() {
        cout << "Meow!" << endl;
    }
    
    void sound_virtual() override {
        cout << "Meow!" << endl;
    }
};

void call(Animal& animal) {
    animal.sound();
}
void call_virtual(Animal& animal) {
    animal.sound_virtual();
}

int main() {
    Dog dog;
    Cat cat;
    call(dog);
    call(cat);
    call_virtual(dog);
    call_virtual(cat);
    return 0;
}
```

### Output

```
Animal makes a generic sound
Animal makes a generic sound
Woof!
Meow!
```


## Explanation
In the above example only the `sound_virtual` method is marked virtual, `sound` is not. Therefore, even though the `sound` method is overriden in the base class, the compiler called the method defined in the `Animal` class, because the pointer was of type `Animal*`. The compiler decided which function to call at compile time -> Static dispatch

On the other hand, `sound_virtual` method calls the appropriate function based at the runtime. This is done through a vTable, a member of the class added at compile time by the compiler which stores which the location of the actual method that has to be called. This is Dynamic Dispatch.

All methods are virtual by default in languages like Python

### Performance Difference
Virtual functions are slower because the following reasons

- Indirection: Instead of directly executing the required method, first a pointer has to be followed to determine the function to be called
- No Compiler Optimizations: Since the compiler can directly knows the function to be called, it can perform optimizations like inlining: instead of calling the function and having the overhead of allocating a new stack frame, the compiler can inline the method at the call site. This is often done with small functions

---

## Virtual Tables (VTables)

### Structure
- **Per-class table**: Each class with virtual functions has its own vtable
- **Function pointers**: Array of pointers to virtual function implementations
- **Inheritance**: Derived classes inherit and potentially override entries
- **VPtr**: Each object contains a pointer to its class's vtable

### Memory Layout
```
Object Memory Layout:
+------------------+
| vptr             | → Points to class vtable
+------------------+
| member variables |
+------------------+

Class VTable:
+------------------+
| virtual_func1    | → Function pointer
+------------------+
| virtual_func2    | → Function pointer
+------------------+
```

---




### VTable Structure Analysis

```cpp
class Animal {
    vtable pointer
    virtual void sound_virtual()
    virtual ~Animal()
};

Animal's VTable:
[0] → Animal::sound_virtual()
[1] → Animal::~Animal()

Dog's VTable:
[0] → Dog::sound_virtual()     // Overridden
[1] → Animal::~Animal()        // Inherited

Cat's VTable:
[0] → Cat::sound_virtual()     // Overridden  
[1] → Animal::~Animal()        // Inherited
```

### Memory Layout Visualization
Consider the following example


#### Code

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Animal makes a generic sound" << endl;
    }
    
    virtual void sound_virtual() {
        cout << "Animal makes a generic virtual sound" << endl;
    }
    
};

class StaticAnimal {
public:
    void sound() {
        cout << "Static Animal makes a generic sound" << endl;
    }
    
    void sound_virtual() {
        cout << "Static Animal makes a generic virtual sound" << endl;
    }
};

int main() {
    cout << sizeof(Animal) << endl; // Size of Animal class
    cout << sizeof(StaticAnimal) << endl; // Size of Animal class
    return 0;
}
```

#### Output
```
8
1
```

#### Explanation
The only difference in the `StaticAnimal` and the `Animal` class is the presence of virtual methods. The presence of virtual methods caused the compiler to insert a pointer to vTable which increases the size of the class. 

Note: Other languages may [(and do)](https://users.rust-lang.org/t/v-tables-differences-between-rust-and-c/92445) implement the dynamic dispatch differently

---

## Hands-On Task

### Conceptual

1. Explain why `sound()` shows static dispatch behavior while `sound_virtual()` shows dynamic dispatch.
2. What happens to vtable inheritance when a derived class doesn't override a virtual function?
3. Should the destructor be virtual or non-virtual?



---

## Common Pitfalls

- Forgetting that non-virtual functions use static dispatch even through base pointers
- Assuming all member functions are virtual by default (unlike Java/C#)
- Thinking virtual functions have no performance cost
- Assuming private virtual functions cannot be overridden [(uncommon but possible)](https://stackoverflow.com/questions/2170688/private-virtual-method-in-c)
- [constructors/destructors don't use dynamic dispatch](https://stackoverflow.com/a/962148)

---

## Resources

### Reading

- [An article from learncpp.com](https://www.learncpp.com/cpp-tutorial/the-virtual-table/) 
- [C++ Virtual Function Implementation](https://shaharmike.com/cpp/vtable-part1/)


### Interactive Tools

- [Compiler Explorer - Assembly output analysis](https://godbolt.org/)

---
