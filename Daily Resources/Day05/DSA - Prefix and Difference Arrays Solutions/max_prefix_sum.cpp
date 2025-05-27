class Solution {
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex,
                            vector<int>& rightIndex) {
        int q = leftIndex.size();
        vector<int> result(q);

        for (int i = 0; i < q; ++i) {
            int L = leftIndex[i];
            int R = rightIndex[i];
            int max_prefix = arr[L];
            int current_sum = arr[L];

            for (int j = L + 1; j <= R; ++j) {
                current_sum += arr[j];
                max_prefix = max(max_prefix, current_sum);
            }

            result[i] = max_prefix;
        }

        return result;
    }
};
