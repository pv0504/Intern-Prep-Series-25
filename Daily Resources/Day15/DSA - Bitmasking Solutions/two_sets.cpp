#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long total = n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        long long target = total / 2;
        vector<int> set1, set2;

        for (int i = n; i >= 1; --i) {
            if (target >= i) {
                set1.push_back(i);
                target -= i;
            } else {
                set2.push_back(i);
            }
        }

        cout << set1.size() << "\n";
        for (int x : set1) cout << x << " ";
        cout << "\n";

        cout << set2.size() << "\n";
        for (int x : set2) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
