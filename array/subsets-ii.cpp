class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& nums, int index, vector<int>& v) {
        ans.push_back(v); // 1. Record every state (from Subsets)
        
        for (int i = index; i < nums.size(); i++) {
            // 2. Skip duplicates at the same level (from Combination Sum II)
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            
            v.push_back(nums[i]);
            backtrack(nums, i + 1, v); // Move forward (Subsets rule)
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end()); // 3. Sort first so duplicates are side-by-side
        backtrack(nums, 0, v);
        return ans;
    }
};