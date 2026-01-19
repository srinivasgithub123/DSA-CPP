class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it: times){
            int u= it[0]-1;
            int v= it[1]-1;
            int w= it[2];
            adj[u].push_back({v, w});
        }

        vector<int>dist(n, 1e9);
        int source= k-1;
        dist[source]=0;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({dist[source], source});

        while(!pq.empty()){
            int edw= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            if (edw > dist[node]) continue;
            for(auto it: adj[node]){
                int currnode= it.first;
                int currdist= it.second;

                if( currdist+edw < dist[currnode]){
                    dist[currnode]= currdist+edw;
                    pq.push({currdist+edw, currnode});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i]==1e9){
                return -1;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans= max(ans, dist[i]);
        }

        return ans;    
    
        
    }
};