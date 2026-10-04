class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
       int n = moveTime.size();
        int m = moveTime[0].size();
        int INF = INT_MAX;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INF)));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        
        dist[0][0][0] = 0;
        pq.emplace(0, 0, 0, 0);
        
        while (!pq.empty()) {
            auto [time, i, j, p] = pq.top();
            pq.pop();
            
            if (i == n-1 && j == m-1) {
                return time;
            }
            
            if (time > dist[i][j][p]) {
                continue;
            }
            
            for (auto [di, dj] : dirs) {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int move_duration = (p == 0) ? 1 : 2;
                    int start_time = max(time, moveTime[ni][nj]);
                    int arrival_time = start_time + move_duration;
                    int new_p = (p + 1) % 2;
                    
                    if (arrival_time < dist[ni][nj][new_p]) {
                        dist[ni][nj][new_p] = arrival_time;
                        pq.emplace(arrival_time, ni, nj, new_p);
                    }
                }
            }
        }
        
        return -1; 
    }
};