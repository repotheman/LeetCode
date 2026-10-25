class Solution {
public:

    vector <vector<int>> ans;
    void generate(vector<int>& candidates, vector<int> &v, int target, int index){
        if(target==0){
            ans.push_back(v);
            return ;
        }

        for(int i = index; i<candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            if(candidates[i] <= target){
                v.push_back(candidates[i]);
                generate(candidates, v, target - candidates[i], i + 1);
                v.pop_back();
            }
        }
    } 

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> v;

        sort(candidates.begin(), candidates.end());

        generate(candidates, v, target, 0);

        return ans;
    }
};