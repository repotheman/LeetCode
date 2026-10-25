class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0;
        int count = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '(') {
                count++;
                i++;
            } else {
                // Ensure we have a pair of closing parentheses
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    result++; // Insert the missing ')'
                    i++;
                }

                // Match the closing pair with an opening '('
                if (count > 0) {
                    count--;
                } else {
                    result++; // Insert a missing '('
                }
            }
        }

        // Each unmatched '(' requires two closing parentheses
        return result + count * 2;
    }
};