class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (rowIndex == 0)
            return ans[0];

        ans.push_back({1, 1});
        if (rowIndex == 1)
            return ans[1];

        for (int i = 2; i <= rowIndex; i++) {
            vector<int> temp = {1};
            for (int j = 1; j < i; j++) {
                int term = ans[i - 1][j - 1] + ans[i - 1][j];
                temp.push_back(term);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans[rowIndex];
    }
};