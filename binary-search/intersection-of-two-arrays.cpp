class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> st;

        for(int num: nums1){
            st.insert(num);
        }
        vector <int> result;

        for(int i = 0; i < nums2.size(); i++){
            if(st.contains(nums2[i])){
                result.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }

        return result;
    }
};