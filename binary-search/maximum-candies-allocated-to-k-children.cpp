class Solution {
public:

    bool possible(vector <int> & candies, long long limit,long long k){
        long long n = candies.size();
        long long children = 0;
        for(int i = 0; i<n; i++){
            children += candies[i] / limit;
        }
        return children >= k ;

    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());

        long long ans = 0;

        while (low<=high){
            long long mid = low + (high-low) /2;

            if(possible(candies, mid , k)){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        } 
        return ans;   
    }
};