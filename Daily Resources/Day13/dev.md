# References, Copy Elision, and Move Semantics in C++
This is a long topic, you will be probably won't be able to read it in one sitting. Also feel free to skim through


## Terminology
These terms are going to keep coming up, so here is a rough definition - 

- lValue: An object that has a name and a section in memory. These can generally be assigned to
- rValue: An object that does not have a name. These can never be assigned to.

Some examples for clarity:

```cpp
//these are lValues
int x = 5; // x is an lValue
const int y = 10; // y is an lValue
y = 20; //but cannot be assigned to

int foo(int a) {
    //a is an lValue
    return a + 1;
}
int (*func_ptr)(int) = &foo; //you can take pointer to functions, so functions are also an lValue
foo = 20; //another lValue, but cannot be assigned to

//these are rValues
int x = 5 + 10; //5 + 10 is an rValue, it does not have a name
int y = foo(20); //the return value of foo(20) is an rValue, it does not have a name
```

There are more details, which if you can either [read](https://en.cppreference.com/w/cpp/language/value_category.html) or [watch](https://youtu.be/XS2JddPq7GQ) but this level of understanding is sufficient for now.

## lValue References
In C, if we wanted pass by reference, we would use pointers. In C++, we instead tend to use lValue references for this purpose.
lValue references have the following differences from pointers:

- They cannot be rebound to another variable.
- They can never be null
- const value references can bind to rValues. They create temporary and then bind to it
- They have a cleaner syntax

lValue references don't really act like pointers; they instead act more as an alias, a second name, for the same object.
As usual, let's look at an example:

```cpp
void vec_push(vector<int>& v) { //syntax for lValue reference
    v.push_back(1);
}
void vec_push2(vector<int>* v) {
    if (v != NULL) v->push_back(1); //annoying arrow syntax
}
void vec_print(const vector<int>& v) { //const lValue reference -> this will work for both lValues and rValues
    for (int i : v) {
        cout << i << " ";
    }
}
void vec_print2(const vector<int>* v) { //this won't work for rValues
    if (v == NULL) return; //need to check for null
    for (int i : *v) { 
        cout << i << " ";
    }
}
//this better syntax is necessary for operator overloading
class MyString {
    public:
    string s{};

    MyString operator+(MyString& f1) { //Normal
        MyString ret;
        ret.s = s + f1.s;
        return ret;
        
    }
    
    MyString operator-(MyString* f1) { //Just to simulate what will happen with pointers in +
        MyString ret;
        ret.s = s + f1->s;
        return ret;
    }
};

int main() {
    vector<int> v {1,2,3};
    vec_push(v); //lValue reference
    vec_push2(&v); //pointer
    vec_print({1,2,3}); //can bind to rValues
    vec_print2(&{1,2,3}); //Error -> cant do this
    MyString s1, s2;
    MyString s3 = s1 + s2; //works
    MyString s4 = s1 - &s2; //ew
    
    vec_push(NULL); //does not compile => no need to check in function
    vec_push2(NULL); //compiles => need to check in function body
}
```
---

## Copy elision in C++
Most of the compiler optimizations are required to preserve the original behavior of the code, but copy elision is an exception. It allows the compiler to skip the copy constructor and directly construct the object in the target location, which can significantly improve performance.

Consider the following code as an example:

```cpp
#include <vector>
using namespace std;
vector<int> bigVector() {
    vector<int> v;
    for (int i = 0; i < 1000000; ++i) {
        v.push_back(i);
    }
    return v; // Copy elision can optimize this return
}


int main() {
    vector<int> v {bigVector()}; // Copy elision avoids unnecessary copy
    for (int i : v) {
        cout << i << " ";
    }
}
```

Without copy elision, `v` would be initialized via the copy constructor, which means deep copying the entire vector data. However, with copy elision, the compiler can optimize this by constructing `v` directly in the memory location where it will be used, avoiding the overhead of copying.
Note that this can optimization can actually change the observable behavior of the code if the copy constructor has side effects, thus it is important that the copy constructor does not do anything that affects the program state outside of the object itself. 


```cpp
class BadClass {
public:
    BadClass() {}
    BadClass(const BadClass&) { cout << "Copy constructor called"; }
    
}

BadClass createBadClass() {
    return BadClass(); 
}

int main() {
    BadClass obj { createBadClass() };
}
```
In the above example, both the outputs are valid - "Copy constructor called" and nothing.

There are two main cases for copy elision:
### Named Return Value Optimization (NRVO)
If the object being returned is a named variable, and this variable was created in the same function or passed as an argument, the copy is elided and the object is constructed directly in the memory location of the return value.

### Rvalue Optimization
If the object is being initialized with an rvalue (like a temporary object), the compiler can optimize the copy by constructing the object directly in the memory location of the target variable.

Since C++17, this is no longer just an optimization but a mandatory behavior. Because of this, the following code will compile in C++17 and later but not in C++14:

```cpp
class SomeLongString {
public:
    SomeLongString() = default;
    SomeLongString(const SomeLongString& in) = delete;
};

SomeLongString get() {
    return SomeLongString();
}

int main() {
    SomeLongString s1 = get();
}
```
try and compile it yourself: `g++ -std=c++14 -o test test.cpp`, `g++ -std=c++17 -o test test.cpp` 

The copy constructor has been deleted, so it can't construct s1 in C++14. In C++17 and later, the compiler has to skip the copy constructor and construct `s1` directly in the memory location where it will be used, thus avoiding the error.


There are other type of copy elisions, but they are for exceptions and another niche feature which are not too important.

For more details: You can read the [cppreference page](https://en.cppreference.com/w/cpp/language/copy_elision.html)


---

## Move Semantics in C++
If this topic seems complex and messy, it is because it is. Move semantics are an important part of C++ but their design is a bit weird because this had preserve backward capability with C++98 and C.

I'll greatly recommend watching [this video](https://youtu.be/Bt3zcJZIalk) but I'll also explain it here if you prefer reading.

### The need
Consider the following code:
```cpp
void swap(string& a, string& b) {
    string tmp(a);   // we've made a second copy of a
    a = b;      // we've made a second copy of b (and discarded a copy of a)
    b = tmp;    // we've made a second copy of tmp (and discarded a copy of b)
}
```

> [!NOTE]
> **How the `string` class works**
>
> `std::string` is an owned container. It stores the actual string data on the heap and deallocates it via its destructor when it goes out of scope.
>
> Its structure is conceptually something like this:
>
> > ```cpp
> > class string {
> >     char* data;      // Pointer to the string data on the heap
> >     size_t size;     // Size of the string
> >     size_t capacity; // Capacity of the string
> > };
> > ```
>
> When we pass a `string` to a function or assign one string to another (e.g., `s1 = s2`), the copy constructor is invoked. This performs a deep copy of the data from the heap, so the internal pointers differ. As a result, the strings remain separate entities in memory.


This seems extremely inefficient for a simple operation like swap. Consider if both `a` and `b` were the contents of 100Kb file, we would've made 3 copies, i.e copied 300Kb in memory for something as simple as swap

The efficient way to do this would have been to just copy around the three class members, instead copying the heap data. This is what move semantics allow us to do.

```cpp
void swap(string& a, string& b) {
    string tmp(std::move(a));
    a = std::move(b);   
    b = std::move(tmp);
}
```

### Move Constructor and Rvalue References
The actual moving is not done by the `move` function, but by the move constructor. The `move` function just casts the lValue to an rValue reference, which is then passed to the move constructor.

The move constructor of string might look something like this:

```cpp
class string {
    char* data;
    size_t size;
    size_t capacity;

    //this takes an rValue reference
    string(string&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr; //so that distructor of other does not delete the data
        other.size = 0;       
        other.capacity = 0;   
    }
}
```

Here, we stole the internals of `other` and set its internals to a default state. This way, we don't have to copy the heap data, we just copy the pointers. This is much more efficient.

### Moved from objects
Moving calls a user defined constructor, and therefore the language cannot specify what happens to the moved from object.
The specification states that the moved from object is in a valid but unspecified state. Moves should only be used when you don't need the moved from object anymore. (Side note: Rust disallows the use of moved from objects at compile time, which is a much better design)

### Pitfalls
1. because `std::move` is just a cast and not the move, It is easy to accidentally copy an object instead of moving it. Just look at this example

```cpp
void swap(string& a, string& b) {
    const string tmp(std::move(a));
    a = std::move(b);   
    b = std::move(tmp);
}
```

Here, `tmp` is a const object, move constructor expects `string&&` not `const string&&`, becuase it needs to modify its internals. This will actually invoke the copy constructor instead because rValues can bind to const lValue references.

2. Move constructor should ideally be marked `noexcept`, which means it should not throw any exceptions. Otherwise containers like `std::vector` will not use the move constructor and instead use the copy constructor while reallocating memory.

3. Rule of 5/0: The following are auto-generated by default. If you implement manually any one of them, the compiler will not auto-generate the others and you must implement all of these
   - Destructor
   - Copy constructor
   - Copy assignment operator
   - Move constructor
   - Move assignment operator

### Notes:
1. It is possible to define classes which have a move constructor but no copy constructor. These are move only values such as `std::unique_ptr`.
2. Functions like `push_back` on `std::vector` are overloaded to accept both rValue and lValue instances to copy or move depending on the context. These are called perfectly forwarding functions and are implemented as follows
```cpp
template<typename T>
void wrapper(T&& arg) {  // This is NOT an rValue reference!, just poor choice of syntax
    someFunction(std::forward<T>(arg));
}
```
I recommend to watch the [video](https://youtu.be/Bt3zcJZIalk) I linked earlier for elaboration

3. rValue references can bind to lValue references, I have mentioned earlier. Here is table to tell which reference can bind to what


| Reference Type              | lvalue | const lvalue | rvalue | rvalue-to-const |
|----------------------------|--------|--------------|--------|-----------------|
| lvalue reference           | ✅ 1   | ❌           | ❌     | ❌               |
| const lvalue reference     | ✅ 3   | ✅ 1         | ✅ 4*  | ✅ 3*            |
| rvalue reference           | ❌     | ❌           | ✅ 1   | ❌               |
| const rvalue reference     | ❌     | ❌           | ✅ 3   | ✅ 1             |
| forwarding/universal ref.  | ✅ 2   | ✅ 2         | ✅ 2   | ✅ 2             |

\* Implicitly converts rvalue to lvalue <br>
Overload resolution priority within each column (lower # = higher priority)

