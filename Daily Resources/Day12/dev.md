# RAII + Smart Pointers | Programming & OOPs

## 📚 Overview
**RAII (Resource Acquisition Is Initialization)** is a C++ programming technique where resource management is tied to object lifetime. **Smart Pointers** are objects that act like traditional pointers but automatically manage memory allocation and deallocation.

## 🎯 Key Concepts

### RAII
- Resources are acquired in constructor, released in destructor
- Automatic cleanup when objects go out of scope
- Exception safety guaranteed

### Smart Pointers (C++11+)
- **`unique_ptr`**: Exclusive ownership, cannot be copied
- **`shared_ptr`**: Shared ownership with reference counting  
- **`weak_ptr`**: Non-owning observer to break circular references

## 💡 Benefits
- **Automatic memory management** - No manual `delete` calls
- **Exception safety** - Resources cleaned up even during exceptions
- **Clear ownership semantics** - Who owns what resource

## 🔧 Quick Example

```cpp
#include <memory>
#include <iostream>

class Resource {
public:
    Resource(int val) : value(val) { // constructor
        std::cout << "Resource created: " << value << std::endl; 
    }
    ~Resource() { // destructor
        std::cout << "Resource destroyed: " << value << std::endl; 
    }
    void use() { std::cout << "Using resource: " << value << std::endl; }
private:
    int value;
};

int main() {
    // RAII with smart pointer
    {
        auto ptr = std::make_unique<Resource>(42);
        ptr->use();
    } // Automatic cleanup here
    
    std::cout << "After scope" << std::endl;
    return 0;
}
```

## 🚀 Hands-on Task

**Challenge**: Fix the memory leaks in this code using smart pointers and implement proper RAII.

```cpp
#include <iostream>
#include <vector>

class FileHandler {
public:
    FileHandler(const std::string& name) : filename(name) {
        std::cout << "Opening file: " << filename << std::endl;
        // Simulate file opening
    }
    
    ~FileHandler() {
        std::cout << "Closing file: " << filename << std::endl;
        // Simulate file closing
    }
    
    void write(const std::string& data) {
        std::cout << "Writing to " << filename << ": " << data << std::endl;
    }
    
private:
    std::string filename;
};

// BUGGY CODE - Fix this!
void buggyFunction() {
    FileHandler* file1 = new FileHandler("data.txt");
    FileHandler* file2 = new FileHandler("log.txt");
    
    file1->write("Hello World");
    file2->write("Debug info");
    
    // Memory leak! Files never closed!
    // What if exception occurs here?
}

int main() {
    buggyFunction();
    std::cout << "Program ending..." << std::endl;
    return 0;
}
```

**Your Task:**
1. Replace raw pointers with appropriate smart pointers
2. Ensure automatic file cleanup
3. Make the code exception-safe
4. Test with both `unique_ptr` and `shared_ptr` scenarios

## 📖 Resources
- [Stanford CS 106L video lecture on RAII and Smart Pointers](https://youtu.be/jdA1bH0eWFg?si=cIwiccFMbaqAJVkQ)
- [LearnCpp Chapter 22](https://www.learncpp.com/)
- [C++ Reference - Smart Pointers](https://en.cppreference.com/w/cpp/memory)
- [RAII on Stack Overflow](https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii)
