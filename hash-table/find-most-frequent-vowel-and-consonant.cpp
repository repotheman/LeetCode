class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxVowel = 0, maxConsonant = 0;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char c = 'a' + i;
            if (vowels.count(c)) {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }
        
        return maxVowel + maxConsonant;
    }
};