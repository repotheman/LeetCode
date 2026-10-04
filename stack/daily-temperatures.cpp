class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
 
        stack<pair<int,int>>st;
        vector<int>ans;
        int n = temp.size();
 
        for(int i = n - 1; i >= 0; i--){
 
            while(!st.empty() && st.top().first <= temp[i]){
                st.pop();
            }
 
            if(!st.empty()){
                int diff = st.top().second - i;
                ans.push_back(diff);
            }else{
                ans.push_back(0);
            }
 
            st.push({temp[i], i});
        }
 
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};