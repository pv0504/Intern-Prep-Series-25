# SDE Intern Prep – Day 1

## 📌 Topic: Journey of a Program to Process

### 🧠 What’s This About?

Ever wondered what really happens after you run:

```
g++ main.cpp && ./a.out
```

Today's topic walks through what your computer actually does behind the scenes — taking your C++ source code and converting it into a real process in memory. This includes:
- Preprocessing
- Compilation
- Assembly
- Linking
- Loading
- Execution

---

### 📚 Resources

**🎥 Main Video:**  
[How C Programs Run – Source to Execution (Neso Academy)](https://www.youtube.com/watch?v=yz-zyMksGmw&pp=ygUoaG93IGEgYyBwcm9ncmFtIGlzIGNvbXBpbGVkIGFuZCBleGVjdXRlZA%3D%3D)

**📖 Read:**  
[Compilation Process in C – GeeksforGeeks](https://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/)

**🧠 Optional Deep Dive:**  
[Compilation and Execution of a C Program on Linux (LiveOverflow)](https://www.youtube.com/watch?v=QdnxjYj1pS0)

---

### 🛠️ Hands-on Task: Break Down Compilation

Take a basic C++ file (e.g. Hello World) and run the following commands one by one. You don’t need to understand every output — just observe what each step does and what files are created.

> Create your file:
```cpp
// main.cpp
#include <iostream>
int main() {
    std::cout << "Hello, DevClub!\n";
    return 0;
}
```

---

#### 🔍 Step-by-step Breakdown

```bash
g++ -E main.cpp
# Step 1: Preprocessing
# Expands #include directives and macros. Outputs plain C++ code with headers included.
```

```bash
g++ -S main.cpp
# Step 2: Compilation
# Converts the code into Assembly instructions (.s file).
```

```bash
g++ -c main.cpp
# Step 3: Assembling
# Creates an object file (main.o) with machine code but not linked.
```

```bash
nm main.o
# Optional: Inspect the object file’s symbol table.
# Shows defined/undefined functions, variables, etc.
```

```bash
g++ main.cpp
# Step 4: Linking
# Links object code with standard libraries and produces an executable (a.out by default).
```

```bash
./a.out
# Step 5: Execution
# Runs the program!
```

```bash
ps aux | grep a.out
# Optional: See your running program in the system process list.
```

### ✅ Key Takeaways

- Compilation has multiple stages: it’s not just one command.
- Each file created (e.g., `.s`, `.o`, `a.out`) represents a different stage.
- Tools like `nm`, `readelf`, `objdump`, and `ps` let you peek under the hood of system internals.
- You don't need to understand *everything* yet — just get comfortable running and observing.

---

👉 Stay tuned for **Day 2**
