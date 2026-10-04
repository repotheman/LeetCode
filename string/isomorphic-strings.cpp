class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If lengths differ, they can't be isomorphic
        if (s.length() != t.length()) return false;
        
        // Arrays to store the last seen index of each ASCII character
        // Initialized to 0
        vector<int> map_s(256, 0);
        vector<int> map_t(256, 0);
        
        for (int i = 0; i < s.length(); i++) {
            
            // If the last seen positions don't match, the mapping is broken
            if (map_s[s[i]] != map_t[t[i]]) {
                return false;
            }
            
            // Record the current position + 1 
            // (+1 avoids conflicts with the default 0 value)
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        
        return true;
    }
};