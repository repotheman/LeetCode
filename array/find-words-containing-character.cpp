class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int l = words.size();
        vector <int> ans;
        for (int i = 0; i<l; i++){
            if(words[i].find(x) != std::string::npos){
                ans.push_back(i);
            }
        }
        return ans;
    }
};