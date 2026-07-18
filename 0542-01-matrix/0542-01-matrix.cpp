// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n= mat.size();
//         int m= mat[0].size();
//         vector<vector<int>>dist(n, vector<int>(m, -1));
//         queue<pair<int, int>>q;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==0){
//                     dist[i][j]=0;
//                     q.push({i, j});
//                 }
//             }
//         }

//         vector<int>dr= {1, -1, 0, 0};
//         vector<int>dc= {0, 0, 1, -1};

//         while(!q.empty()){
//             auto[row, col]= q.front();
//             q.pop();

//             for(int i=0; i<4; i++){
//                 int newr= row+dr[i];
//                 int newc= col+dc[i];

//                 if(newr>=0 && newc>=0 && newr<n && newc<m && dist[newr][newc]==-1){
//                     dist[newr][newc]= dist[row][col]+1;
//                     q.push({newr, newc});
//                 }
//             }
//         }
//         return dist;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> wallsMatrix(vector<vector<int>>& mat) {
//         int n= mat.size();
//         int m= mat[0].size();
//         queue<pair<pair<int, int>, int>>q;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==0){
//                     q.push({{i,j}, 0});
//                 }
//             }
//         }

//         vector<int>dr= {-1, 0, 1, 0};
//         vector<int>dc= {0, -1, 0, 1};
//         while(!q.empty()){
//             int row= q.front().first.first;
//             int col= q.front().first.second;
//             int dist= q.front().second;
//             q.pop();

//             for(int i=0; i<4; i++){
//                 int newr=row+dr[i];
//                 int newc=col+dc[i];

//                 if(newr>=0 && newc>=0 && newc<m && newr<n && mat[newr][newc]==1e9){
//                     mat[newr][newc]=dist+1;
//                     q.push({{newr, newc}, dist+1});
//                 }
//             }
//         }

//     }
// };










// class Solution{
// public:
//     vector<vector<int>>updateMatrix(vector<vector<int>>& mat){
//         int n= mat.size();
//         int m= mat[0].size();
//         vector<vector<int>>dist(n, vector<int>(m, -1));
//         queue<pair<int, int>>q;

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(mat[i][j]==0){
//                     q.push({i, j});
//                     dist[i][j]= 0;
//                 }
//             }
//         }
//         int dr[]= {-1, 0, 1, 0};
//         int dc[]={0, 1, 0, -1};

//         while(!q.empty()){
//             int row= q.front().first;
//             int col= q.front().second;
//             q.pop();

//             for(int i=0; i<4; i++){
//                 int nrow= row+dr[i];
//                 int ncol= col+dc[i];

//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && dist[nrow][ncol]==-1){
//                     dist[nrow][ncol]= dist[row][col]+1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     return dist;    
//     }
// };












class Solution{
public:
    vector<vector<int>>updateMatrix(vector<vector<int>>& mat){
        int n= mat.size();
        int m= mat[0].size();
        vector<vector<int>>dist(n, vector<int>(m, -1));
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0,1, 0, -1};
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr= row+dr[i];
                int nc= col+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[row][col]+1;
                    q.push({nr, nc});
                }
            }
        }
    return dist;    
    }
};