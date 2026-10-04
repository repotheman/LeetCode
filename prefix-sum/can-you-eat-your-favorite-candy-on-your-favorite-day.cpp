class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = candiesCount[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + candiesCount[i];
        }

        vector<bool> res;
        for (auto& q : queries) {
            int type = q[0];
            int day = q[1];
            int cap = q[2];

            long long minCandies = day + 1;
            long long maxCandies = (long long)(day + 1) * cap;

            long long before = type == 0 ? 0 : prefixSum[type - 1];
            long long current = prefixSum[type];

            res.push_back(maxCandies > before && minCandies <= current);
        }

        return res;
    }
};