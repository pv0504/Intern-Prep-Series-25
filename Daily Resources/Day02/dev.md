# DevClub Intern Prep – Day 2

## 📌 Topic: Stack vs Heap + Memory Layout

### 🧠 What’s This About?

When you write code that uses variables, arrays, or dynamically allocated memory, where do these actually live in memory?

Today’s topic helps you understand:
- The difference between **stack** and **heap**
- How functions use stack memory (call frames, local variables)
- When and why heap memory is used (`new` / `malloc`)
- The overall memory layout of a C/C++ process

---

### 📚 Resources

**🎥 Main Video:**  
[Stack vs Heap Memory Explained](https://youtu.be/bbym08gSWvQ?si=G3ptKVIKoQ3O8j5E) 

**📖 Read:**  
[Memory Layout of C Programs – GeeksforGeeks](https://www.geeksforgeeks.org/memory-layout-of-c-program/)

**🧠 Optional Deep Dive:**  
[Process Memory Layout – OSDev Wiki](https://wiki.osdev.org/Memory_Management)

---

### 🛠️ Hands-on Task: Observe Stack & Heap in Code

Create a sample program to visualize and compare stack vs heap memory.

```cpp
// main.cpp
#include <iostream>
using namespace std;

void printAddresses() {
    int localVar = 10;
    int* heapVar = new int(20);

    cout << "Address of localVar (Stack): " << &localVar << endl;
    cout << "Address of heapVar (Heap): " << heapVar << endl;

    delete heapVar;
}

int globalVar = 100;

int main() {
    static int staticVar = 50;
    printAddresses();

    cout << "Address of globalVar (Data segment): " << &globalVar << endl;
    cout << "Address of staticVar (Data segment): " << &staticVar << endl;
    return 0;
}
```

> **Try This:**
> - Observe how different variables are stored at different memory locations
> - Modify the program to create a large local array (`int arr[100000]`) and watch for stack overflow
> - Use `ulimit -s` to see your system's stack size limit

---

### ✅ Key Takeaways

- **Stack** is used for function calls and local variables. It's fast but limited in size.
- **Heap** is used for dynamically allocated memory. It’s flexible but must be manually managed.
- Understanding memory layout helps avoid bugs like memory leaks, segmentation faults, and overflows.
- Sections like `.text`, `.data`, `.bss`, heap, and stack make up your process memory.


