class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
 
        vector<int>stops(1001, 0);
 
        for(auto x: trips){
            int passengers = x[0];
            int left = x[1];
            int right = x[2];
 
            stops[left] += passengers;
            stops[right] -= passengers;
        }
 
        for(int i = 1; i < stops.size(); i++){
            stops[i] += stops[i - 1];
        }
 
        for(auto x: stops) if(x > capacity) return false;
 
        return true;
        
    }
};