class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<int>& vis,
             int node, int &size, int &nodes) {

        vis[node] = 1;
        nodes++;
        size += adj[node].size();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, vis, it, size, nodes);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {

                int size = 0;
                int nodes = 0;

                dfs(adj, vis, i, size, nodes);

                int edgeCount = size / 2;

                if (edgeCount == nodes * (nodes - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};