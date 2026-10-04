class Solution {
public:
    int maxArea(vector<int>& nums) {
 
        int n = nums.size();
        int i = 0, j = n - 1;
        int ans = 0;
 
        while(i < j){
            int length = j - i;
            int height = min(nums[i], nums[j]);
 
            int area = length * height;
 
            ans = max(ans, area);
 
            if(nums[i] < nums[j]) i++;
            else j--;
        }
        return ans;
        
    }
};