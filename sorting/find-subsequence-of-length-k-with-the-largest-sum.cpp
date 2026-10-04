class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(pq.top().second);
            pq.pop();
        }
        sort(indices.begin(), indices.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(nums[indices[i]]);
        }
        return result;
    }
};