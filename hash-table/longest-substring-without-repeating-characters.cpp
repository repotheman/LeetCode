#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // Size 128 covers all ASCII characters (letters, spaces, symbols)
        vector<int> freq(128, 0);

        int left = 0, maxLength = 0;
        
        for (int r = 0; r < n; r++) {
            // 1. Add the incoming character to our frequency map
            freq[s[r]]++;

            // 2. If the current character is a duplicate (count > 1),
            // shrink the window from the left until the duplicate is gone.
            while (freq[s[r]] > 1) {
                freq[s[left]]--; // Remove the character falling off the left
                left++;          // Move the left pointer forward
            }

            // 3. Update the maximum length found so far
            maxLength = max(maxLength, r - left + 1);
        }

        return maxLength;
    }
};