#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int ans = 0;

    for (int i = 0; i < n; ) {
        if (s[i] != t[i]) {
            if (i + 1 < n && s[i + 1] != t[i + 1] && s[i] != s[i + 1]) {
                ans++;
                i += 2;
            } else {
                ans++;
                i++;
            }
        } else {
            i++;
        }
    }

    cout << ans << '\n';
    return 0;
}
