class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int left= 0;
        int mid = 1;
        int right = 2;

        while(right<n){
            if((arr[left]%2!=0) && (arr[mid]%2!=0) && (arr[right]%2!=0)){
                return true;
            }
            left++;
            mid++;
            right++;
        }
        return false;
    }
};