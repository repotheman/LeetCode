class Solution {
public:

    bool canMake(vector<int> &bloomDay, int m, int k ,int day){
        int bouquets = 0;
        int adjacent = 0;

        for(int i =0; i< bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                adjacent++;
                if(adjacent == k){
                    bouquets++;
                    adjacent = 0;
                }
            }else{
                adjacent = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = (long long) m * k;

        if(totalFlowersNeeded > bloomDay.size()){
            return -1;
        }

        int lo = 0, hi = 0;

        for(int day : bloomDay){
            hi = max(hi,day);
        }

        int ans = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(canMake(bloomDay, m, k, mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};