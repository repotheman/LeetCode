class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int balance = 0;
        int right = 0;
        for(int i =0 ; i< n; i++){
            if(s[i] == '('){
                balance++;
            }else{
                if(balance == 0  && s[i] == ')'){
                    right++;
                }else{
                    balance--;
                }
            }
        }

        return balance + right;
    }
};