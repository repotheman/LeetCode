class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
 
    int maxVowels(string s, int k) {
 
        int n = s.size();
        int left = 0;
        int vowels = 0, ans = 0;
 
        for(int right = 0; right < n; right++){
 
            if(isVowel(s[right])) vowels++;
            if(right - left + 1 == k){
                ans = max(ans, vowels);
 
                if(isVowel(s[left])) vowels--;
                left++;
            }
 
        }
 
        return ans;
        
    }
};