class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int max_len = 0;
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindrome (center is s[i])
            int len1 = expandAroundCenter(s, i, i);
            
            // Check for even length palindrome (center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length found at this center
            int len = std::max(len1, len2);
            
            // If we found a longer palindrome, update the starting index and max length
            if (len > max_len) {
                // Math to find the start index based on center 'i' and length 'len'
                start = i - (len - 1) / 2;
                max_len = len;
            }
        }
        
        return s.substr(start, max_len);
    }
    
private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        // Expand outwards as long as we are in bounds and characters match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the actual length of the palindrome
        // The while loop breaks when left and right are 1 step PAST the valid palindrome bounds,
        // so the length is (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
};