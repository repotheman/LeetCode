class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> lastSeen(32, -1); // Last seen index for each bit

        for (int i = n - 1; i >= 0; --i) {
            // Update last seen index for bits set in nums[i]
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    lastSeen[b] = i;
                }
            }

            // Find the farthest bit needed to maintain max OR
            int farthest = i;
            for (int b = 0; b < 32; ++b) {
                if (lastSeen[b] != -1) {
                    farthest = max(farthest, lastSeen[b]);
                }
            }

            ans[i] = farthest - i + 1;
        }

        return ans;
    }
};