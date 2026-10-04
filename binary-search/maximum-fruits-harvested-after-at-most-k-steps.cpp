class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int res = 0;
        int left = 0, sum = 0;

        // Try all right-end positions of the window
        for (int right = 0; right < n; ++right) {
            sum += fruits[right][1];

            // Check if the window from fruits[left][0] to fruits[right][0] is valid
            while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                sum -= fruits[left][1];
                ++left;
            }

            res = max(res, sum);
        }

        return res;
    }

    // Helper to calculate minimum steps to collect fruits from left to right, starting at startPos
    int minSteps(int left, int right, int startPos) {
        // Two possible paths:
        // 1. go to left first, then to right
        // 2. go to right first, then to left
        // We take the min of both
        if (right <= startPos) {
            return startPos - left;
        } else if (left >= startPos) {
            return right - startPos;
        } else {
            return min(
                2 * (startPos - left) + (right - startPos),
                2 * (right - startPos) + (startPos - left)
            );
        }
    }
};
