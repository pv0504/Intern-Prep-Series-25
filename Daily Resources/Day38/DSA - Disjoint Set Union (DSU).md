# 📘 DSA Problem of the Day – DSU Special (03/07/2025)

## 🔍 Focus: Mastering Disjoint Set Union (Union-Find)

Union-Find (DSU) supports fast connectivity and component-merging operations. It underpins Kruskal’s MST, dynamic connectivity, cycle detection, and many offline graph-query techniques.

---

## 📚 Learning Resources

- [CP-Algorithms: DSU — Union by Rank & Path Compression](https://cp-algorithms.com/data_structures/disjoint_set_union.html)  
- [GeeksforGeeks: Disjoint Set Union (DSU) / Union Find](https://www.geeksforgeeks.org/disjoint-set-data-structures/)  
- 📺 [YouTube: DSU Tutorial (Union-Find)]([https://www.youtube.com/watch?v=hmA9fuzBd2U](https://www.youtube.com/watch?v=aBxjDBC4M1U&pp=ygUSZGlzam9pbnQgc2V0IHVuaW9u))  

---

## 🧩 Practice Problems

| #  | Problem                                                                                     | Difficulty     |
|----|---------------------------------------------------------------------------------------------|----------------|
| 1  | [Snowmen (CSES 1689)](https://cses.fi/problemset/task/1689)                                  | Easy           |
| 2  | [Road Construction (CSES 1709)](https://cses.fi/problemset/task/1709)                       | Easy-Medium    |
| 3  | [Friends and Parties (CSES 2103)](https://cses.fi/problemset/task/2103)                     | Easy-Medium    |
| 4  | [Components in a Graph (LeetCode 323)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) | Medium         |
| 5  | [Accounts Merge (LeetCode 721)](https://leetcode.com/problems/accounts-merge/)              | Medium-Hard    |
| 6  | [Redundant Connection (LeetCode 684)](https://leetcode.com/problems/redundant-connection/)  | Medium-Hard    |
| 7  | [Merging Communities (HackerRank)](https://www.hackerrank.com/challenges/merging-communities/problem) | Hard           |
| 8  | [Dynamic Graph Connectivity (Offline) – SPOJ DYNACON1](https://www.spoj.com/problems/DYNACON1/) | Hard           |

---

## 💡 Tips for DSU

- **Path Compression & Union by Rank**  
  Always compress paths in `find()` and merge smaller rank under larger to achieve near-constant amortized time.

- **Use Cases**  
  - Kruskal’s MST  
  - Offline connectivity queries (Mo’s algorithm on trees)  
  - Cycle detection in undirected graphs  
  - Maintaining bipartiteness with DSU + parity arrays

- **Advanced Variants**  
  - **Rollback DSU** for divide-and-conquer offline queries  
  - **Persistent DSU** stores history for time-travel queries  
  - **DSU on Tree** to answer subtree queries by merging child components

---

📢 **Note:** Solutions will be published on **04/07/2025**.  
For questions, ping me at **9873886151**.  
Happy coding! 🚀  

