class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map <char, int> counts;

        for(char c :s ){
            counts[c]++;
        }

        vector<pair<char, int>> freq_vec(counts.begin(), counts.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        string result = "";

        for(const auto & p : freq_vec) {
            result.append(p.second, p.first);
        }

        return result;

    }
};