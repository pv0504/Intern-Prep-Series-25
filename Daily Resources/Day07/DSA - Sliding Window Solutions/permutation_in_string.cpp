class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len_s1 = s1.size(), len_s2 = s2.size();
        if (len_s1 > len_s2) return false;
        
        vector<int> s1_count(26, 0), window_count(26, 0);
        for (int i = 0; i < len_s1; ++i) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (s1_count[i] == window_count[i]) matches++;
        }
        
        for (int i = 0; i < len_s2 - len_s1; ++i) {
            if (matches == 26) return true;
            
            int left_char = s2[i] - 'a';
            int right_char = s2[i + len_s1] - 'a';
            
            // Remove left_char from window
            window_count[left_char]--;
            if (window_count[left_char] == s1_count[left_char]) {
                matches++;
            } else if (window_count[left_char] + 1 == s1_count[left_char]) {
                matches--;
            }
            
            // Add right_char to window
            window_count[right_char]++;
            if (window_count[right_char] == s1_count[right_char]) {
                matches++;
            } else if (window_count[right_char] - 1 == s1_count[right_char]) {
                matches--;
            }
        }
        
        return matches == 26;
    }
};
