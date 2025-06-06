#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long LIMIT = 1LL << 48;  // 2^48 = 281474976710656

    int t;
    cin >> t;

    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (x == y) {
            cout << -1 << '\n';
        } else {
            long long answer = LIMIT - max(x, y);
            cout << answer << '\n';
        }
    }

    return 0;
}
