#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<long long> arr(n);
    vector<long long> prefix(n + 1, 0);  // 1-based prefix sum

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] + arr[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}
