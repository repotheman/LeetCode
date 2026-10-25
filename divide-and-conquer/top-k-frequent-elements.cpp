class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;

        vector<int>result;
        for(auto num : nums){
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& [num, freq] : mp) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};