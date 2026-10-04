class Solution {
public:
    bool closeStrings(string word1, string word2) {    
        vector <int> freq1(26);
        vector <int>freq2(26);
        int m  = word1.length();
        int n = word2.length();

        if(m!=n){
            return false;
        }

        for(int i = 0; i<m;i++){
            char ch = word1[i];

            int idx = ch-'a';

            freq1[idx]++;

            char ch1 = word2[i];

            int idx1 = ch1-'a';
            freq2[idx1]++;
        }
        
        for(int i=0 ; i<26; i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            if(freq1[i] == 0 && freq2[i] == 0) continue;

            return false;
        
        }

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        return freq1 == freq2;
    }
};