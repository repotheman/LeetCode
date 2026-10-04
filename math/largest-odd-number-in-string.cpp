class Solution {
public:
    string largestOddNumber(string num) {
        // Iterate backwards from the last character
        for (int i = num.length() - 1; i >= 0; i--) {
            
            // Check if the current character is an odd number
            // (num[i] - '0') converts the character to its integer value
            if ((num[i] - '0') % 2 != 0) {
                // Return the substring from index 0 of length (i + 1)
                return num.substr(0, i + 1);
            }
        }
        
        // If no odd digit is found, return an empty string
        return "";
    }
};