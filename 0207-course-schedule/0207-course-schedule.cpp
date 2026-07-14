// class Solution {
// public:

//     bool isCycle(int src, vector<bool> &vis, vector<bool>& recPath, vector<vector<int>>& edges){
//         vis[src]= true;
//         recPath[src]= true;

//         for(int i=0; i<edges.size(); i++){
//             int v= edges[i][0];
//             int u= edges[i][1];

//             if(u==src){
//                 if(!vis[v]){
//                     if(isCycle(v, vis, recPath, edges))
//                     return true;
//                 }else if(recPath[v]){
//                     return true;
//                 }
//             }
//         }

//         recPath[src]= false;
//         return false;
//     }

//     bool canFinish(int n, vector<vector<int>>& edges) {
//         vector<bool> vis(n, false);
//         vector<bool> recPath(n, false);

//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 if(isCycle(i, vis, recPath, edges)){
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

//topop sort using bfs
class Solution{
public:

    bool canFinish(int n, vector<vector<int>> &edges){
        vector<vector<int>>adj(n);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
        }
        vector<int>indegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

    if(cnt<n){
        return false;
    }    
    return true;
    }
};    