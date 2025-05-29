class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0, max_freq = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];
            while ((long long)(right - left + 1) * nums[right] - total > k) {
                total -= nums[left];
                left++;
            }
            max_freq = max(max_freq, right - left + 1);
        }
        
        return max_freq;
    }
};
