// // class Solution {
// // public:
// //     int findCircleNum(vector<vector<int>>& isConnected) {
// //         int n=isConnected.size();
// //         vector<int>visited(n,0);
// //         vector<vector<int>>adj(n);
// //         int prov=0;
// //         for(int i=0; i<n; i++){
// //             for(int j=0; j<n; j++){
// //                 if(i!=j && isConnected[i][j]==1){
// //                     adj[i].push_back(j);
// //                 }
// //             }
// //         }
        
// //         for(int i = 0; i < n; i++) {
// //             if(!visited[i]) {
// //                 queue<int> q;
// //                 q.push(i);
// //                 visited[i] = true;
// //                 prov++;

// //                 while(!q.empty()) {
// //                     int node = q.front(); q.pop();

// //                     for(int neigh : adj[node]) {
// //                         if(!visited[neigh]) {
// //                             visited[neigh] = true;
// //                             q.push(neigh);
// //                     }
// //                 }
// //             }
// //         }
// //     }


// //     return prov;    
// //     }
// // };

// // class Solution {
// // public:
// //     int findCircleNum(vector<vector<int>>& isConnected) {
// //         int n = isConnected.size();
// //         vector<int> visited(n, 0);
// //         int provinces = 0;

// //         for(int i = 0; i < n; i++) {
// //             if(!visited[i]) {
// //                 provinces++;
// //                 queue<int> q;
// //                 q.push(i);
// //                 visited[i] = 1;

// //                 while(!q.empty()) {
// //                     int city = q.front();
// //                     q.pop();

// //                     for(int j = 0; j < n; j++) {
// //                         if(isConnected[city][j] == 1 && !visited[j]) {
// //                             visited[j] = 1;
// //                             q.push(j);
// //                         }
// //                     }
// //                 }
// //             }
// //         }
// //         return provinces;
// //     }
// // };









// class Solution{
// public:

//     // void dfs(vector<vector<int>>&adj, vector<int>& vis, int node){
//     //     vis[node]=1;
//     //     for(auto it: adj[node]){
//     //         if(!vis[it])
//     //         dfs(adj, vis, it);
//     //     }
//     // }

//     void bfs(vector<vector<int>>&adj, vector<int>&vis, int node){
//         vis[node]=1;
//         queue<int>q;
//         q.push(node);

//         while(!q.empty()){
//             int cnode= q.front();
//             q.pop();

//             for(auto it: adj[cnode]){
//                 if(!vis[it]){
//                     vis[it]=1;
//                     q.push(it);
//                 }
//             }
//         }

//     }

//     int findCircleNum(vector<vector<int>>& isConnected){
//         int n= isConnected.size();
//         vector<int>vis(n, 0);
//         vector<vector<int>>adj(n);
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(i!=j && isConnected[i][j]==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         int provincess=0;

//         for(int i=0; i<n; i++){
//             if(vis[i]==0){
//                 provincess++;
//                 bfs(adj, vis, i);
//             }
//         }
//     return provincess;    
//     }
// };














class Solution{
public:

    void bfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node]=1;
        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int cnode= q.front();
            q.pop();

            for(auto it: adj[cnode]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected){
        int n= isConnected.size(), provincess=0;
        vector<vector<int>>adj(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(adj, vis, i);
                provincess++;
            }
        }
        
    return provincess;
    }
};
