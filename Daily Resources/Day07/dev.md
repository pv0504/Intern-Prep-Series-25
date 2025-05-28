# DevClub Intern Prep – Day 7

## 📌 Topic: Memory Alignment + Padding

### 🧠 What’s This About?

In C/C++, memory alignment and padding impact how structures are laid out in memory, affecting performance and size. Most compilers automatically add *padding bytes* to align data according to hardware constraints.

Today’s topic will help you understand:
- Why alignment is necessary
- What padding is and how it affects memory layout
- How to control padding using `#pragma pack` or `__attribute__((packed))`
- When misalignment can lead to performance issues or segmentation faults

---

### 📚 Resources

**🎥 Main Video:**  
[Memory Alignment and Padding in C/C++ (CodeVault)](https://youtu.be/hpPmH_-vYWo?si=1HlS5OSE4jhQxiaZ)

**📖 Read:**  
[Structure Padding and Packing in C – GeeksforGeeks](https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/)

**🧠 Optional Deep Dive:**  
[Linux Memory Alignment – LWN.net (Advanced)](https://lwn.net/Articles/250967/)  
Discusses low-level alignment, effects on cache/memory access, compiler behavior, and performance implications. Great for systems/interview prep.

---

### 🛠️ Hands-on Task: Observe Structure Padding

Create a C++ program to explore how padding affects struct sizes.

```cpp
#include <iostream>
using namespace std;

struct A {
    char a;
    int b;
    char c;
};

#pragma pack(1)
struct B {
    char a;
    int b;
    char c;
};
#pragma pack()

int main() {
    cout << "Size of struct A (default padding): " << sizeof(A) << endl;
    cout << "Size of struct B (packed): " << sizeof(B) << endl;
    return 0;
}
```

> Try:
> - Changing the order of members in `struct A` and observe size differences
> - Add a `double` to see how it aligns on 8-byte boundaries
> - Use `alignof()` or `std::align` (C++17) to explore alignment directly

---

### ✅ Key Takeaways

- Most systems align data for efficient access: e.g., `int` aligns to 4 bytes
- **Padding** fills unused bytes to meet alignment rules, increasing memory usage
- `#pragma pack` and GCC attributes can control padding (but use with care)
- Misalignment may cause performance penalties or runtime errors on strict CPUs

---

👉 Stay tuned for **Day 8: Branch Prediction + Pipelining**
