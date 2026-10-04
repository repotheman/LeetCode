class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If it's greater than 0, it's not the outermost '('
                if (opened > 0) {
                    result += c;
                }
                opened++;
            } else {
                opened--;
                // If it's greater than 0 after decrementing, it's not the outermost ')'
                if (opened > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};