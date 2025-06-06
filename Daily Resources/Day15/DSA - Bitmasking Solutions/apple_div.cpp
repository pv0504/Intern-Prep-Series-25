#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> weights(n);
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
        total += weights[i];
    }

    long long min_diff = LLONG_MAX;

    for (int mask = 0; mask < (1 << n); ++mask) {
        long long group_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                group_sum += weights[i];
            }
        }
        long long other_sum = total - group_sum;
        min_diff = min(min_diff, abs(group_sum - other_sum));
    }

    cout << min_diff << "\n";
    return 0;
}
