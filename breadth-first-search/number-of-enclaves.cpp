class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Base case: out of bounds or already water
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
            return;

        // 2. Sink the land so we don't visit it infinitely
        grid[r][c] = 0;

        // 3. Explore 4 directions
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Check left and right columns
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 1)
                dfs(grid, r, 0); 
            if (grid[r][cols - 1] == 1)
                dfs(grid, r, cols - 1); 
        }

        // Step 2: Check top and bottom rows
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 1)
                dfs(grid, 0, c); 
            if (grid[rows - 1][c] == 1)
                dfs(grid, rows - 1, c); 
        }

        // Step 3: Iterate over the whole grid to count the remaining trapped 1s
        int enclaveCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
    }
};