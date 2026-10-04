class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int, int> mp;
        for(int i=0; i<arr.size(); i++){
            int curr = arr[i];
            mp[curr]++;
        }
        set<int> s;
        for(auto pair:mp){
            s.insert(pair.second);
        }
        return (s.size()  == mp.size())?true:false;
    }
};