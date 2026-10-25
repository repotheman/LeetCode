class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(int k, int target, int index, vector<int>& v) {
        // Base case: exact size 'k' and target reached zero
        if (target == 0 && v.size() == k) {
            ans.push_back(v);
            return;
        }
        
        // Pruning: stop early if we exceed target or vector size
        if (target < 0 || v.size() > k) {
            return;
        }
        
        // Numbers available are fixed from 1 to 9
        for (int i = index; i <= 9; i++) {
            v.push_back(i);              // Choose
            backtrack(k, target - i, i + 1, v); // Explore (move to i + 1 so each is used once)
            v.pop_back();                // Un-choose (Backtrack)
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        backtrack(k, n, 1, v); // Start from index 1 up to 9
        return ans;
    }
};