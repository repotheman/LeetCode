class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0); // Array to store character frequencies (A-Z)
        
        int l = 0;
        int max_freq = 0; // Tracks the highest frequency of any single char in the window
        int best = 0;

        for (int r = 0; r < s.size(); r++) {
            // Increment the count for the current character
            count[s[r] - 'A']++;
            
            // Update the maximum frequency found in the current window
            max_freq = max(max_freq, count[s[r] - 'A']);

            // If the number of characters we need to replace exceeds k, shrink the window
            while ((r - l + 1) - max_freq > k) {
                count[s[l] - 'A']--; // Remove the left character from our counts
                l++;                 // Shrink the window
            }

            // Update the maximum length found so far
            best = max(best, r - l + 1);
        }

        return best;
    }
};