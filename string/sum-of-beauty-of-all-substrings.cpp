class Solution {
public:
    int beautySum(std::string s) {
        int total_beauty = 0;
        int n = s.length();
        
        // i is the start index of the substring
        for (int i = 0; i < n; i++) {
            // This array acts as our hash map for the 26 lowercase letters
            int freq[26] = {0}; 
            
            // j is the end index of the substring
            for (int j = i; j < n; j++) {
                // Increment the frequency of the current character
                freq[s[j] - 'a']++;
                
                int max_f = 0;
                int min_f = n; // The maximum possible frequency is the string length
                
                // Find the most and least frequent characters in the current substring
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        max_f = std::max(max_f, freq[k]);
                        min_f = std::min(min_f, freq[k]);
                    }
                }
                
                // Add the beauty of the current substring s[i...j]
                total_beauty += (max_f - min_f);
            }
        }
        
        return total_beauty;
    }
};