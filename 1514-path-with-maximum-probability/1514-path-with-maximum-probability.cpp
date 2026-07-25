class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int node= edges[i][0];
            int adjnode= edges[i][1];
            adj[node].push_back({adjnode, succProb[i]});
            adj[adjnode].push_back({node, succProb[i]});
        }

        //max_heap
        priority_queue<pair<double, int>>pq;
        vector<double>dist(n, 0.0);
        dist[start]=1.0;
        pq.push({1.0, start});

        while(!pq.empty()){
            double wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            if(wt<dist[node])continue;
            for(auto it: adj[node]){
                int adjnode= it.first;
                double edgwt= it.second;
                if(wt*edgwt > dist[adjnode]){
                    dist[adjnode]= wt*edgwt;
                    pq.push({wt*edgwt, adjnode});
                }
            }
        }

    return dist[end];    
        
    }
};