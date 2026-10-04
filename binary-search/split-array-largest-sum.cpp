class Solution {
public:
    bool possible(vector<int>& nums, int limit, int k) {

        int subarray = 0;
        int currsum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (currsum + nums[i] > limit) {
                currsum = 0;
                subarray++;
            }

            currsum += nums[i];
        }

        return subarray + 1 <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, mid, k)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }

        }
        return ans;
    }
};