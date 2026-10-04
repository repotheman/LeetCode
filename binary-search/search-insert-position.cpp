class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int m = 0 ;
        int n= nums.size()-1;

        while(m<=n){
            int mid = (m+n)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                n = mid-1;
            }
            else{
                m = mid + 1;
            }
        } 
        return m;
    }
};