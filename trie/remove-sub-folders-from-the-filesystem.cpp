class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string>result;
        result.push_back(folder[0]);

        for(int i = 1; i < folder.size(); ++i){
            string prefix = result.back() + "/";

            if(folder[i].rfind(prefix,0) != 0){
                result.push_back(folder[i]);
            }
        }
        return result;
    }
};