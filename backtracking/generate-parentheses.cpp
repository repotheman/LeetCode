class Solution {
public:
    vector<string> valid;

    void recursion(string& s, int open, int close) {
        if (open == 0 && close == 0){
            valid.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            recursion(s, open - 1, close);
            s.pop_back();
        }

        if (close > 0) {
            if (open < close) {
                s.push_back(')');
                recursion(s, open, close - 1);
                s.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        recursion(s, n, n);
        return valid;
    }
};