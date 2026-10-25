class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l= 0, minLength = INT_MAX;

        int current_sum = 0;
        
        for(int r = 0; r <nums.size(); r++){
            current_sum += nums[r];

            while(current_sum >= target){
                minLength = min(minLength, r-l + 1);
                current_sum -= nums[l];
                l++;
            }
        }

       return minLength != INT_MAX ? minLength : 0;
    }
};