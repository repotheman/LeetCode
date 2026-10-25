class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        int n = s2.length();

        if(k>n) return false;

        vector<int> s1_freq(26,0);
        vector<int> window_freq(26,0);

        for(char c: s1){
            s1_freq[c-'a']++;
        }

        for(int r = 0; r<n; r++){
            window_freq[s2[r] - 'a']++;

            if(r >= k -1){
                if(window_freq == s1_freq){
                    return true;
                }

                window_freq[s2[r-k+1] - 'a']--;
            } 
        }
        return false;
    }
};