class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        if (n == 0) return 0;
        int m = moveTime[0].size();
        if (m == 0) return 0;

        // Define a structure to hold the time and coordinates
        struct Cell {
            int time;
            int i;
            int j;
            Cell(int t, int x, int y) : time(t), i(x), j(y) {}
            // Overload the operator to make the priority queue a min-heap
            bool operator>(const Cell& other) const {
                return time > other.time;
            }
        };

        // Priority queue to implement Dijkstra's algorithm
        priority_queue<Cell, vector<Cell>, greater<Cell>> heap;
        heap.push(Cell(0, 0, 0));

        // Distance matrix to store the minimum time to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        // Possible directions to move: up, down, left, right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!heap.empty()) {
            Cell current = heap.top();
            heap.pop();
            int time = current.time;
            int i = current.i;
            int j = current.j;

            // If we've reached the destination, return the time
            if (i == n - 1 && j == m - 1) {
                return time;
            }

            // If the current time is greater than the recorded distance, skip
            if (time > dist[i][j]) {
                continue;
            }

            // Explore all four possible directions
            for (auto& dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    // Calculate the new time to reach the adjacent cell
                    int new_time = max(time, moveTime[x][y]) + 1;
                    // If this new time is better, update the distance and push to the heap
                    if (new_time < dist[x][y]) {
                        dist[x][y] = new_time;
                        heap.push(Cell(new_time, x, y));
                    }
                }
            }
        }
        // If we exit the loop without returning, return the distance to the last cell
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};