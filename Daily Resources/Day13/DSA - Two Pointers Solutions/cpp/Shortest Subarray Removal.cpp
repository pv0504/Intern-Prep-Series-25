#include <bits/stdc++.h>
using namespace std;
int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size(), left = 0, right = n - 1;
    while (left + 1 < n && arr[left] <= arr[left + 1]) ++left;
    if (left == n - 1) return 0;
    while (right > left && arr[right - 1] <= arr[right]) --right;
    int res = min(n - left - 1, right);
    for (int i = 0, j = right; i <= left && j < n; ++i) {
        while (j < n && arr[j] < arr[i]) ++j;
        res = min(res, j - i - 1);
    }
    return res;
}
