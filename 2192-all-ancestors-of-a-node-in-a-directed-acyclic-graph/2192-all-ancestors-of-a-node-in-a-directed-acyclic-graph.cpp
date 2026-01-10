class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        vector<set<int>>ancestors(n);
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(int child: adj[node]){
                ancestors[child].insert(node);

                for(int x: ancestors[node]){
                    ancestors[child].insert(x);
                }

                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }

        vector<vector<int>>ans(n);
        for(int i=0; i<n; i++){
            for(int x: ancestors[i]){
                ans[i].push_back(x);
            }
        }

    return ans;    
    }
};