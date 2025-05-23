class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto can_finish = [&](int speed) {
            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + speed - 1) / speed; // ceil without using floating point
            }
            return hours <= h;
        };

        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (can_finish(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
