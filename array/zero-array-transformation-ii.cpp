class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> diff(n + 1, 0);
        int dec = 0, k = 0;

        for (int i = 0; i < n; ++i) {
            while (dec + diff[i] < nums[i]) {
                if (k == m) return -1;
                auto& q = queries[k++];
                int l = q[0], r = q[1], v = q[2];
                if (r < i) continue;
                diff[max(l, i)] += v;
                diff[r + 1] -= v;
            }
            dec += diff[i];
        }
        return k;
    }
};
