#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const vector<long long>& arr, int k, long long maxSum) {
    long long currentSum = 0;
    int count = 1;

    for (auto val : arr) {
        if (currentSum + val > maxSum) {
            currentSum = val;
            count++;
            if (count > k) return false;
        } else {
            currentSum += val;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    long long maxVal = 0, totalSum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
        totalSum += arr[i];
    }

    long long left = maxVal, right = totalSum, result = totalSum;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (isValid(arr, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
