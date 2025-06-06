#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, res = 0;
    while (left < right) {
        res = max(res, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }
    return res;
}
