#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    vector<int> prefix(n + 1, 0);  // prefix[0] = 0

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (prefix[b] ^ prefix[a - 1]) << '\n';
    }

    return 0;
}
