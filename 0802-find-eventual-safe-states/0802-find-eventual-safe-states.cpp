// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n= graph.size();
//         vector<int> outdegree(n, 0);
//         vector<vector<int>> adjrev(n);

//         for(int u=0; u<n; u++){
//             outdegree[u]= graph[u].size();
//             for(int v: graph[u]){
//                 adjrev[v].push_back(u);
//             }
//         }

//         queue<int> q;
//         vector<int> safenodes;
//         for(int i=0; i<n; i++){
//             if(outdegree[i]==0){
//                 q.push(i);
//             }
//         }

//         while(q.size()!=0){
//             int node= q.front();
//             q.pop();
//             safenodes.push_back(node);

//             for(auto it: adjrev[node]){
//                 outdegree[it]--;
//                 if(outdegree[it]==0){
//                     q.push(it);
//                 }
//             }

//         }
        
//         sort(safenodes.begin(), safenodes.end());
//         return safenodes;
//     }
// };












class Solution{
public:

    bool dfs(int node, vector<int>& vis, vector<int>& path, vector<int>& check, vector<vector<int>>& graph){
        vis[node]=1;
        path[node]=1;
        
        for(int adjNode: graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, path, check, graph)==true){
                    check[node]=0;
                    return true;
                }
            }else if(path[adjNode]){
                check[node]=0;
                return true;
            }
        }

        check[node]=1;
        path[node]=0;
        return false;

    }

    vector<int>eventualSafeNodes(vector<vector<int>>& graph){
        int n= graph.size();
        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        vector<int>check(n, 0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, path, check, graph);
            }
        }

        vector<int>safeNodes;
        for(int i=0; i<n; i++){
            if(check[i]==1){
                safeNodes.push_back(i);
            }
        }

    return safeNodes;    
    }
};