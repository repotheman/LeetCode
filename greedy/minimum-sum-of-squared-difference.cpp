class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        vector<long long> diff(n);
        long long maxDiff = 0;
        
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }
        
        // Binary search on the answer
        long long low = 0, high = maxDiff;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total_cost = 0;
            
            for (int i = 0; i < n; i++) {
                if (diff[i] > mid) {
                    total_cost += (diff[i] - mid);
                }
            }
            
            if (total_cost <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        // Apply the threshold `ans` and reduce elements
        long long remaining_k = k;
        for (int i = 0; i < n; i++) {
            if (diff[i] > ans) {
                remaining_k -= (diff[i] - ans);
                diff[i] = ans;
            }
        }
        
        // Distribute leftover budget strictly to elements equal to `ans`
        for (int i = 0; i < n && remaining_k > 0; i++) {
            if (diff[i] == ans && diff[i] > 0) {
                diff[i]--;
                remaining_k--;
            }
        }
        
        // Calculate the final sum of squares
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result += diff[i] * diff[i];
        }
        
        return result;
    }
};