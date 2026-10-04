class Solution {
public:
    bool possible(vector<int>&piles, int speed, int h){
        long long time = 0;
 
        for(int i = 0; i < piles.size(); i++){
 
            if(piles[i] < speed) time += 1;
            else{
 
                time += piles[i] / speed;
 
                if(piles[i] % speed) time += 1;
            }
            
        }
 
        
            return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
 
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
 
        while(low <= high){
 
            int mid = low + (high - low) / 2;
 
            if(possible(piles, mid, h)){
 
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
 
        return ans;
 
 
        
    }
};
