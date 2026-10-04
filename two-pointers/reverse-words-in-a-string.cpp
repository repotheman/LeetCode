class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the whole string
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int left = 0;  // Marks the start of a word
        int right = 0; // Traverses and places characters in their correct positions
        int i = 0;     // Main iterator
        
        while (i < n) {
            // Skip leading spaces or multiple spaces between words
            while (i < n && s[i] == ' ') i++;
            
            if (i == n) break; // Reached the end
            
            // Step 2: Copy the word to the 'right' pointer position
            while (i < n && s[i] != ' ') {
                s[right] = s[i];
                right++;
                i++;
            }
            
            // Step 3: Reverse the newly placed word to fix its spelling
            reverse(s.begin() + left, s.begin() + right);
            
            // Add a single space after the word
            s[right] = ' ';
            right++;
            
            // Update left for the next word
            left = right; 
        }
        
        // Resize the string to cut off the remaining junk characters and trailing space
        // We do (right - 1) to remove the final extra space added in the loop
        s.resize(max(0, right - 1));
        
        return s;
    }
};