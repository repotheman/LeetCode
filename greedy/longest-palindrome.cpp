class Solution {
public:
    int longestPalindrome(std::string s) {
        // Array to store frequencies of characters (size 128 covers all standard ASCII)
        int freq[128] = {0};
        
        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        int total_length = 0;
        bool has_unpaired_char = false;
        
        for (int count : freq) {
            // Integer division in C++ automatically drops the remainder.
            // Example: If count is 5, (5 / 2) = 2 pairs. 2 * 2 = 4 characters used.
            total_length += (count / 2) * 2;
            
            // If the count is odd, it means one character is left unpaired
            if (count % 2 != 0) {
                has_unpaired_char = true;
            }
        }
        
        // If we have at least one unpaired character, we can put one in the absolute center
        if (has_unpaired_char) {
            total_length += 1;
        }
        
        return total_length;
    }
};