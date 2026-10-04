class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> curr, next;

        for (int num : arr) {
            next = {num};
            for (int val : curr) {
                next.insert(val | num);
            }
            curr = next;
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};