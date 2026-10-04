class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map <int, vector<int>> adj;
        queue <int> que;

        vector <bool> visited(numCourses, false);

        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector <int> indegree(numCourses, 0);
        

        for(int u =0; u<numCourses; u++){
            for(int &v : adj[u]){
                indegree[v]++;
            }
        }

        for(int i =0; i<numCourses; i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }


        vector<int> result;

        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();

            for(int &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        return result.size() == numCourses;
    }
};