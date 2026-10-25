class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        
        unordered_map <int,int> freq;

        int l = 0;
        int zeros = 0;
        int best= 0;

        for (int r = 0; r <s.size(); r++){
            
            if(s[r] == 0)
                zeros++;

            while(zeros > k ){
                if(s[l] == 0)
                    zeros--;

                l++;
            }

            best = max(best, r - l + 1);
        }

        return best;

        
    }
};