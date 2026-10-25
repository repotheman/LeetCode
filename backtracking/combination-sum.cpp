class Solution {
public:

    vector <vector<int>> ans;
    
    void combination(vector<int>& candidates, int target, vector <int>& v, int  index){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        for(int i = index; i <candidates.size(); i++ ){
            if(candidates[i] <= target){
                v.push_back(candidates[i]);
                combination(candidates, target - candidates[i],v, i);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> v;

        combination(candidates, target,v,0);

        return ans;
    }
};