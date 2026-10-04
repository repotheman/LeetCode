class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int prefixsum = 0;
        int maxlength = 0;
        mp[prefixsum] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                prefixsum += -1;
            } else {
                prefixsum += 1;
            }

            if (mp.find(prefixsum) != mp.end()) {
                maxlength = max(maxlength, i - mp[prefixsum]);
            } else {
                mp[prefixsum] = i;
            }
        }

        return maxlength;
    }
};
