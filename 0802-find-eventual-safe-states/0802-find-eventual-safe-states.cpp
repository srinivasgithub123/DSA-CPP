class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adjrev(n);

        for(int u=0; u<n; u++){
            indegree[u]= graph[u].size();
            for(int v: graph[u]){
                adjrev[v].push_back(u);
            }
        }

        queue<int> q;
        vector<int> safenodes;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(q.size()!=0){
            int node= q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }
        
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};