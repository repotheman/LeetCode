class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> conflicts(n + 1);  // conflicts[right] = list of lefts
        vector<long long> gains(n + 1, 0);     // gains[i] = gain if we remove conflict starting from i

        for (auto& pair : conflictingPairs) {
            int a = pair[0], b = pair[1];
            int left = min(a, b);
            int right = max(a, b);
            conflicts[right].push_back(left);
        }

        int maxLeft = 0, secondMaxLeft = 0;
        long long validSubarrays = 0;

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }
            validSubarrays += (right - maxLeft);
            gains[maxLeft] += (long long)(maxLeft - secondMaxLeft);
        }

        long long maxGain = *max_element(gains.begin(), gains.end());
        return validSubarrays + maxGain;
    }
};
