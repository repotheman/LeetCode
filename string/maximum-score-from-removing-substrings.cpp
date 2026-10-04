class Solution {
public:
    int removePattern(string &s, char first, char second, int value) {
        stack<char> st;
        int score = 0;
        string temp;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                score += value;
            } else {
                st.push(ch);
            }
        }

        // build the remaining string
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;  // update original string

        return score;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;
        if (x > y) {
            total += removePattern(s, 'a', 'b', x); // remove "ab" first
            total += removePattern(s, 'b', 'a', y); // then "ba"
        } else {
            total += removePattern(s, 'b', 'a', y); // remove "ba" first
            total += removePattern(s, 'a', 'b', x); // then "ab"
        }
        return total;
    }
};