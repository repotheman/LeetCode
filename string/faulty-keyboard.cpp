class Solution {
public:
    string finalString(string s) {
        string ans;
        for(auto x:s){
            if(x == 'i'){
                reverse(ans.begin(), ans.end());
                continue;
            }else{
                ans.push_back(x);   
            }
        }
        return ans;
    }
};