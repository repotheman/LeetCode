class Solution {
public:
    int maxOr = 0, count = 0;

    void dfs(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr)
                count++;
            return;
        }

        // Include current number
        dfs(nums, index + 1, currentOr | nums[index]);

        // Exclude current number
        dfs(nums, index + 1, currentOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // First, calculate max possible OR
        for (int num : nums)
            maxOr |= num;

        // Start DFS
        dfs(nums, 0, 0);
        return count;
    }
};
