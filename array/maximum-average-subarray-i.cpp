class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int n = nums.size();
        int left = 0 ;
        double ans = INT_MIN, sum = 0;
        for(int right = 0; right< n ; right++){
            sum += nums[right];
            
            while(right - left + 1 == k){
                ans = max(ans, sum);
                sum -= nums[left];
                left++;
            }
        }
        return ans / k;
    }
};