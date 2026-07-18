// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         int ans=0;

//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         queue<pair<pair<int, int>, int>>q;//((i,j), time)
//         //pushing all sources in queue
//         for(int i=0;i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j}, 0});
//                     vis[i][j]= true;
//                 }
//             }
//         }

//         //bfs
//         while(q.size()!=0){
//             int i= q.front().first.first;
//             int j= q.front().first.second;
//             int time= q.front().second;

//             q.pop();
//             ans= max(ans, time);

//             if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){//top
//                 q.push({{i-1, j}, time+1});
//                 vis[i-1][j]= true;
//             }

//             if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){//right
//                 q.push({{i, j+1}, time+1});
//                 vis[i][j+1]= true;
//             }

//             if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){//bottom
//                 q.push({{i+1, j}, time+1});
//                 vis[i+1][j]= true;
//             }

//             if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){//left
//                 q.push({{i, j-1}, time+1});
//                 vis[i][j-1]= true;
//             }

//         }

//     //check for fresh orange
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(grid[i][j]==1 && !vis[i][j]){
//                 return -1;
//             }
//         }
//     }

//     return ans;    
//     }
// };











// class Solution{
// public:
//     int orangesRotting(vector<vector<int>>& grid){
//         int n= grid.size();
//         int m= grid[0].size();
//         vector<vector<int>>vis(n, vector<int>(m, 0));
//         queue<pair<pair<int, int>, int>>q;
//         int forg=0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]==2){
//                     q.push({{i, j},0});
//                     vis[i][j]=2;
//                 }else if(grid[i][j]==1){
//                     forg++;
//                 }
//             }
//         }

//         int dr[]= {-1, 0, 1, 0};
//         int dc[]= {0, 1, 0, -1};
//         int tm= 0;

//         while(!q.empty()){
//             int row= q.front().first.first;
//             int col= q.front().first.second;
//             int t= q.front().second;
//             tm= max(tm, t);
//             q.pop();

//             for(int i=0; i<4; i++){
//                 int nrow= row+dr[i];
//                 int ncol= col+dc[i];

//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
//                     q.push({{nrow, ncol}, t+1});
//                     vis[nrow][ncol]= 2;
//                     forg--;
//                 }
//             }
//         }
//     if(forg!=0){
//         return -1;
//     }    
//     return tm;
       
        
//     }
// };














class Solution{
public:
    int orangesRotting(vector<vector<int>>&grid){
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis= grid;
        queue<pair<pair<int, int>, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};
        int time=0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            time= q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr= row+dr[i];
                int nc= col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==1){
                    vis[nr][nc]=2;
                    q.push({{nr, nc}, time+1});
                }
            }
        }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==1){
                return -1;
            }
        }
    }
    return time;
    }
};