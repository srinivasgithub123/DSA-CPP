// class Solution {
// public:
//     vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
//         vector<vector<int>>adj(n);
//         vector<int>indegree(n, 0);

//         for(auto it: prerequisites){
//             int v= it[0];
//             int u= it[1];
//             adj[u].push_back(v);
//             indegree[v]++;
//         }

//         queue<int>q;
//         vector<int>ans;
//         for(int i=0; i<n; i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
        
//         while(!q.empty()){
//             int node= q.front();
//             q.pop();
//             ans.push_back(node);
//             for(int v: adj[node]){
//                 indegree[v]--;
//                 if(indegree[v]==0){
//                     q.push(v);
//                 }
//             }
//         }
//         if(ans.size()<n){
//             return {};
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(int i=0; i<prerequisites.size(); i++){
            int u= prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[v].push_back(u);
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

        vector<int>ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

    if(ans.size()==n){
        return ans;
    }    
    return {};
    }
};



