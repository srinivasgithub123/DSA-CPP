// class Solution {
// public:

//     void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
//         vis[node] = 1;

//         for (auto it : adj[node]) {
//             if (!vis[it]) {
//                 dfs(it, vis, adj);
//             }
//         }
//     }

//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

//         // Build graph
//         vector<vector<int>> adj(n);

//         for (auto it : invocations) {
//             adj[it[0]].push_back(it[1]);
//         }

//         // Find suspicious methods
//         vector<int> vis(n, 0);
//         dfs(k, vis, adj);

//         // Store non-suspicious methods
//         unordered_set<int> st;

//         for (int i = 0; i < n; i++) {
//             if (vis[i] == 0) {
//                 st.insert(i);
//             }
//         }

//         // If a non-suspicious method calls a suspicious method,
//         // we cannot remove the suspicious methods.
//         vector<int> ans(n);

//         for (int i = 0; i < n; i++) {
//             ans[i] = i;
//         }

//         for (auto node : st) {

//             for (auto x : adj[node]) {

//                 if (vis[x] == 1) {
//                     return ans;
//                 }
//             }
//         }

//         // Otherwise, return only non-suspicious methods
//         vector<int> result;

//         for (auto it : st) {
//             result.push_back(it);
//         }

//         return result;
//     }
// };











class Solution {
public:

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, vis, adj);
            }
        }
    }

    vector<int> remainingMethods(
        int n,
        int k,
        vector<vector<int>>& invocations
    ) {
        vector<vector<int>> adj(n);

        // Build graph
        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Find suspicious methods
        vector<int> vis(n, 0);
        dfs(k, vis, adj);

        // Check whether a normal method calls a suspicious method
        for (int node = 0; node < n; node++) {

            if (vis[node] == 0) {  // normal method

                for (int next : adj[node]) {

                    if (vis[next] == 1) {
                        // Cannot remove suspicious methods
                        vector<int> ans(n);

                        for (int i = 0; i < n; i++) {
                            ans[i] = i;
                        }

                        return ans;
                    }
                }
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};