class Solution {
public:
    string makeGood(string s) {
        string result = "";

        for (char c : s) {
            if (!result.empty() &&
                (result.back() + 32 == c || result.back() - 32 == c)) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};