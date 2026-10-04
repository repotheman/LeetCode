class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int> pos;
        vector <int> neg;
        vector <int> result;

        for(auto i : nums){
            if(i < 0)
                neg.push_back(i);
            else
                pos.push_back(i);
        }
        
        int j = 0;
        for(int i = 0; i<pos.size(); i++){
            result.push_back(pos[i]);
            result.push_back(neg[i]); 
        }
        return result ;
    }
};