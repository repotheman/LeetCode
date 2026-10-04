class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums)
            mp[num]++;

        int maxFreq = 0;
        int majority = 0;

        for (auto m : mp) {
            if (m.second > maxFreq) {
                maxFreq = m.second;
                majority = m.first;
            }
        }

        return majority;
    }
};