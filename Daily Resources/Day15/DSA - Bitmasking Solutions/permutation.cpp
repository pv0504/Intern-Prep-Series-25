#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// Loop macro for convenience
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        // Set to keep track of unused numbers
        set<int> unused;
        FOR(i, 1, n) unused.insert(i);

        vi a(n + 1, 0);  // 1-based indexing for output array

        // Find the largest power of two <= n
        int po2 = 1;
        while (po2 * 2 <= n) po2 *= 2;

        if (n & 1) {
            // If n is odd
            cout << n << "\n";

            // lowest set bit of n (largest power of two dividing n)
            int low = n & (-n);

            // Assign fixed values at the end positions
            a[n - 3] = low;

            // If low == 1, add 2, else add 1 to low
            a[n - 2] = low + (low == 1 ? 2 : 1);

            a[n - 1] = n - low;
            a[n] = n;

        } else {
            // If n is even
            cout << po2 * 2 - 1 << "\n";

            if (n == po2) {
                // n is a power of two
                a[n - 4] = 1;
                a[n - 3] = 3;
                a[n - 2] = n - 2;
                a[n - 1] = n - 1;
                a[n] = n;
            } else {
                // n is even but not a power of two
                a[n - 2] = n;
                a[n - 1] = n - 1;
                a[n] = po2 - 1;
            }
        }

        // Remove assigned values from unused set
        FOR(i, 1, n + 1) {
            if (a[i] != 0) {
                unused.erase(a[i]);
            }
        }

        // Fill the remaining positions with the smallest unused numbers
        FOR(i, 1, n + 1) {
            if (a[i] == 0) {
                a[i] = *unused.begin();
                unused.erase(unused.begin());
            }
        }

        // Print the permutation
        FOR(i, 1, n + 1) cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
