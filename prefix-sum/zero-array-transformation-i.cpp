class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ++diff[l];
            --diff[r + 1];
        }
        
        int decrements = 0;
        for (int i = 0; i < n; ++i) {
            decrements += diff[i];
            if (decrements < nums[i]) 
                return false;
        }
        
        return true;
    }
};
