class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph (1-based → 0-based)
        for (auto it : relations) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> finishtime(n, 0);

        // Initialize courses with no prerequisites
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                finishtime[i] = time[i];
            }
        }

        // Topo BFS + DP
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v : adj[node]) {
                indegree[v]--;

                finishtime[v] = max(
                    finishtime[v],
                    finishtime[node] + time[v]
                );

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Answer = maximum finish time
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, finishtime[i]);
        }

        return ans;
    }
};
