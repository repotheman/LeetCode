class Solution {
public:
    bool detectCapitalUse(string word) {
 
        int lower = 0, upper = 0;
        int n = word.size();
 
        for(auto x: word){
            if(isupper(x)) upper++;
            else lower++;
        }
 
        if(upper == n) return true;
        if(lower == n) return true;
        if(upper == 1 && isupper(word[0])) return true;
 
        return false;
        
    }
};