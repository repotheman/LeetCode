class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set <int> st;
        vector <int> ans;
        for(int num : nums){
            if(st.find(num) != st.end()){
                ans.push_back(num);
            }
            st.insert(num);
        }

        return ans;
    }
};