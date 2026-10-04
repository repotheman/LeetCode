class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;  // behaves like a stack

        for (char ch : s) {
            if (!st.empty() && st.back().first == ch) {
                st.back().second++;
                if (st.back().second == k) {
                    st.pop_back();
                }
            } else {
                st.push_back({ch, 1});
            }
        }

        string result;
        for (auto &[ch, count] : st) {
            result.append(count, ch);
        }

        return result;
    }
};
