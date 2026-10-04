class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        // Extract start times for binary search
        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i)
            startTimes[i] = events[i][0];

        // dp[i][j] = max value using first i events and attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            int next = upper_bound(startTimes.begin(), startTimes.end(), events[i][1]) - startTimes.begin();
            for (int j = 1; j <= k; ++j) {
                // Two choices: skip or attend current event
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[next][j - 1]);
            }
        }
        return dp[0][k];
    }
};
