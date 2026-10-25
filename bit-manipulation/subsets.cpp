class Solution {
public:
    vector<vector<int>> ans;

    void creatingSet(vector<int>& nums, int i, vector<int> v) {
        ans.push_back(v); // Record every state as a valid subset

        for (int j = i; j < nums.size(); j++) {
            v.push_back(nums[j]);        // Choose
            creatingSet(nums, j + 1, v); // Explore (move to next index)
            v.pop_back();                // Un-choose (Backtrack)
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> v;
        creatingSet(nums, 0, v);

        return ans;
    }
};