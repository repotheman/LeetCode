class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto x:nums){
            mp[x]++;
        }
        for(int i = 0; i<=n;i++){
            if(!mp.count(i)) return i;
        }
        return -1;
    }
};