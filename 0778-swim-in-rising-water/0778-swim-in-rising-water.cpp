// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         priority_queue<
//         pair<int, pair<int,int>>,
//         vector<pair<int, pair<int,int>>>,
//         greater<pair<int, pair<int,int>>>> pq;
//         int n= grid.size();
//         int m= grid[0].size();

//         vector<vector<int>>dist(n, vector<int>(m, 1e9));
//         dist[0][0]=grid[0][0];
//         pq.push({grid[0][0],{0,0}});
//         int dr[]={-1, 0, 1, 0};
//         int dc[]={0,1,0,-1};

//         while(!pq.empty()){
//             auto it= pq.top();
//             pq.pop();

//             int diff= it.first;
//             int row= it.second.first;
//             int col= it.second.second;

//             if(row==n-1 && col==m-1){
//                 return diff;
//             }

//             for(int i=0; i<4; i++){
//                 int newr= row+dr[i];
//                 int newc= col+dc[i];
//                 if(newr>=0 && newc>=0 && newr<n && newc<m){
//                     int newCost = max(dist[row][col], grid[newr][newc]);
//                     if(newCost < dist[newr][newc]){
//                         dist[newr][newc]= newCost;
//                         pq.push({newCost, {newr, newc}});
//                     }
//                 }
//             }
//         }
//     return 0;    
//     }
// };
















class Solution{
public:
    int swimInWater(vector<vector<int>>&grid){
        vector<vector<int>>dist(grid.size(), vector<int>(grid.size(), 1e9));
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dr[]={-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};
        int n= grid.size();

        while(!pq.empty()){
            int dis= pq.top().first;
            int row= pq.top().second.first;
            int col= pq.top().second.second;
            pq.pop();
            if(dis>dist[row][col])continue;

            for(int i=0; i<4; i++){
                int nr=row+dr[i];
                int nc= col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n){
                    int maxdist= max(dis, grid[nr][nc]);
                    if(maxdist<dist[nr][nc]){
                        dist[nr][nc]=maxdist;
                        pq.push({maxdist, {nr, nc}});
                    }
                }
            }
        }
    return dist[n-1][n-1];    
    }
};