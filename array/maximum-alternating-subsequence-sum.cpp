class Solution {
    typedef long long ll;
    ll t[1000001][2];
    int n;

    ll solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n) return 0;
        if (t[idx][flag] != -1) return t[idx][flag];

        ll skip = solve(idx + 1, nums, flag);
        ll val = flag ? nums[idx] : -nums[idx];
        ll take = solve(idx + 1, nums, !flag) + val;

        return t[idx][flag] = max(skip, take);
    }

public:
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, true);
    }
};
