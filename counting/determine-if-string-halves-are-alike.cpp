class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool halvesAreAlike(string s) {
        int n = s.length();

        int left = 0;
        int right = (n / 2);
        int count_left = 0;
        int count_right = 0;

        while (left < n / 2 && right < n) {
            
            if(isVowel(s[left])){
                count_left++;
            }
            if(isVowel(s[right])){
                count_right++;
            }

            left++;
            right++;

        }

        if(count_left == count_right){
            return true;
        }
        return false;
    }
};