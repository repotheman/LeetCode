class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set <int> st;

        for(auto num : nums){
            st.insert(num);
        }

        int exist = 0;
        int i = 1;
        while(exist != 1){
            
            if( !st.count(k * i)){
                return k*i;
            }

            i++;
        }
    return -1;
    }
};