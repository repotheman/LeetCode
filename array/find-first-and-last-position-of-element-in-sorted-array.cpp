class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int m = 0;
        int n = nums.size() - 1;

        while ( m<=n)
        {
            if (nums[m] == target && nums[n] == target)
            {
                return {m, n};
            }
            else if (nums[m] < target && m<nums.size()-1)
            {
                m++;
            }
            else if (nums[n] > target && n>0)
            {
                n--;
            }
            else
            {
                return {-1, -1};
            }
        }
        return {-1, -1};
    }
};