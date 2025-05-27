class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;

        int prefix_sum = 0;
        int result = 0;

        for (int num : nums) {
            prefix_sum += num;
            int mod = ((prefix_sum % k) + k) % k; // handle negative mods

            result += count[mod];
            count[mod]++;
        }

        return result;
    }
};
