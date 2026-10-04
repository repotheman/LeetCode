class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();

        // Left side: min sum of n elements from first 2n
        priority_queue<int> maxHeap;
        vector<long long> leftSum(size, 0);
        long long leftTotal = 0;
        for (int i = 0; i < 2 * n; ++i) {
            maxHeap.push(nums[i]);
            leftTotal += nums[i];
            if (maxHeap.size() > n) {
                leftTotal -= maxHeap.top();
                maxHeap.pop();
            }
            if (i >= n - 1) {
                leftSum[i] = leftTotal;
            }
        }

        // Right side: max sum of n elements from last 2n
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<long long> rightSum(size, 0);
        long long rightTotal = 0;
        for (int i = size - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            rightTotal += nums[i];
            if (minHeap.size() > n) {
                rightTotal -= minHeap.top();
                minHeap.pop();
            }
            if (i <= 2 * n) {
                rightSum[i] = rightTotal;
            }
        }

        long long result = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            result = min(result, leftSum[i] - rightSum[i + 1]);
        }

        return result;
    }
};
