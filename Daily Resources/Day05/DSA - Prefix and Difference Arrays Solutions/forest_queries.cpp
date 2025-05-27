#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<string> forest(n);
    for (int i = 0; i < n; ++i) {
        cin >> forest[i];
    }

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    // Build 2D prefix sum
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            int is_tree = (forest[y - 1][x - 1] == '*') ? 1 : 0;
            prefix[y][x] = prefix[y - 1][x] + prefix[y][x - 1] - prefix[y - 1][x - 1]+ is_tree;
        }
    }

    // Process queries
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int result = prefix[y2][x2]  - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];
        cout << result << '\n';
    }

    return 0;
}
