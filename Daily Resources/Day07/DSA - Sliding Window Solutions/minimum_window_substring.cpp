class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> t_count, window_count;
        for (char c : t) t_count[c]++;
        
        int have = 0, need = t_count.size();
        int left = 0, min_len = INT_MAX, res_left = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window_count[c]++;
            
            if (t_count.count(c) && window_count[c] == t_count[c]) {
                have++;
            }
            
            while (have == need) {
                if ((right - left + 1) < min_len) {
                    min_len = right - left + 1;
                    res_left = left;
                }
                
                window_count[s[left]]--;
                if (t_count.count(s[left]) && window_count[s[left]] < t_count[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(res_left, min_len);
    }
};
