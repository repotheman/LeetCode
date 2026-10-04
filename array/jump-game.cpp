class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // The farthest index we can currently reach

        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) {
                // If we are at a point that is not reachable
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }

        return true; // If we completed the loop, we can reach the end
    }
};
