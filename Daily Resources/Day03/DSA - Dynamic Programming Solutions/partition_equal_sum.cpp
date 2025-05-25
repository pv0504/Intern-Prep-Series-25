#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;
        for (int x : nums) {
            for (int t = target; t >= x; --t) {
                dp[t] = dp[t] || dp[t - x];
            }
        }
        return dp[target];
    }
};
