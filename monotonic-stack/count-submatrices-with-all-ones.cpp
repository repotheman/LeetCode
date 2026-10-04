class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            // Build histogram for this row
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            // Count submatrices ending at this row
            result += countRectangles(height);
        }

        return result;
    }

private:
    int countRectangles(vector<int>& height) {
        int n = height.size();
        vector<int> sum(n, 0);
        stack<int> st;
        int res = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] >= height[i])
                st.pop();

            if (!st.empty()) {
                int prev = st.top();
                sum[i] = sum[prev] + height[i] * (i - prev);
            } else {
                sum[i] = height[i] * (i + 1);
            }

            st.push(i);
            res += sum[i];
        }
        return res;
    }
};
