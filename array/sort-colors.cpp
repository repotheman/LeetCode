class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0= 0, count1 = 0, count2 = 0;
        for(int curr:nums){
            if(curr==0) count0++;
            else if(curr==1) count1++;
            else if (curr==2) count2++;
        }int idx=0;
        while(count0!=0){nums[idx++]=0; count0--;}
        while(count1!=0){nums[idx++]=1; count1--;}
        while(count2!=0){nums[idx++]=2; count2--;}
    }
};