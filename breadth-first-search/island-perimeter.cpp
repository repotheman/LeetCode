class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int total_land = 0;
        int adjacent = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    total_land++;
                    // Check right neighbor
                    if (j + 1 < cols && grid[i][j+1] == 1) {
                        adjacent++;
                    }
                    // Check bottom neighbor
                    if (i + 1 < rows && grid[i+1][j] == 1) {
                        adjacent++;
                    }
                }
            }
        }
        return 4 * total_land - 2 * adjacent;
    }
};