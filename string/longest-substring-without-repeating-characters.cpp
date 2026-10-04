class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map <char,int> freq;
        int l = 0;
        int best = 0;

        for (int r = 0; r<s.size(); r++){
            freq[s[r]]++;

            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            best = max(best, r - l + 1);;
        }
        return best;

    }
};