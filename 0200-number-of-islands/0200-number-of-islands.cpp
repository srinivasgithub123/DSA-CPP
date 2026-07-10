// class Solution {
// public:

//     void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& grid, int n, int m){

//         if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]!='1'){
//             return;
//         }
//         vis[i][j]= true;

//         dfs(i-1,j,vis, grid, n, m);//top
//         dfs(i,j+1,vis, grid, n, m);//right
//         dfs(i+1,j,vis, grid, n, m);//bottom
//         dfs(i,j-1,vis, grid, n, m);//left

//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int islands=0;
//         int n= grid.size();
//         int m= grid[0].size();

//         vector<vector<bool>>vis(n, vector<bool>(m, false));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]=='1' && !vis[i][j]){
//                     dfs(i, j, vis, grid, n, m);
//                     islands++;
//                 }
//             }
//         }
        
//         return islands;
//     }
// };

// class Solution {
// public:

//     void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>& grid, int n, int m){
//         queue<pair<int, int>>q;
//         q.push({row,col});
//         visited[row][col]=1;
//         vector<int>dr={-1, 0, 1, 0};
//         vector<int>dc={0, -1, 0, 1};

//         while(!q.empty()){
//             int crow= q.front().first;
//             int ccol= q.front().second;
//             q.pop();

//             for(int i=0; i<4; i++){
//                 int newr= crow+dr[i];
//                 int newc= ccol+dc[i];

//                 //top
//                 if(newr>=0 && newc<m &&newr<n&&newc>=0&& grid[newr][newc]=='1' && !visited[newr][newc]){
//                     visited[newr][newc]=1;
//                     q.push({newr, newc});
//                 }

//             }
            

//         }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int isLands=0;
//         int n= grid.size();
//         int m= grid[0].size();
//         vector<vector<int>>visited(n, vector<int>(m, 0));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j]=='1' && !visited[i][j]){
//                     bfs(i, j, visited, grid, n, m);
//                     isLands++;
//                 }
//             }
//         }

//         return isLands;
//     }
// };











class Solution{
public:

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col){
        int n= grid.size();
        int m= grid[0].size();
        vis[row][col]= true;
        queue<pair<int, int>>q;
        q.push({row, col});
        vector<int>dr={-1, 0, 1, 0};
        vector<int>dc={0, -1, 0, 1};


        while(!q.empty()){
            int crow= q.front().first;
            int ccol= q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr= crow+dr[i];
                int newc= ccol+dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]=='1'){
                    vis[newr][newc]=1;
                    q.push({newr, newc});
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid){
        int isLands=0;
        int n= grid.size();
        int m= grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(grid[row][col]=='1' && !vis[row][col]){
                    bfs(grid, vis, row, col);
                    isLands++;
                }
            }
        }
    return isLands;    
   }
};